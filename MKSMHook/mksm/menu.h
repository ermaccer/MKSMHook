#pragma once

#define TOTAL_SELECT_CHARACTERS 7
#define SELECT_SCREEN_PTR 0x5CC5F0
#define MENU_ITEM_PTR 0x4C7078
typedef struct {
	int stringID;
	int function;
}frontendmenu_entry;

typedef struct {
	int boxStatus;
	int stringID;
	int characterID;
}selectscreen_entry;


typedef struct
{
	int field0;
	int field4;
	int field8;
	int field12;
	int field16;
	int field20;
	int field24;
	int field28;
	int field32;
	int field36;
	int field40;
	int p1_padID;
	int p2_padID;
	int field52;
	int field56;
	int p1_cursor;
	int p2_cursor;
	int field68;
	int field72;
	selectscreen_entry characters[TOTAL_SELECT_CHARACTERS];
	char pad[68];
	int stageID;

}selectscreen;