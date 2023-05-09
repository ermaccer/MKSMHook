#include "pad.h"

int PxPad_GetButtons(int id)
{
	return ((int(*)(int, int))0x2C74B8)(gPxPad, id);
}

int PxPad_GetRawButtons(int id)
{
	return ((int(*)(int, int))0x2C7360)(gPxPad, id);
}

void PxPad_GetAnalogValues(int id, char* buff)
{
	((void(*)(int, int, char*))0x2C7578)(gPxPad, id, buff);
}
