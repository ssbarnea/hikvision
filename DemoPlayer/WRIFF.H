#ifndef _WRIFF_H_
#define _WRIFF_H_

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// RIFF.H -- Interface for wrinting RIFF files
//
// By Nitzan Shaked
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
//#include "avifmt.h"
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//
// Chunk types a riff file can contain
//
typedef enum riffSectionType
{
	RIFF_SECTION_LIST	= 0,					// "LIST" (size) "TYPE" (data)
	RIFF_SECTION_CHUNK	= 1						// "name" (size) (data)
};

//
// Structure used to hold information about a chunk
//
typedef struct _riffSection
{
	riffSectionType	type;				// LIST or CHUNK
	long			sizeOffset;			// Offset in file where size is to be written
	long			currentSize;		// Current size (including subchunks, if any)
} riffSection;

//
// Maximum nesting level for riff files
//
#define MAX_RIFF_NESTING_LEVEL 20

//
// Stack used to hold current structure of riff file
//
typedef riffSection riffStack[MAX_RIFF_NESTING_LEVEL];

//
// Information about one riff file
//
typedef struct _riffFile
{
	FILE		*f;						// The file handler
	riffStack	stack;
	long		stackTop;				// Stack top (-1 if empty)
} riffFile;

//
// Names and types of lists and chunks
//
typedef char *str4;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//
// Create a new riff file and return a pointer to a "riffFile"
//
// Return NULL if failure
//
riffFile *riffCreate( LPCTSTR filename );

//
// Close a riff file
//
bool riffClose( riffFile *f );

//
// Pads the file to WORD boundry (adds a 0 byte if necessary)
//
bool riffPadWord( riffFile *f );

//
// Pads the file to a given granularity from a given position
//
bool riffPadJunk(	riffFile	*f,
					long		granularity,
					long		from );

//
// Adds a LIST to a riff file
//
bool riffAddList(	riffFile	*f,
					str4		type,				// "LIST" or "RIFF"
					str4		name );

//
// Adds a CHUNK to a riff file
//
bool riffAddChunk(	riffFile	*f,
					str4		name );

//
// Writes data to the riff file
//
bool riffWriteData(	riffFile	*f,
					void		*buf,
					long		size );

//
// Returns the current position (size) of the riff file
//
long riffSize( riffFile *f );

//
// Closes last section in the riff file
//
bool riffCloseSection( riffFile *f );
bool riffCloseChunk( riffFile *f );
bool riffCloseList( riffFile *f );

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#endif _WRIFF_H_
