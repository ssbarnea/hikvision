/****************************************************************************\
Datei  : Color.h
Projekt: Farbverwaltung
Inhalt : CColor Deklaration
Datum  : 10.01.1999
Autor  : Christian Rodemeyer
Hinweis: © 1999 by Christian Rodemeyer
\****************************************************************************/
#pragma once

#ifndef __COLOR_H                                               
#define __COLOR_H

/****************************************************************************\
 CColor: Repräsentiert einen Farbwert
\****************************************************************************/
class CColor
{
public:

  // COLORREF Konvertierung
  // ----------------------
  CColor(COLORREF cr = black);
  operator COLORREF() const;

  // RGB - Routinen
  // --------------
  void SetRed(int red);     // 0..255  
  void SetGreen(int green); // 0..255
  void SetBlue(int blue);   // 0..255
  void SetRGB(int red, int green, int blue);

  int GetRed() const;   // 0..255
  int GetGreen() const; // 0..255
  int GetBlue() const;  // 0..255

  // HLS - Routinen
  // --------------
  void SetHue(float hue);               // 0.0 .. 360.0
  void SetLuminance(float luminance);   // 0.0 .. 1.0
  void SetSaturation(float saturation); // 0.0 .. 1.0
  void SetHLS(float hue, float luminance, float saturation);

  float GetHue() const;        // 0.0 .. 360.0
  float GetLuminance() const;  // 0.0 .. 1.0
  float GetSaturation() const; // 0.0 .. 1.0

  // String Konvertierung
  // ---------------------
  CString GetString() const;          // Liefert String im Format RRGGBB
  bool    SetString(LPCSTR pcColor); // Erwartet String im Format RRGGBB

  // Benannte Web Farben
  // -------------------
  CString GetName() const; // Liefert String mit benannter Farbe oder #RRGGBB falls kein Name bekannt

  static CColor FromString(LPCSTR pcColor); 
  static LPCSTR GetNameFromIndex(int i);
  static CColor GetColorFromIndex(int i);
  static int    GetNumNames() {return numNamedColors;}

