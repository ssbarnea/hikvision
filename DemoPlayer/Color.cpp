/****************************************************************************\
Datei  : Color.cpp
Projekt: Farbverwaltung
Inhalt : CColor Implementierung
Datum  : 10.01.1999
Autor  : Christian Rodemeyer
Hinweis: © 1999 by Christian Rodemeyer
         Info über HLS Konvertierungsfunktion
         - Foley and Van Dam: "Fundamentals of Interactive Computer Graphics"  
         - MSDN: 'HLS Color Spaces'
         - MSDN: 'Converting Colors Between RGB and HLS' 

Modified:  8 Sep 2004  Hans Dietrich
           - fixed SetRgb() parameter order
		   - moved ToRGB() and ToHLS() to public section

\****************************************************************************/

#include "StdAfx.h"
#include "Color.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/****************************************************************************\
 CColor: Implementierung
\****************************************************************************/
const CColor::DNamedColor CColor::m_namedColor[CColor::numNamedColors] =
{
  {aliceblue            , "aliceblue"},
  {antiquewhite         , "antiquewhite"},
  {aqua                 , "aqua"},
  {aquamarine           , "aquamarine"},
  {azure                , "azure"},
  {beige                , "beige"},
  {bisque               , "bisque"},
  {black                , "black"},
  {blanchedalmond       , "blanchedalmond"},
  {blue                 , "blue"},
  {blueviolet           , "blueviolet"},
  {brown                , "brown"},
  {burlywood            , "burlywood"},
  {cadetblue            , "cadetblue"},
  {chartreuse           , "chartreuse"},
  {chocolate            , "chocolate"},
  {coral                , "coral"},
  {cornflower           , "cornflower"},
  {cornsilk             , "cornsilk"},
  {crimson              , "crimson"},
  {cyan                 , "cyan"},
  {darkblue             , "darkblue"},
  {darkcyan             , "darkcyan"},
  {darkgoldenrod        , "darkgoldenrod"},
  {darkgray             , "darkgray"},
  {darkgreen            , "darkgreen"},
  {darkkhaki            , "darkkhaki"},
  {darkmagenta          , "darkmagenta"},
  {darkolivegreen       , "darkolivegreen"},
  {darkorange           , "darkorange"},
  {darkorchid           , "darkorchid"},
  {darkred              , "darkred"},
  {darksalmon           , "darksalmon"},
  {darkseagreen         , "darkseagreen"},
  {darkslateblue        , "darkslateblue"},
  {darkslategray        , "darkslategray"},
  {darkturquoise        , "darkturquoise"},
  {darkviolet           , "darkviolet"},
  {deeppink             , "deeppink"},
  {deepskyblue          , "deepskyblue"},
  {dimgray              , "dimgray"},
  {dodgerblue           , "dodgerblue"},
  {firebrick            , "firebrick"},
  {floralwhite          , "floralwhite"},
  {forestgreen          , "forestgreen"},
  {fuchsia              , "fuchsia"},
  {gainsboro            , "gainsboro"},
  {ghostwhite           , "ghostwhite"},
  {gold                 , "gold"},
  {goldenrod            , "goldenrod"},
  {gray                 , "gray"},
  {green                , "green"},
  {greenyellow          , "greenyellow"},
  {honeydew             , "honeydew"},
  {hotpink              , "hotpink"},
  {indianred            , "indianred"},
  {indigo               , "indigo"},
  {ivory                , "ivory"},
  {khaki                , "khaki"},
  {lavender             , "lavender"},
  {lavenderblush        , "lavenderblush"},
  {lawngreen            , "lawngreen"},
  {lemonchiffon         , "lemonchiffon"},
  {lightblue            , "lightblue"},
  {lightcoral           , "lightcoral"},
  {lightcyan            , "lightcyan"},
  {lightgoldenrodyellow , "lightgoldenrodyellow"},
  {lightgreen           , "lightgreen"},
  {lightgrey            , "lightgrey"},
  {lightpink            , "lightpink"},
  {lightsalmon          , "lightsalmon"},
  {lightseagreen        , "lightseagreen"},
  {lightskyblue         , "lightskyblue"},
  {lightslategray       , "lightslategray"},
  {lightsteelblue       , "lightsteelblue"},
  {lightyellow          , "lightyellow"},
  {lime                 , "lime"},
  {limegreen            , "limegreen"},
  {linen                , "linen"},
  {magenta              , "magenta"},
  {maroon               , "maroon"},
  {mediumaquamarine     , "mediumaquamarine"},
  {mediumblue           , "mediumblue"},
  {mediumorchid         , "mediumorchid"},
  {mediumpurple         , "mediumpurple"},
  {mediumseagreen       , "mediumseagreen"},
  {mediumslateblue      , "mediumslateblue"},
  {mediumspringgreen    , "mediumspringgreen"},
  {mediumturquoise      , "mediumturquoise"},
  {mediumvioletred      , "mediumvioletred"},
  {midnightblue         , "midnightblue"},
  {mintcream            , "mintcream"},
  {mistyrose            , "mistyrose"},
  {moccasin             , "moccasin"},
  {navajowhite          , "navajowhite"},
  {navy                 , "navy"},
  {oldlace              , "oldlace"},
  {olive                , "olive"},
  {olivedrab            , "olivedrab"},
  {orange               , "orange"},
  {orangered            , "orangered"},
  {orchid               , "orchid"},
  {palegoldenrod        , "palegoldenrod"},
  {palegreen            , "palegreen"},
  {paleturquoise        , "paleturquoise"},
  {palevioletred        , "palevioletred"},
  {papayawhip           , "papayawhip"},
  {peachpuff            , "peachpuff"},
  {peru                 , "peru"},
  {pink                 , "pink"},
  {plum                 , "plum"},
  {powderblue           , "powderblue"},
  {purple               , "purple"},
  {red                  , "red"},
  {rosybrown            , "rosybrown"},
  {royalblue            , "royalblue"},
  {saddlebrown          , "saddlebrown"},
  {salmon               , "salmon"},
  {sandybrown           , "sandybrown"},
  {seagreen             , "seagreen"},
  {seashell             , "seashell"},
  {sienna               , "sienna"},
  {silver               , "silver"},
  {skyblue              , "skyblue"},
  {slateblue            , "slateblue"},
  {slategray            , "slategray"},
  {snow                 , "snow"},
  {springgreen          , "springgreen"},
  {steelblue            , "steelblue"},
  {tan                  , "tan"},
  {teal                 , "teal"},
  {thistle              , "thistle"},
  {tomato               , "tomato"},
  {turquoise            , "turquoise"},
  {violet               , "violet"},
  {wheat                , "wheat"},
  {white                , "white"},
  {whitesmoke           , "whitesmoke"},
  {yellow               , "yellow"},
  {yellowgreen          , "yellowgreen"}
};

