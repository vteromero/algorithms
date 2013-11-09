// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// This file tests the functions defined in color-text.h

#include <stdio.h>

#include "util/color-text.h"

int main()
{
    char text[10];
    char colored_text[100];

    sprintf(text, "%8s", "HELLO!");

    // Tests foreground colors
    const int test1_len = 15;
    int test1[test1_len][3] = {
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_RED, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_GREEN, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_YELLOW, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_BLUE, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_MAGENTA, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_CYAN, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_LIGHT_GRAY, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_DARK_GRAY, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_LIGHT_RED, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_LIGHT_GREEN, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_LIGHT_YELLOW, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_LIGHT_BLUE, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_LIGHT_MAGENTA, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_LIGHT_CYAN, CT_BG_DEFAULT}
    };

    for(int i=0; i<test1_len; ++i)
    {
        ColorText(
            text,
            (TextStyle)test1[i][0],
            (TextFgColor)test1[i][1],
            (TextBgColor)test1[i][2],
            colored_text);

        printf("%s", colored_text);
    }
    printf("\n");

    // Tests background colors
    const int test2_len = 15;
    int test2[test2_len][3] = {
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_DEFAULT},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_RED},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_GREEN},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_YELLOW},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_BLUE},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_MAGENTA},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_CYAN},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_LIGHT_GRAY},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_DARK_GRAY},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_LIGHT_RED},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_LIGHT_GREEN},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_LIGHT_YELLOW},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_LIGHT_BLUE},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_LIGHT_MAGENTA},
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_LIGHT_CYAN}
    };

    for(int i=0; i<test2_len; ++i)
    {
        ColorText(
            text,
            (TextStyle)test2[i][0],
            (TextFgColor)test2[i][1],
            (TextBgColor)test2[i][2],
            colored_text);

        printf("%s", colored_text);
    }
    printf("\n");

    // Tests styles
    const int test3_len = 5;
    int test3[test3_len][3] = {
        {CT_STYLE_RESET_ALL, CT_FG_DEFAULT, CT_BG_DEFAULT},
        {CT_STYLE_BOLD, CT_FG_DEFAULT, CT_BG_DEFAULT},
        {CT_STYLE_DIM, CT_FG_DEFAULT, CT_BG_DEFAULT},
        {CT_STYLE_UNDERLINED, CT_FG_DEFAULT, CT_BG_DEFAULT},
        {CT_STYLE_BLINK, CT_FG_DEFAULT, CT_BG_DEFAULT}
    };

    for(int i=0; i<test3_len; ++i)
    {
        ColorText(
            text,
            (TextStyle)test3[i][0],
            (TextFgColor)test3[i][1],
            (TextBgColor)test3[i][2],
            colored_text);

        printf("%s", colored_text);
    }
    printf("\n");

    return 0;
}
