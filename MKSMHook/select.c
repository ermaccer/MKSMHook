#include "select.h"
#include "mksm/mksm.h"

void custom_select_screen()
{
	selectscreen* sel = (selectscreen*)SELECT_SCREEN_PTR;
	int p1_buttons = PxPad_GetButtons(0);
	int p2_buttons = PxPad_GetButtons(1);

	if (p1_buttons > 0)
	{
		int cursor = sel->p1_cursor;
		int chr = sel->characters[cursor].characterID;

		if (p1_buttons & PAD_UP)
			chr--;
		if (p1_buttons & PAD_DOWN)
			chr++;

		if (chr < 0) chr = NUM_CHARACTERS;
		if (chr > NUM_CHARACTERS) chr = 0;
#ifndef PS2_BUILD
		_printf("Character %03d : %s\n", chr, get_character_name(chr));
#endif // !PS2_BUILD

		sel->characters[cursor].stringID = CHARACTER_STRING_START + chr;
		sel->characters[cursor].characterID = chr;

	}
	if (p2_buttons > 0)
	{
		int cursor = sel->p2_cursor;
		int chr = sel->characters[cursor].characterID;

		if (p2_buttons & PAD_UP)
			chr--;
		if (p2_buttons & PAD_DOWN)
			chr++;

		if (chr < 0) chr = NUM_CHARACTERS;
		if (chr > NUM_CHARACTERS) chr = 0;
#ifndef PS2_BUILD
		_printf("P2 Character %03d : %s\n", chr, get_character_name(chr));
#endif // !PS2_BUILD
		sel->characters[cursor].stringID = CHARACTER_STRING_START + chr;
		sel->characters[cursor].characterID = chr;

	}


}
