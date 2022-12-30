#include "pad.h"

int PxPad_GetButtons(int id)
{
	return ((int(*)(int, int))0x2C74B8)(gPxPad, id);
}
