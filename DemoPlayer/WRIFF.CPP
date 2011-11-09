//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <windows.h>
#include <mmsystem.h>
#include "avifmt.h"

#include "wriff.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////

riffFile *riffCreate( LPCTSTR filename )
{
	riffFile	*result;


	if ( (result = (riffFile*)malloc( sizeof(riffFile) )) == NULL )
	{
		//fprintf( stderr, "Error - riffCreate() - can't allocate memory for riffFile\n" );
		return NULL;
	}

	if ( (result->f = fopen( filename, "wb" )) == NULL )
	{
		//fprintf( stderr, "Error - riffCreate() - can't create <%s>\n", filename );
		free( result );
		return NULL;
	}

	result->stackTop = -1;

	return result;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffClose( riffFile *f )
{
	while( f->stackTop > -1 )
	{
		riffCloseSection( f );
	}

	if ( fclose( f->f ) != 0 )
	{
	//	fprintf( stderr, "Error - riffClose() - can't close RIFF file\n" );
		return false;
	}

	//free( f );

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffPadWord( riffFile *f )
{
	char	dummy = 0;


	if ( ftell( f->f ) % 2 == 1 )
	{
		fwrite( &dummy, 1, 1, f->f );
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#define MAX_GRAN 2048

bool riffPadJunk(	riffFile	*f,
					long		granularity,
					long		from )
{
	long	currentSize;


	if ( granularity > MAX_GRAN )
	{
		//fprintf( stderr, "Error - riffPadJunk() - granularity greater than %d\n", MAX_GRAN );
		return false;
	}

	if ( f->stack[ f->stackTop ].type != RIFF_SECTION_LIST )
	{
		//fprintf( stderr, "Error - riffPadJunk() - current section type is not LIST\n" );
		return false;
	}
	
	currentSize = ( riffSize( f ) - from ) % granularity;
	if ( currentSize != 0 )
	{
		char	buf[MAX_GRAN];

		currentSize = ( currentSize + 8 ) % granularity;
		memset( buf, 0, granularity );

		riffAddChunk( f, "JUNK" );
		riffWriteData( f, buf, granularity-currentSize );
		riffCloseChunk( f );
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffAddList(	riffFile	*f,
					str4		type,				// "LIST" or "RIFF"
					str4		name )
{
	if ( f->stackTop == MAX_RIFF_NESTING_LEVEL )
	{
		//fprintf( stderr, "Error - riffAddList() - maximum nesting level reached\n" );
		return false;
	}

	if ( f->stackTop > -1 )
	{
		if ( f->stack[ f->stackTop ].type != RIFF_SECTION_LIST )
		{
			//fprintf( stderr, "Error - riffAddList() - current section type is not LIST\n" );
			return false;
		}
	}

	(f->stackTop)++;

	f->stack[ f->stackTop ].type		= RIFF_SECTION_LIST;
	f->stack[ f->stackTop ].sizeOffset	= ftell( f->f ) + 4;
	f->stack[ f->stackTop ].currentSize	= 0;

	fwrite( type, 1, 4, f->f );			// "LIST" or "RIFF"
	fwrite( "xxxx", 1, 4, f->f );		// reserve room for size
	fwrite( name, 1, 4, f->f );

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffAddChunk(	riffFile	*f,
					str4		name )
{
	if ( f->stackTop == MAX_RIFF_NESTING_LEVEL )
	{
		//fprintf( stderr, "Error - riffAddChunk() - maximum nesting level reached\n" );
		return false;
	}

	if ( f->stack[ f->stackTop ].type != RIFF_SECTION_LIST )
	{
		//fprintf( stderr, "Error - riffAddChunk() - current section type is not LIST\n" );
		return false;
	}

	(f->stackTop)++;

	f->stack[ f->stackTop ].type		= RIFF_SECTION_CHUNK;
	f->stack[ f->stackTop ].sizeOffset	= ftell( f->f ) + 4;
	f->stack[ f->stackTop ].currentSize	= 0;

	fwrite( name, 1, 4, f->f );
	fwrite( "xxxx", 1, 4, f->f );		// reserve room for size

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffWriteData(	riffFile	*f,
					void		*buf,
					long		size )
{
	if ( (long)fwrite( buf, 1, size, f->f ) != size )
	{
		//fprintf( stderr, "Error - riffWriteData() - fwrite() didn't return expected result\n" );
		return false;
	}

	f->stack[ f->stackTop ].currentSize += size;

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

long riffSize( riffFile *f )
{
	return ftell( f->f );
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffCloseSection( riffFile *f )
{
	long	sizeToAdd;


	if ( f->stackTop == -1 )
	{
		//fprintf( stderr, "Error - riffCloseSection() - stack underflow\n" );
		return false;
	}

	if ( f->stack[ f->stackTop ].type == RIFF_SECTION_LIST )
	{
		f->stack[ f->stackTop ].currentSize += 4;
	}

	fseek( f->f, f->stack[ f->stackTop ].sizeOffset, SEEK_SET );
	fwrite( &(f->stack[ f->stackTop ].currentSize), 1, 4, f->f );
	fseek( f->f, 0, SEEK_END );

	switch ( f->stack[ f->stackTop ].type )
	{
	case RIFF_SECTION_LIST:
		sizeToAdd = 12;
		break;

	case RIFF_SECTION_CHUNK:
		sizeToAdd = 8;
		break;

	default:
		//fprintf( stderr, "Error - riffCloseSection() - unexpected section type\n" );
		sizeToAdd = 0;
	}

	if ( f->stack[ f->stackTop ].type == RIFF_SECTION_LIST )
	{
		f->stack[ f->stackTop ].currentSize -= 4;
	}

	if ( f->stackTop > 0 )
	{
		f->stack[ f->stackTop - 1 ].currentSize += ( f->stack[ f->stackTop ].currentSize + sizeToAdd );
	}

	(f->stackTop)--;

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffCloseChunk( riffFile *f )
{
	return riffCloseSection( f );
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool riffCloseList( riffFile *f )
{
	return riffCloseSection( f );
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/**/

