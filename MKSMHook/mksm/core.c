#include "core.h"

void _printf(const char* text, ...)
{
	((void(*)(const char*, ...))0x482610)(text);
}

void _sprintf(char* buffer, const char* format, ...)
{
	((void(*)(char*, const char*, ...))0x475918)(buffer, format);
}

void SetGameType(int type)
{
	((void(*)(int))0x1663E0)(type);
	// reset health
	((void(*)())0x1EE858)();

}

int GetTickCounter()
{
	return *(int*)0x565020;
}
