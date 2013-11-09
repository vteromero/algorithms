// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Support for colored & styled text in Linux terminal.

#ifndef COLOR_TEXT_H_
#define COLOR_TEXT_H_

// Text style.
enum TextStyle
{
    CT_STYLE_RESET_ALL = 0,
    CT_STYLE_BOLD,
    CT_STYLE_DIM,
    CT_STYLE_UNDERLINED = 4,
    CT_STYLE_BLINK,
    CT_STYLE_REVERSE = 7,
    CT_STYLE_HIDDEN
};

// Text foreground color.
enum TextFgColor
{
    CT_FG_DEFAULT = 39,
    CT_FG_BLACK = 30,
    CT_FG_RED,
    CT_FG_GREEN,
    CT_FG_YELLOW,
    CT_FG_BLUE,
    CT_FG_MAGENTA,
    CT_FG_CYAN,
    CT_FG_LIGHT_GRAY,
    CT_FG_DARK_GRAY = 90,
    CT_FG_LIGHT_RED,
    CT_FG_LIGHT_GREEN,
    CT_FG_LIGHT_YELLOW,
    CT_FG_LIGHT_BLUE,
    CT_FG_LIGHT_MAGENTA,
    CT_FG_LIGHT_CYAN,
    CT_FG_WHITE
};

// Text background color.
enum TextBgColor
{
    CT_BG_DEFAULT = 49,
    CT_BG_BLACK = 40,
    CT_BG_RED,
    CT_BG_GREEN,
    CT_BG_YELLOW,
    CT_BG_BLUE,
    CT_BG_MAGENTA,
    CT_BG_CYAN,
    CT_BG_LIGHT_GRAY,
    CT_BG_DARK_GRAY = 100,
    CT_BG_LIGHT_RED,
    CT_BG_LIGHT_GREEN,
    CT_BG_LIGHT_YELLOW,
    CT_BG_LIGHT_BLUE,
    CT_BG_LIGHT_MAGENTA,
    CT_BG_LIGHT_CYAN,
    CT_BG_WHITE
};

// The input string will be formated by applying color and style.
void ColorText(
    const char *input,
    TextStyle type,
    TextFgColor fgcolor,
    TextBgColor bgcolor,
    char *output);

#endif // COLOR_TEXT_H_
