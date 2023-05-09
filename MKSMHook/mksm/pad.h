#pragma once
#define gPxPad 0x6B4330 

enum PAD_ENUM
{
	PAD_L2 = 0x1,
	PAD_R2 = 0x2,
	PAD_L1 = 0x4,
	PAD_R1 = 0x8,
	PAD_TRIANGLE = 0x10,
	PAD_CIRCLE = 0x20,
	PAD_CROSS = 0x40,
	PAD_SQUARE = 0x80,
	PAD_SELECT = 0x100,
	PAD_L3 = 0x200,
	PAD_R3 = 0x400,
	PAD_START = 0x800,
	PAD_UP = 0x1000,
	PAD_RIGHT = 0x2000,
	PAD_DOWN = 0x4000,
	PAD_LEFT = 0x8000,


};

enum PxPad_AnalogStruct {
	L_X,
	L_Y,
	R_X,
	R_Y,
	MaxAnalog
};

int  PxPad_GetButtons(int id);
int  PxPad_GetRawButtons(int id);
void PxPad_GetAnalogValues(int id, char* buff);