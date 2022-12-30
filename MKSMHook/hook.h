#pragma once
#include "mksm/mksm.h"
#include "menu.h"

void pressed_keyboard_key(int vKey);
void process_hook_timer();
void process_hook_in_game();


void hook_set_vector();

// data hooks

void Camera_HookSetPosition(vector* dest, vector* src);