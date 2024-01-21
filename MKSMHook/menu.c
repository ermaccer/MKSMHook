#include "menu.h"
#include "freecamera.h"
#include "mouse.h"

char buffer[256] = { 0 };
int m_nCurrentPos = 0;
int m_nTimer = 0;
int m_nCurrentMenuOpen = -1;

int32 ms_MenuActive = false;
int32 ms_FreeCamera = false;
int32 ms_SwapToDebug = false;
int32 ms_FreeCameraAbsoluteControls = true;
int32 ms_FreezeWorld = false;

char* m_szMenuOptions[TOTAL_MENUS] = {
	"Camera",
	"Game",
	"Enemy Spawner",
	"Misc."
};


menu_entry CameraOptions[] =
{
#ifndef PS2_BUILD
	{"Free Camera", &ms_FreeCamera, 0, "Use keyboard to move the camera. Shortcut - G"},
	{"Absolute Controls", &ms_FreeCameraAbsoluteControls, 0, "Move X and Z without camera matrix. Don't disable for now."},
#else
	{"Free Camera", &ms_FreeCamera, 0, "Use keyboard to move the camera."},
#endif

	{"Increase FOV", 0, add_fov, "Only works in free camera."},
	{"Decrease FOV", 0, dec_fov, "Only works in free camera."},
	{"Reset FOV", 0, reset_fov, "Only works in free camera."},
	{"Update Flag", (int*)0x511378, 0, "Freezes player and entities while in free camera."}
};

menu_entry GameOptions[] =
{
	{"Set Single Player Mode", 0, set_mode_sp, "Open and close Start menu to refresh lifebars."},
	{"Set Versus Mode", 0, set_mode_vs, "Open and close Start menu to refresh lifebars."},
	{"Set Ko-op Mode", 0, set_mode_coop, "Open and close Start menu to refresh lifebars."},
	{"Set Practice Mode", 0, set_mode_practice, "Open and close Start menu to refresh lifebars."},
};


menu_entry MiscOptions[] =
{
	{"Debug Menu", &ms_SwapToDebug, 0, "Swaps Continue option in pause menu."},
#ifndef PS2_BUILD
	{"Freeze Characters",0, toggle_freeze_world, "Shortcut - H"}
#else
	{"Freeze Characters",0, toggle_freeze_world, ""}
#endif
};

menu_entry SpawnerOptions[] =
{
	{"Enemy 1", (int*)0x515DE0, 0, "T"},
	{"Enemy 1 Amount",(int*)0x515DF0, 0, ""},

	{"Enemy 2", (int*)0x515DE4, 0, "T"},
	{"Enemy 2 Amount",(int*)0x0515DF4, 0, ""},

	{"Enemy 3", (int*)0x515DE8, 0, "T"},
	{"Enemy 3 Amount",(int*)0x515DF8, 0, ""},

	{"Enemy 4", (int*)0x515DEC, 0, "T"},
	{"Enemy 4 Amount",(int*)0x515DFC, 0, ""},

	{"Spawn Enemies",0, spawn_enemies, ""},
	{"Reset Values",0, reset_enemies, ""}
};

void initialize_menu()
{
	m_nCurrentPos = 0;
	m_nCurrentMenuOpen = -1;
	ms_FreeCamera = false;
	ms_MenuActive = false;
	ms_SwapToDebug = false;
	ms_FreeCameraAbsoluteControls = true;
	ms_FreezeWorld = false;
	m_nTimer = GetTickCounter();
}

