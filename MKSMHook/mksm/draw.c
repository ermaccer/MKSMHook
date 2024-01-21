#include "draw.h"

void PrintTextCentered(int x, int y, int color, int alpha, char* text)
{
	((void(*)(int, int, int, int, char*))0x2F50D8)(x, y, color, alpha, text);
}

void PrintText(int x, int y, int color, int font, char* text)
{
	((void(*)(int, int, int, int, char*))0x2F4EC0)(x, y, color, font,  text);
}