LPCSTR CColor::GetNameFromIndex(int i)
{
  ASSERT(0 <= i && i < numNamedColors);
  return m_namedColor[i].name;
}

CColor CColor::GetColorFromIndex(int i)
{
  ASSERT(0 <= i && i < numNamedColors);
  return m_namedColor[i].color;
}

CColor CColor::FromString(LPCSTR pcColor)
{
  CColor t;
  t.SetString(pcColor);
  return t;
}

CColor::CColor(COLORREF cr)
: m_bIsRGB(true), m_bIsHLS(false), m_colorref(cr)
{}

CColor::operator COLORREF() const
{
  const_cast<CColor*>(this)->ToRGB();
  return m_colorref;
}

// RGB

void CColor::SetRed(int red)
{
  ASSERT(0 <= red && red <= 255);
  ToRGB();
  m_color[c_red] = static_cast<unsigned char>(red);
  m_bIsHLS = false;
}

void CColor::SetGreen(int green)
{
  ASSERT(0 <= green && green <= 255);
  ToRGB();
  m_color[c_green] = static_cast<unsigned char>(green);
  m_bIsHLS = false;
}

void CColor::SetBlue(int blue)
{
  ASSERT(0 <= blue && blue <= 255);
  ToRGB();
  m_color[c_blue] = static_cast<unsigned char>(blue);
  m_bIsHLS = false;
}

void CColor::SetRGB(int red, int green, int blue)
{
  ASSERT(0 <= red && red <= 255);
  ASSERT(0 <= green && green <= 255);
  ASSERT(0 <= blue && blue <= 255);

  m_color[c_red]   = static_cast<unsigned char>(red);
  m_color[c_green] = static_cast<unsigned char>(green);
  m_color[c_blue]  = static_cast<unsigned char>(blue);
  m_bIsHLS = false;
  m_bIsRGB = true;
}

int CColor::GetRed() const
{
  const_cast<CColor*>(this)->ToRGB();
  return m_color[c_red];
}

int CColor::GetGreen() const
{
  const_cast<CColor*>(this)->ToRGB();
  return m_color[c_green];
}

int CColor::GetBlue() const
{
  const_cast<CColor*>(this)->ToRGB();
  return m_color[c_blue];
}

// HSL

void CColor::SetHue(float hue)
{
  ASSERT(hue >= 0.0 && hue <= 360.0);

  ToHLS();
  m_hue = hue;
  m_bIsRGB = false;
}

void CColor::SetSaturation(float saturation)
{
  ASSERT(saturation >= 0.0 && saturation <= 1.0); // 0.0 ist undefiniert

  ToHLS();
  m_saturation = saturation;
  m_bIsRGB = false;
}

void CColor::SetLuminance(float luminance)
{
  ASSERT(luminance >= 0.0 && luminance <= 1.0);

  ToHLS();
  m_luminance = luminance;
  m_bIsRGB = false;
}