void menu_draw()
{
	if (ms_MenuActive == true)
	{
		int total = TOTAL_MENUS;

		switch (m_nCurrentMenuOpen)
		{
		case MENU_CAMERA:
			total = sizeof(CameraOptions) / sizeof(CameraOptions[0]);
			break;
		case MENU_GAME:
			total = sizeof(GameOptions) / sizeof(GameOptions[0]);
			break;
		case MENU_ENEMY_SPAWNER:
			total = sizeof(SpawnerOptions) / sizeof(SpawnerOptions[0]);
			break;
		case MENU_MISC:
			total = sizeof(MiscOptions) / sizeof(MiscOptions[0]);
			break;
		default:
			break;
		}

		if (m_nCurrentMenuOpen == MENU_CAMERA)
		{
			for (int i = 0; i < total; i++)
			{

				if (CameraOptions[i].toggle)
					_sprintf(buffer, "%s - %s", CameraOptions[i].name, TRUE_FALSE(*CameraOptions[i].toggle));
				if (CameraOptions[i].func)
					_sprintf(buffer, "%s", CameraOptions[i].name);

				if (CameraOptions[i].tip && i == m_nCurrentPos)
				{
					PrintTextCentered(323, 398, -1, 1, CameraOptions[i].tip);
					PrintTextCentered(320, 395, 255, 1, CameraOptions[i].tip);
				}

				PrintTextCentered(320 + 5, 110 + (i * 22) + 5, -1, 2, buffer);

				if (i == m_nCurrentPos)
					PrintTextCentered(320, 110 + (i * 22), 0xFF0000FF, 2, buffer);
				else
					PrintTextCentered(320, 110 + (i * 22), 255, 2, buffer);
			}
		}
		else if (m_nCurrentMenuOpen == MENU_MISC)
		{
			for (int i = 0; i < total; i++)
			{

				if (MiscOptions[i].toggle)
					_sprintf(buffer, "%s - %s", MiscOptions[i].name, TRUE_FALSE(*MiscOptions[i].toggle));
				if (MiscOptions[i].func)
					_sprintf(buffer, "%s", MiscOptions[i].name);
				if (MiscOptions[i].tip && i == m_nCurrentPos)
				{
					PrintTextCentered(323, 398, -1, 1, MiscOptions[i].tip);
					PrintTextCentered(320, 395, 255, 1, MiscOptions[i].tip);
				}


				PrintTextCentered(320 + 5, 110 + (i * 22) + 5, -1, 2, buffer);

				if (i == m_nCurrentPos)
					PrintTextCentered(320, 110 + (i * 22), 0xFF0000FF, 2, buffer);
				else
					PrintTextCentered(320, 110 + (i * 22), 255, 2, buffer);
			}
		}
		else if (m_nCurrentMenuOpen == MENU_GAME)
		{
			for (int i = 0; i < total; i++)
			{

				if (GameOptions[i].toggle)
					_sprintf(buffer, "%s - %s", GameOptions[i].name, TRUE_FALSE(*GameOptions[i].toggle));
				if (GameOptions[i].func)
					_sprintf(buffer, "%s", GameOptions[i].name);
				if (GameOptions[i].tip && i == m_nCurrentPos)
				{
					PrintTextCentered(323, 398, -1, 1, GameOptions[i].tip);
					PrintTextCentered(320, 395, 255, 1, GameOptions[i].tip);
				}


				PrintTextCentered(320 + 5, 110 + (i * 22) + 5, -1, 2, buffer);


				if (i == m_nCurrentPos)
					PrintTextCentered(320, 110 + (i * 22), 0xFF0000FF, 2, buffer);
				else
					PrintTextCentered(320, 110 + (i * 22), 255, 2, buffer);
			}
		}
		else if (m_nCurrentMenuOpen == MENU_ENEMY_SPAWNER)
		{
			for (int i = 0; i < total; i++)
			{
				if (SpawnerOptions[i].tip[0] == 'T' && SpawnerOptions[i].toggle)
				{
					char* charName = get_character_name(*SpawnerOptions[i].toggle);
					if (*SpawnerOptions[i].toggle == 0)
					{
						charName = "None";
					}
					_sprintf(buffer, "%s - %s (ID %03d)", SpawnerOptions[i].name,charName , *SpawnerOptions[i].toggle);
				}

				else if (SpawnerOptions[i].toggle)
					_sprintf(buffer, "%s - %d", SpawnerOptions[i].name, *SpawnerOptions[i].toggle);


				if (SpawnerOptions[i].func)
					_sprintf(buffer, "%s", SpawnerOptions[i].name);
				if (SpawnerOptions[i].tip && i == m_nCurrentPos && !(SpawnerOptions[i].tip[0] == 'T'))
				{
					PrintTextCentered(323, 398, -1, 1, SpawnerOptions[i].tip);
					PrintTextCentered(320, 395, 255, 1, SpawnerOptions[i].tip);
				}


				PrintTextCentered(320 + 5, 110 + (i * 22) + 5, -1, 2, buffer);


				if (i == m_nCurrentPos)
					PrintTextCentered(320, 110 + (i * 22), 0xFF0000FF, 2, buffer);
				else
					PrintTextCentered(320, 110 + (i * 22), 255, 2, buffer);
			}
		}
		else
		{
			for (int i = 0; i < total; i++)
			{
				PrintTextCentered(320 + 5, 110 + (i * 22) + 5, -1, 2, m_szMenuOptions[i]);

				if (i == m_nCurrentPos)
					PrintTextCentered(320, 110 + (i * 22), 0xFF0000FF, 2, m_szMenuOptions[i]);
				else
					PrintTextCentered(320, 110 + (i * 22), 255, 2, m_szMenuOptions[i]);
			}

		}
		
		PrintTextCentered(160, 425, 255, 1, "MKSMHook " MKSMHOOK_VERSION " by ermaccer");
	}
}

