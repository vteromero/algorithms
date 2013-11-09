// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>

#include "color-text.h"

#include <assert.h>
#include <stdio.h>

void ColorText(
    const char *input,
    TextStyle type,
    TextFgColor fgcolor,
    TextBgColor bgcolor,
    char *output)
{
    assert(input != NULL);

    sprintf(output, "\033[%d;%d;%dm%s\033[0m",
        type, fgcolor, bgcolor, input);
}