  enum ENamedColor // Named Colors, could be used as COLORREF
  {
    none                 = 0x7FFFFFFF,   // keine Farbe
    aliceblue            = 0x00FFF8F0,   // RGB(0xF0, 0xF8, 0xFF) 
    antiquewhite         = 0x00D7EBFA,   // RGB(0xFA, 0xEB, 0xD7) 
    aqua                 = 0x00FFFF00,   // RGB(0x00, 0xFF, 0xFF) 
    aquamarine           = 0x00D4FF7F,   // RGB(0x7F, 0xFF, 0xD4) 
    azure                = 0x00FFFFF0,   // RGB(0xF0, 0xFF, 0xFF) 
    beige                = 0x00DCF5F5,   // RGB(0xF5, 0xF5, 0xDC) 
    bisque               = 0x00C4E4FF,   // RGB(0xFF, 0xE4, 0xC4) 
    black                = 0x00000000,   // RGB(0x00, 0x00, 0x00) 
    blanchedalmond       = 0x00CDEBFF,   // RGB(0xFF, 0xEB, 0xCD) 
    blue                 = 0x00FF0000,   // RGB(0x00, 0x00, 0xFF) 
    blueviolet           = 0x00E22B8A,   // RGB(0x8A, 0x2B, 0xE2) 
    brown                = 0x002A2AA5,   // RGB(0xA5, 0x2A, 0x2A) 
    burlywood            = 0x0087B8DE,   // RGB(0xDE, 0xB8, 0x87) 
    cadetblue            = 0x00A09E5F,   // RGB(0x5F, 0x9E, 0xA0) 
    chartreuse           = 0x0000FF7F,   // RGB(0x7F, 0xFF, 0x00) 
    chocolate            = 0x001E69D2,   // RGB(0xD2, 0x69, 0x1E) 
    coral                = 0x00507FFF,   // RGB(0xFF, 0x7F, 0x50) 
    cornflower           = 0x00ED9564,   // RGB(0x64, 0x95, 0xED) 
    cornsilk             = 0x00DCF8FF,   // RGB(0xFF, 0xF8, 0xDC) 
    crimson              = 0x003C14DC,   // RGB(0xDC, 0x14, 0x3C) 
    cyan                 = 0x00FFFF00,   // RGB(0x00, 0xFF, 0xFF) 
    darkblue             = 0x008B0000,   // RGB(0x00, 0x00, 0x8B) 
    darkcyan             = 0x008B8B00,   // RGB(0x00, 0x8B, 0x8B) 
    darkgoldenrod        = 0x000B86B8,   // RGB(0xB8, 0x86, 0x0B) 
    darkgray             = 0x00A9A9A9,   // RGB(0xA9, 0xA9, 0xA9) 
    darkgreen            = 0x00006400,   // RGB(0x00, 0x64, 0x00) 
    darkkhaki            = 0x006BB7BD,   // RGB(0xBD, 0xB7, 0x6B) 
    darkmagenta          = 0x008B008B,   // RGB(0x8B, 0x00, 0x8B) 
    darkolivegreen       = 0x002F6B55,   // RGB(0x55, 0x6B, 0x2F) 
    darkorange           = 0x00008CFF,   // RGB(0xFF, 0x8C, 0x00) 
    darkorchid           = 0x00CC3299,   // RGB(0x99, 0x32, 0xCC) 
    darkred              = 0x0000008B,   // RGB(0x8B, 0x00, 0x00) 
    darksalmon           = 0x007A96E9,   // RGB(0xE9, 0x96, 0x7A) 
    darkseagreen         = 0x008BBC8F,   // RGB(0x8F, 0xBC, 0x8B) 
    darkslateblue        = 0x008B3D48,   // RGB(0x48, 0x3D, 0x8B) 
    darkslategray        = 0x004F4F2F,   // RGB(0x2F, 0x4F, 0x4F) 
    darkturquoise        = 0x00D1CE00,   // RGB(0x00, 0xCE, 0xD1) 
    darkviolet           = 0x00D30094,   // RGB(0x94, 0x00, 0xD3) 
    deeppink             = 0x009314FF,   // RGB(0xFF, 0x14, 0x93) 
    deepskyblue          = 0x00FFBF00,   // RGB(0x00, 0xBF, 0xFF) 
    dimgray              = 0x00696969,   // RGB(0x69, 0x69, 0x69) 
    dodgerblue           = 0x00FF901E,   // RGB(0x1E, 0x90, 0xFF) 
    firebrick            = 0x002222B2,   // RGB(0xB2, 0x22, 0x22) 
    floralwhite          = 0x00F0FAFF,   // RGB(0xFF, 0xFA, 0xF0) 
    forestgreen          = 0x00228B22,   // RGB(0x22, 0x8B, 0x22) 
    fuchsia              = 0x00FF00FF,   // RGB(0xFF, 0x00, 0xFF) 
    gainsboro            = 0x00DCDCDC,   // RGB(0xDC, 0xDC, 0xDC) 
    ghostwhite           = 0x00FFF8F8,   // RGB(0xF8, 0xF8, 0xFF) 
    gold                 = 0x0000D7FF,   // RGB(0xFF, 0xD7, 0x00) 
    goldenrod            = 0x0020A5DA,   // RGB(0xDA, 0xA5, 0x20) 
    gray                 = 0x00808080,   // RGB(0x80, 0x80, 0x80) 
    green                = 0x00008000,   // RGB(0x00, 0x80, 0x00) 
    greenyellow          = 0x002FFFAD,   // RGB(0xAD, 0xFF, 0x2F) 
    honeydew             = 0x00F0FFF0,   // RGB(0xF0, 0xFF, 0xF0) 
    hotpink              = 0x00B469FF,   // RGB(0xFF, 0x69, 0xB4) 
    indianred            = 0x005C5CCD,   // RGB(0xCD, 0x5C, 0x5C) 
    indigo               = 0x0082004B,   // RGB(0x4B, 0x00, 0x82) 
    ivory                = 0x00F0FFFF,   // RGB(0xFF, 0xFF, 0xF0) 
    khaki                = 0x008CE6F0,   // RGB(0xF0, 0xE6, 0x8C) 
    lavender             = 0x00FAE6E6,   // RGB(0xE6, 0xE6, 0xFA) 
    lavenderblush        = 0x00F5F0FF,   // RGB(0xFF, 0xF0, 0xF5) 
    lawngreen            = 0x0000FC7C,   // RGB(0x7C, 0xFC, 0x00) 
    lemonchiffon         = 0x00CDFAFF,   // RGB(0xFF, 0xFA, 0xCD) 
    lightblue            = 0x00E6D8AD,   // RGB(0xAD, 0xD8, 0xE6) 
    lightcoral           = 0x008080F0,   // RGB(0xF0, 0x80, 0x80) 
    lightcyan            = 0x00FFFFE0,   // RGB(0xE0, 0xFF, 0xFF) 
    lightgoldenrodyellow = 0x00D2FAFA,   // RGB(0xFA, 0xFA, 0xD2) 
    lightgreen           = 0x0090EE90,   // RGB(0x90, 0xEE, 0x90) 
    lightgrey            = 0x00D3D3D3,   // RGB(0xD3, 0xD3, 0xD3) 
    lightpink            = 0x00C1B6FF,   // RGB(0xFF, 0xB6, 0xC1) 
    lightsalmon          = 0x007AA0FF,   // RGB(0xFF, 0xA0, 0x7A) 
    lightseagreen        = 0x00AAB220,   // RGB(0x20, 0xB2, 0xAA) 
    lightskyblue         = 0x00FACE87,   // RGB(0x87, 0xCE, 0xFA) 
    lightslategray       = 0x00998877,   // RGB(0x77, 0x88, 0x99) 
    lightsteelblue       = 0x00DEC4B0,   // RGB(0xB0, 0xC4, 0xDE) 
    lightyellow          = 0x00E0FFFF,   // RGB(0xFF, 0xFF, 0xE0) 
    lime                 = 0x0000FF00,   // RGB(0x00, 0xFF, 0x00) 
    limegreen            = 0x0032CD32,   // RGB(0x32, 0xCD, 0x32) 
    linen                = 0x00E6F0FA,   // RGB(0xFA, 0xF0, 0xE6) 
    magenta              = 0x00FF00FF,   // RGB(0xFF, 0x00, 0xFF) 
    maroon               = 0x00000080,   // RGB(0x80, 0x00, 0x00) 
    mediumaquamarine     = 0x00AACD66,   // RGB(0x66, 0xCD, 0xAA) 
    mediumblue           = 0x00CD0000,   // RGB(0x00, 0x00, 0xCD) 
    mediumorchid         = 0x00D355BA,   // RGB(0xBA, 0x55, 0xD3) 
    mediumpurple         = 0x00DB7093,   // RGB(0x93, 0x70, 0xDB) 
    mediumseagreen       = 0x0071B33C,   // RGB(0x3C, 0xB3, 0x71) 
    mediumslateblue      = 0x00EE687B,   // RGB(0x7B, 0x68, 0xEE) 
    mediumspringgreen    = 0x009AFA00,   // RGB(0x00, 0xFA, 0x9A) 
    mediumturquoise      = 0x00CCD148,   // RGB(0x48, 0xD1, 0xCC) 
    mediumvioletred      = 0x008515C7,   // RGB(0xC7, 0x15, 0x85) 
    midnightblue         = 0x00701919,   // RGB(0x19, 0x19, 0x70) 
    mintcream            = 0x00FAFFF5,   // RGB(0xF5, 0xFF, 0xFA) 
    mistyrose            = 0x00E1E4FF,   // RGB(0xFF, 0xE4, 0xE1) 
    moccasin             = 0x00B5E4FF,   // RGB(0xFF, 0xE4, 0xB5) 
    navajowhite          = 0x00ADDEFF,   // RGB(0xFF, 0xDE, 0xAD) 
    navy                 = 0x00800000,   // RGB(0x00, 0x00, 0x80) 
    oldlace              = 0x00E6F5FD,   // RGB(0xFD, 0xF5, 0xE6) 
    olive                = 0x00008080,   // RGB(0x80, 0x80, 0x00) 
    olivedrab            = 0x00238E6B,   // RGB(0x6B, 0x8E, 0x23) 
    orange               = 0x0000A5FF,   // RGB(0xFF, 0xA5, 0x00) 
    orangered            = 0x000045FF,   // RGB(0xFF, 0x45, 0x00) 
    orchid               = 0x00D670DA,   // RGB(0xDA, 0x70, 0xD6) 
    palegoldenrod        = 0x00AAE8EE,   // RGB(0xEE, 0xE8, 0xAA) 
    palegreen            = 0x0098FB98,   // RGB(0x98, 0xFB, 0x98) 
    paleturquoise        = 0x00EEEEAF,   // RGB(0xAF, 0xEE, 0xEE) 
    palevioletred        = 0x009370DB,   // RGB(0xDB, 0x70, 0x93) 
    papayawhip           = 0x00D5EFFF,   // RGB(0xFF, 0xEF, 0xD5) 
    peachpuff            = 0x00B9DAFF,   // RGB(0xFF, 0xDA, 0xB9) 
    peru                 = 0x003F85CD,   // RGB(0xCD, 0x85, 0x3F) 
    pink                 = 0x00CBC0FF,   // RGB(0xFF, 0xC0, 0xCB) 
    plum                 = 0x00DDA0DD,   // RGB(0xDD, 0xA0, 0xDD) 
    powderblue           = 0x00E6E0B0,   // RGB(0xB0, 0xE0, 0xE6) 
    purple               = 0x00800080,   // RGB(0x80, 0x00, 0x80) 
    red                  = 0x000000FF,   // RGB(0xFF, 0x00, 0x00) 
    rosybrown            = 0x008F8FBC,   // RGB(0xBC, 0x8F, 0x8F) 
    royalblue            = 0x00E16941,   // RGB(0x41, 0x69, 0xE1) 
    saddlebrown          = 0x0013458B,   // RGB(0x8B, 0x45, 0x13) 
    salmon               = 0x007280FA,   // RGB(0xFA, 0x80, 0x72) 
    sandybrown           = 0x0060A4F4,   // RGB(0xF4, 0xA4, 0x60) 
    seagreen             = 0x00578B2E,   // RGB(0x2E, 0x8B, 0x57) 
    seashell             = 0x00EEF5FF,   // RGB(0xFF, 0xF5, 0xEE) 
    sienna               = 0x002D52A0,   // RGB(0xA0, 0x52, 0x2D) 
    silver               = 0x00C0C0C0,   // RGB(0xC0, 0xC0, 0xC0) 
    skyblue              = 0x00EBCE87,   // RGB(0x87, 0xCE, 0xEB) 
    slateblue            = 0x00CD5A6A,   // RGB(0x6A, 0x5A, 0xCD) 
    slategray            = 0x00908070,   // RGB(0x70, 0x80, 0x90) 
    snow                 = 0x00FAFAFF,   // RGB(0xFF, 0xFA, 0xFA) 
    springgreen          = 0x007FFF00,   // RGB(0x00, 0xFF, 0x7F) 
    steelblue            = 0x00B48246,   // RGB(0x46, 0x82, 0xB4) 
    tan                  = 0x008CB4D2,   // RGB(0xD2, 0xB4, 0x8C) 
    teal                 = 0x00808000,   // RGB(0x00, 0x80, 0x80) 
    thistle              = 0x00D8BFD8,   // RGB(0xD8, 0xBF, 0xD8) 
    tomato               = 0x004763FF,   // RGB(0xFF, 0x63, 0x47) 
    turquoise            = 0x00D0E040,   // RGB(0x40, 0xE0, 0xD0) 
    violet               = 0x00EE82EE,   // RGB(0xEE, 0x82, 0xEE) 
    wheat                = 0x00B3DEF5,   // RGB(0xF5, 0xDE, 0xB3) 
    white                = 0x00FFFFFF,   // RGB(0xFF, 0xFF, 0xFF) 
    whitesmoke           = 0x00F5F5F5,   // RGB(0xF5, 0xF5, 0xF5) 
    yellow               = 0x0000FFFF,   // RGB(0xFF, 0xFF, 0x00) 
    yellowgreen          = 0x0032CD9A,   // RGB(0x9A, 0xCD, 0x32) 
  };

