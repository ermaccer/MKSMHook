#include "hook.h"
#include "mouse.h"
#include <stdio.h>
#include "types.h"
#include "freecamera.h"

void process_hook_in_game()
{
	int buttons = PxPad_GetButtons(0);

	if (buttons & PAD_L3)
		ms_MenuActive = !ms_MenuActive;

	if (GetAsyncKeyState(72))
		toggle_freeze_world();

	if (GetAsyncKeyState(71))
		toggle_free_camera();

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

void hook_set_vector()
{
	static int a1, a2, _ra;

	asm volatile ("move %0, $ra" : "=r" (_ra));
	asm volatile ("move %0, $a1" : "=r" (a1));
	asm volatile ("move %0, $a0" : "=r" (a2));



	asm volatile ("move $ra, %0" : : "r" (_ra));
	asm volatile ("move $a1, %0" : : "r" (a1));
	asm volatile ("move $a0, %0" : : "r" (a2));

	asm volatile ("lq      $a2, 0($a1)");
	asm volatile ("sq      $a2, 0($a0)");


	asm volatile ("jr      $ra");
	asm volatile ("nop");
}
