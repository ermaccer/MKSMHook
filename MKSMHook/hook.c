#include "hook.h"
#include "mouse.h"
#include <stdio.h>
#include "types.h"
#include "freecamera.h"

void process_hook_in_game()
{
	int buttons = PxPad_GetButtons(0);

	if (buttons & PAD_L3)
	{
		ms_MenuActive = !ms_MenuActive;
	}

#ifndef PS2_BUILD
	if (GetAsyncKeyState(72))
		toggle_freeze_world();

	if (GetAsyncKeyState(71))
		toggle_free_camera();
#endif

	Camera* cam = CameraManager_GetCurrentCamera();
	if (cam)
	{
		if (ms_FreeCamera == false)
		{
			camPos.x = cam->pos.x;
			camPos.y = cam->pos.y;
			camPos.z = cam->pos.z;
			camRot.x = cam->rot.x;
			camRot.y = cam->rot.y;
			camRot.z = cam->rot.z;
		}
	}
	menu_update();
	menu_draw();
}