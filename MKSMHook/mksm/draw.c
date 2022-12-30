#include "draw.h"

void PrintText(int x, int y, int color, int alpha, char* text)
{
	((void(*)(int, int, int, int, char*))0x2F50D8)(x, y, color, alpha, text);
}