void menu_update()
{
	if (ms_MenuActive)
	{
		int buttons = PxPad_GetButtons(0);

		if (buttons & PAD_UP)
		{
			m_nCurrentPos--;
		}
		if (buttons & PAD_DOWN)
		{
			m_nCurrentPos++;
		}
		if (buttons & PAD_TRIANGLE)
		{
			m_nCurrentMenuOpen = -1;
			m_nCurrentPos = 0;
		}
		if (buttons & PAD_CROSS)
		{
			if (m_nCurrentMenuOpen == -1)
			{
				m_nCurrentMenuOpen = m_nCurrentPos;
				m_nCurrentPos = 0;
			}
			else
			{
				switch (m_nCurrentMenuOpen)
				{
				case MENU_CAMERA:
					if (CameraOptions[m_nCurrentPos].toggle)
					{
						*CameraOptions[m_nCurrentPos].toggle = !*CameraOptions[m_nCurrentPos].toggle;

						if (m_nCurrentPos == 0)
						{
							if (ms_FreeCamera == true)
								activate_freecam();
							else
								restore_freecam();
						}
					}
					if (CameraOptions[m_nCurrentPos].func)
						CameraOptions[m_nCurrentPos].func();
					break;
				case MENU_MISC:
					if (MiscOptions[m_nCurrentPos].toggle)
					{
						*MiscOptions[m_nCurrentPos].toggle = !*MiscOptions[m_nCurrentPos].toggle;
						if (m_nCurrentPos == 0)
						{
							frontendmenu_entry* pauseMenuList = (frontendmenu_entry*)0x4C6FD8;
							if (ms_SwapToDebug == true)
							{
								pauseMenuList->stringID = 415;
								pauseMenuList->function = 0x1AAE80;
							}
							else
							{
								pauseMenuList->stringID = 420;
								pauseMenuList->function = 0x1AA6F0;
							}
						}
					}
					if (MiscOptions[m_nCurrentPos].func)
						MiscOptions[m_nCurrentPos].func();
					break;
				case MENU_GAME:
					if (GameOptions[m_nCurrentPos].toggle)
					{
						*GameOptions[m_nCurrentPos].toggle = !*GameOptions[m_nCurrentPos].toggle;
					}
					if (GameOptions[m_nCurrentPos].func)
						GameOptions[m_nCurrentPos].func();
					break;
				case MENU_ENEMY_SPAWNER:
					if (SpawnerOptions[m_nCurrentPos].toggle)
					{
						*SpawnerOptions[m_nCurrentPos].toggle += 1;
						if (*SpawnerOptions[m_nCurrentPos].toggle > 90)
							*SpawnerOptions[m_nCurrentPos].toggle = 0;
					}
					if (SpawnerOptions[m_nCurrentPos].func)
						SpawnerOptions[m_nCurrentPos].func();
					break;
				default:
					break;
				}
			}
		}
		if (buttons & PAD_CIRCLE)
		{
			switch (m_nCurrentMenuOpen)
			{
			case MENU_ENEMY_SPAWNER:
				if (SpawnerOptions[m_nCurrentPos].toggle)
				{
					*SpawnerOptions[m_nCurrentPos].toggle -= 1;
					if (*SpawnerOptions[m_nCurrentPos].toggle < 0)
						*SpawnerOptions[m_nCurrentPos].toggle = 90;
				}
				break;
			default:
				break;
			}
		}
		int total = TOTAL_MENUS;

		if (m_nCurrentMenuOpen == MENU_CAMERA)
			total = sizeof(CameraOptions) / sizeof(CameraOptions[0]);
		else if (m_nCurrentMenuOpen == MENU_MISC)
			total = sizeof(MiscOptions) / sizeof(MiscOptions[0]);
		else if (m_nCurrentMenuOpen == MENU_GAME)
			total = sizeof(GameOptions) / sizeof(GameOptions[0]);
		else if (m_nCurrentMenuOpen == MENU_ENEMY_SPAWNER)
			total = sizeof(SpawnerOptions) / sizeof(SpawnerOptions[0]);
		if (m_nCurrentPos + 1 > total) m_nCurrentPos = 0;
		if (m_nCurrentPos < 0) m_nCurrentPos = total - 1;
	}

	
}

