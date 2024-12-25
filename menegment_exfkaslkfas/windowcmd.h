#ifndef WINDOWCMD_H
#define WINDOWCMD_H
#pragma once

#include <windows.h>

void setConsoleSize(int width, int height);
void lockConsoleResize();
void setColor(int textColor, int backgroundColor);

#endif