  enum ENamedColorIndex
  { 
    i_aliceblue, i_antiquewhite, i_aqua, i_aquamarine, i_azure, i_beige, i_bisque, i_black, 
    i_blanchedalmond, i_blue, i_blueviolet, i_brown, i_burlywood, i_cadetblue, i_chartreuse,
    i_chocolate, i_coral, i_cornflower, i_cornsilk, i_crimson, i_cyan, i_darkblue, i_darkcyan, 
    i_darkgoldenrod, i_darkgray, i_darkgreen, i_darkkhaki, i_darkmagenta, i_darkolivegreen, 
    i_darkorange, i_darkorchid, i_darkred, i_darksalmon, i_darkseagreen, i_darkslateblue, 
    i_darkslategray, i_darkturquoise, i_darkviolet, i_deeppink, i_deepskyblue, i_dimgray, 
    i_dodgerblue, i_firebrick, i_floralwhite, i_forestgreen, i_fuchsia, i_gainsboro, 
    i_ghostwhite, i_gold, i_goldenrod, i_gray, i_green, i_greenyellow, i_honeydew, i_hotpink, 
    i_indianred, i_indigo, i_ivory, i_khaki, i_lavender, i_lavenderblush, i_lawngreen, 
    i_lemonchiffon, i_lightblue, i_lightcoral, i_lightcyan, i_lightgoldenrodyellow, 
    i_lightgreen, i_lightgrey, i_lightpink, i_lightsalmon, i_lightseagreen, i_lightskyblue, 
    i_lightslategray, i_lightsteelblue, i_lightyellow, i_lime, i_limegreen, i_linen, 
    i_magenta, i_maroon, i_mediumaquamarine, i_mediumblue, i_mediumorchid, i_mediumpurple, 
    i_mediumseagreen, i_mediumslateblue, i_mediumspringgreen, i_mediumturquoise, 
    i_mediumvioletred, i_midnightblue, i_mintcream, i_mistyrose, i_moccasin, i_navajowhite, 
    i_navy, i_oldlace, i_olive, i_olivedrab, i_orange, i_orangered, i_orchid, i_palegoldenrod, 
    i_palegreen, i_paleturquoise, i_palevioletred, i_papayawhip, i_peachpuff, i_peru, i_pink,
    i_plum, i_powderblue, i_purple, i_red, i_rosybrown, i_royalblue, i_saddlebrown, i_salmon, 
    i_sandybrown, i_seagreen, i_seashell, i_sienna, i_silver, i_skyblue, i_slateblue, 
    i_slategray, i_snow, i_springgreen, i_steelblue, i_tan, i_teal, i_thistle, i_tomato, 
    i_turquoise, i_violet, i_wheat, i_white, i_whitesmoke, i_yellow, i_yellowgreen,
    numNamedColors
  };

  void ToRGB(); // logisch konstant, nicht physikalisch
  void ToHLS(); // logisch konstant, nicht physikalisch

private:

  // Konvertierung
  // -------------
  static unsigned char ToRGB1(float rm1, float rm2, float rh);

  // Daten
  // -----
  union // Byteweiser Zugriff auf die COLORREF Struktur
  {
    COLORREF      m_colorref;
    unsigned char m_color[4];
  };
  enum {c_red = 0, c_green = 1, c_blue = 2, c_null = 3}; // enum Hack für colorbyte-Index

  float m_hue;         // 0.0 .. 360.0  // Winkel
  float m_saturation;  // 0.0 .. 1.0    // Prozent
  float m_luminance;   // 0.0 .. 1.0    // Prozent

  // Flag für Lazy Evaluation
  bool m_bIsRGB; 
  bool m_bIsHLS; 

  // statische Konstanten für benannte Farben
  struct DNamedColor
  {
    COLORREF color; 
    LPCTSTR  name;
  };
  static const DNamedColor m_namedColor[numNamedColors]; 
};

#endif

