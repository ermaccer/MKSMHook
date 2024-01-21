#include <stdio.h>
#include "mksm/mksm.h"
#include "ps2mem.h"
#include "mips.h"
#include "hook.h"
#include "menu.h"
#include "select.h"

int CompatibleCRCList[] = { 0x455DD546 };

void game_loop_hook(int state)
{    
    ((void(*)(int))0x1D73C8)(state);
    process_hook_in_game();
}


void cursor_hook(int a0, int a1, int a2)
{
    ((void(*)(int, int, int))0x13CD80)(a0, a1, a2);
    custom_select_screen();
}


void init()
{
     initialize_menu();
#ifndef PS2_BUILD
     _printf("MKSMHook init! Version: %s\n", MKSMHOOK_VERSION);
#endif // !PS2_BUILD



     makeJal(0x1D4F98, game_loop_hook);
     makeJal(0x1D9A50, game_loop_hook);
     makeJal(0x1DC148, game_loop_hook);

     patchInt(0x5739AC, (int)&cursor_hook);
     patchInt(0x4B09EC, (int)&cursor_hook);

     makeJal(0x1EB988, hook_player_control);
}


#ifdef PS2_BUILD
// needs to be 03 because O0 ironically does some funky stuff with this function
void __attribute__((optimize("O3"))) INVOKER()
{
    asm("ei\n");
    asm("addiu $ra, -4\n");

    init();
}
#endif // PS2_BUILD




int __attribute__((optimize("O3"))) main()
{
    return 0;
}
