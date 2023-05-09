#pragma once
#include "mksm/mksm.h"
#include "menu.h"

void process_hook_in_game();

#ifndef PS2_BUILD
void hook_set_vector();
#endif