bool key_pressed(int vKey)
{
	return GetAsyncKeyState(vKey);
}

void set_mode_sp()
{
	SetGameType(0);
}

void set_mode_coop()
{
	SetGameType(1);
}

void set_mode_vs()
{
	SetGameType(2);
}

void set_mode_practice()
{
	SetGameType(3);
}

void open_debug_menu()
{
	ms_MenuActive = false;
	((void(*)(int))0x1A8788)(MENU_ITEM_PTR);
}

void toggle_freeze_world()
{
	if (GetTickCounter() - m_nTimer <= 3) return;
	m_nTimer = GetTickCounter();

	ms_FreezeWorld = !ms_FreezeWorld;

	if (ms_FreezeWorld)
		*(int*)0x515E04 = 1;
	else
		*(int*)0x515E04 = 0;
}

void toggle_free_camera()
{
	if (GetTickCounter() - m_nTimer <= 3) return;
	m_nTimer = GetTickCounter();

	ms_FreeCamera = !ms_FreeCamera;

	if (ms_FreeCamera == true)
		activate_freecam();
	else
		restore_freecam();
}

void add_fov()
{
	*(float*)0x4F4D4C += 10.0f;
}

void dec_fov()
{
	*(float*)0x4F4D4C -= 10.0f;
}

void reset_fov()
{
	*(float*)0x4F4D4C= 700.0f;
}

void reset_enemies()
{
	*(int*)0x515DE0 = 0;
	*(int*)0x515DE4 = 0;
	*(int*)0x515DE8 = 0;
	*(int*)0x515DEC = 0;

	*(int*)0x515DF0 = 0;
	*(int*)0x515DF4 = 0;
	*(int*)0x515DF8 = 0;
	*(int*)0x515DFC = 0;
}

void spawn_enemies()
{
	((int(*)(void))0x308010)();
	ms_MenuActive = false;
}

void hook_player_control(int a0, int a1)
{
	if (ms_MenuActive)
		return;

	((void(*)(int, int))0x1EAF30)(a0, a1);
}


void swap_p2_to_p1()
{
	//mdl p1_object = *(mdl*)0x5E6B40;
	//mdl p2_object = *(mdl*)0x5E9F00;
	//set_mode_coop();
	//*(mdl*)0x5E9F00 = p1_object;
	//*(mdl*)0x5E6B40 = p2_object;
	//set_mode_sp();
}