void CColor::SetHLS(float hue, float luminance, float saturation)
{
  ASSERT(hue >= 0.0 && hue <= 360.0);
  ASSERT(luminance >= 0.0 && luminance <= 1.0);
  ASSERT(saturation >= 0.0 && saturation <= 1.0); // 0.0 ist undefiniert

  m_hue = hue;
  m_luminance = luminance;
  m_saturation = saturation;
  m_bIsRGB = false;
  m_bIsHLS = true;
}

float CColor::GetHue() const
{
  const_cast<CColor*>(this)->ToHLS();
  return m_hue;
}

float CColor::GetSaturation() const
{
  const_cast<CColor*>(this)->ToHLS();
  return m_saturation;
}

float CColor::GetLuminance() const
{
  const_cast<CColor*>(this)->ToHLS();
  return m_luminance;
}

// Konvertierung

void CColor::ToHLS() 
{
  if (!m_bIsHLS)
  {
    // Konvertierung
    unsigned char minval = min(m_color[c_red], min(m_color[c_green], m_color[c_blue]));
    unsigned char maxval = max(m_color[c_red], max(m_color[c_green], m_color[c_blue]));
    float mdiff  = float(maxval) - float(minval);
    float msum   = float(maxval) + float(minval);
   
    m_luminance = msum / 510.0f;

    if (maxval == minval) 
    {
      m_saturation = 0.0f;
      m_hue = 0.0f; 
    }   
    else 
    { 
      float rnorm = (maxval - m_color[c_red]  ) / mdiff;      
      float gnorm = (maxval - m_color[c_green]) / mdiff;
      float bnorm = (maxval - m_color[c_blue] ) / mdiff;   

      m_saturation = (m_luminance <= 0.5f) ? (mdiff / msum) : (mdiff / (510.0f - msum));

      if (m_color[c_red]   == maxval) m_hue = 60.0f * (6.0f + bnorm - gnorm);
      if (m_color[c_green] == maxval) m_hue = 60.0f * (2.0f + rnorm - bnorm);
      if (m_color[c_blue]  == maxval) m_hue = 60.0f * (4.0f + gnorm - rnorm);
      if (m_hue > 360.0f) m_hue = m_hue - 360.0f;
    }
    m_bIsHLS = true;
  }
}

void CColor::ToRGB() 
{
  if (!m_bIsRGB)
  {
    if (m_saturation == 0.0) // Grauton, einfacher Fall
    {
      m_color[c_red] = m_color[c_green] = m_color[c_blue] = 
		  unsigned char(m_luminance * 255.0);
    }
    else
    {
      float rm1, rm2;
         
      if (m_luminance <= 0.5f) rm2 = m_luminance + m_luminance * m_saturation;  
      else                     rm2 = m_luminance + m_saturation - m_luminance * m_saturation;
      rm1 = 2.0f * m_luminance - rm2;   
      m_color[c_red]   = ToRGB1(rm1, rm2, m_hue + 120.0f);   
      m_color[c_green] = ToRGB1(rm1, rm2, m_hue);
      m_color[c_blue]  = ToRGB1(rm1, rm2, m_hue - 120.0f);
    }
    m_bIsRGB = true;
  }
}

unsigned char CColor::ToRGB1(float rm1, float rm2, float rh)
{
  if      (rh > 360.0f) rh -= 360.0f;
  else if (rh <   0.0f) rh += 360.0f;
 
  if      (rh <  60.0f) rm1 = rm1 + (rm2 - rm1) * rh / 60.0f;
  else if (rh < 180.0f) rm1 = rm2;
  else if (rh < 240.0f) rm1 = rm1 + (rm2 - rm1) * (240.0f - rh) / 60.0f;

#if 0  // -----------------------------------------------------------
  rm1 = rm1 * 255.;
  rm1 += 0.5;
  if (rm1 > 255.0)
	  rm1 = 255.0;
#endif // -----------------------------------------------------------

  return static_cast<unsigned char>(rm1 * 255);
}

// Stringkonvertierung im Format RRGGBB

CString CColor::GetString() const 
{
  CString color;
  color.Format("%02X%02X%02X", GetRed(), GetGreen(), GetBlue());
  return color;
}

bool CColor::SetString(LPCTSTR pcColor) 
{
  ASSERT(pcColor);
  int r, g, b;
  if (sscanf(pcColor, "%2x%2x%2x", &r, &g, &b) != 3) 
  {
    m_color[c_red] = m_color[c_green] = m_color[c_blue] = 0;
    return false;
  }
  else
  {
    m_color[c_red]   = static_cast<unsigned char>(r);
    m_color[c_green] = static_cast<unsigned char>(g);
    m_color[c_blue]  = static_cast<unsigned char>(b);
    m_bIsRGB = true;
    m_bIsHLS = false;
    return true;
  }
}

CString CColor::GetName() const
{
  const_cast<CColor*>(this)->ToRGB();
  int i = numNamedColors; 
  while (i-- && m_colorref != m_namedColor[i].color);
  if (i < 0) 
  {
    return "#" + GetString();
  }
  else return m_namedColor[i].name;
}
