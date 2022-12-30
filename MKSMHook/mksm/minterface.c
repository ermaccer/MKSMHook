#include "minterface.h"
#include "core.h"

int cModelInterface_GetObjectPointer(int id)
{
	return ((int(*)(int, int))0x283B50)(gModelInterface, id);
}

void SetLoadedType(int id, short type)
{
	((void(*)(int, short))0x2F6BA0)(id, type);
}

void SetCharacterFiles(int id, int objectID, int unk, int unk2, int vram, int unk3)
{
	((void(*)(int, int, int, int, int, int))0x1CEE00)(id, objectID, unk, unk2, vram, unk3);
}

void SwapCharacterModel(int id, int obj, int unk3)
{
	int mdl = cModelInterface_GetObjectPointer(id);
	if (mdl)
	{
		SetLoadedType(1, 0);
		//_printf("MDL: %x\n", mdl);
		//*(unsigned char*)(mdl + 10090) = 0;
		//SetCharacterFiles(1, 0x5A, 0, 1, PLAYER1_VRAM, 0x21);
	}
}
