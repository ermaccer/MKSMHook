#pragma once

#define gModelInterface 0x67C590
#define PLAYER1_VRAM *(int*)0x4E5094
#define PLAYER2_VRAM *(int*)0x4E5098

int cModelInterface_GetObjectPointer(int id);	
void SetLoadedType(int id, short type);
// 1 0x5A, 0, 1, PLAYER1_VRAM, 0x21
void SetCharacterFiles(int id, int objectID, int unk, int unk2, int vram, int unk3);

void SwapCharacterModel(int id, int obj, int unk3);