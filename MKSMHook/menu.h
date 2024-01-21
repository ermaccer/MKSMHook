#pragma once
#include "types.h"
#include "mksm/mksm.h"


enum eMenuItems {
	MENU_CAMERA,
	MENU_GAME,
	MENU_ENEMY_SPAWNER,
	MENU_MISC,
	TOTAL_MENUS
};


// vars

extern int32 ms_MenuActive;
extern int32 ms_FreeCamera;
extern int32 ms_FreeCameraAbsoluteControls;
extern int32 ms_FreezeWorld;


typedef struct{
	char* name;
	int* toggle;
	void (*func)();
	char* tip;
} menu_entry;



void initialize_menu();

void menu_draw();
void menu_update();

bool key_pressed(int vKey);

// funcs

void set_mode_sp();
void set_mode_coop();
void set_mode_vs();
void set_mode_practice();

void open_debug_menu();

void toggle_freeze_world();
void toggle_free_camera();

void add_fov();
void dec_fov();
void reset_fov();
void reset_enemies();
void spawn_enemies();
// hooks 
void hook_player_control(int a0, int a1);
