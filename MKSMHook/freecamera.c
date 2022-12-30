#include "freecamera.h"
#include "mips.h"
#include "ps2mem.h"
#include "mouse.h"
#include "mksm/pxMath.h"
#include "menu.h"

char buff[512];

vector camPos = {};
vector camRot = {};

// 214688 
void activate_freecam()
{
	*(int*)0x511378 = 1;
	makeJal(0x36F4A4, process_freecam);
	//makeJal(0x36F4A8, process_freecam);
	// position
	//makeJal(0x36F4B4, process_freecam);
	//NOP(0x36F4B4);

	NOP(0x36F4D4);
	NOP(0x36F4DC);
	NOP(0x36F4E0);

	// rotation
	NOP(0x36F4E4);
	NOP(0x36F4F8);
	NOP(0x36F4FC);
	NOP(0x36F500);

}

void restore_freecam()
{
	*(int*)0x511378 = 0;
	patchInt(0x36F4A4, jalr(v1));
	//NOP(0x36F4A8);

	// position
	patchInt(0x36F4B4, jal(0x214688));
	patchInt(0x36F4D4, 0xE6010080);
	patchInt(0x36F4DC, 0xE6020084);
	patchInt(0x36F4E0, 0xE6000088);

	// rotation
	patchInt(0x36F4E4, jal(0x214688));
	patchInt(0x36F4F8, 0xE6010090);
	patchInt(0x36F4FC, 0xE6000098);
	patchInt(0x36F500, 0xE6020094);
}

void process_freecam()
{
	if (ms_FreeCamera)
	{
		freecamera_control();
		set_camera_position(&camPos);
		set_camera_rotation(&camRot);
	}

}

void freecamera_control()
{
	Camera* cam = CameraManager_GetCurrentCamera();
	matrix* camMat = ((matrix* (*)(void))0x224E28)();
	matrix m = *camMat;

	static float camSpeed = 25.0f;

	if (GetAsyncKeyState(90))
		camSpeed = 50.0f;
	else
		camSpeed = 25.0f;


	vector forward = { m.M[2][0], m.M[2][1], m.M[2][2] };
	vector up = { m.M[1][0], m.M[1][1], m.M[1][2] };
	vector right = { m.M[0][0], m.M[0][1], m.M[0][2] };
	vector u = { m.M[3][0], m.M[3][1], m.M[3][2] };

#ifdef DEBUG
	_sprintf(buff, "FORWARD %f %f %f\n", forward.x, forward.y, forward.z);
	_printf(buff);
	_sprintf(buff, "RIGHT %f %f %f\n", right.x, right.y, right.z);
	_printf(buff);
	_sprintf(buff, "UP %f %f %f\n", up.x, up.y, up.z);
	_printf(buff);
	_sprintf(buff, "POS %f %f %f\n", u.x, u.y, u.z);
	_printf(buff);
#endif // _DEBUG



	if (ms_FreeCameraAbsoluteControls == true)
	{
		if (GetAsyncKeyState(87))
		{
			camPos.z += camSpeed;
		}
		if (GetAsyncKeyState(83))
		{
			camPos.z -= camSpeed;
		}

		if (GetAsyncKeyState(65))
		{
			camPos.x -= camSpeed;
		}
		if (GetAsyncKeyState(68))
		{
			camPos.x += camSpeed;
		}
	}
	else
	{
		if (GetAsyncKeyState(87))
		{
			camPos.x -= forward.x * camSpeed;
			camPos.y -= forward.y * camSpeed;
			camPos.z -= forward.z * camSpeed;
		}
		if (GetAsyncKeyState(83))
		{
			vector mult = forward;
			vector_mult_flt(&mult, camSpeed);
			vector_sub(&camPos, &mult);
		}

		if (GetAsyncKeyState(65))
		{
			vector mult = right;
			vector_mult_flt(&mult, camSpeed);
			vector_sub(&camPos, &mult);
		}
		if (GetAsyncKeyState(68))
		{
			vector mult = right;
			vector_mult_flt(&mult, camSpeed);
			vector_add(&camPos, &mult);
		}

	}

	if (GetAsyncKeyState(81))
		camPos.y += camSpeed;
	if (GetAsyncKeyState(69))
		camPos.y -= camSpeed;

	if (GetAsyncKeyState(37))
		camRot.y -= camSpeed;
	if (GetAsyncKeyState(39))
		camRot.y += camSpeed;

	if (GetAsyncKeyState(38))
		camRot.x += camSpeed;
	if (GetAsyncKeyState(40))
		camRot.x -= camSpeed;

	if (GetAsyncKeyState(88))
		camRot.z -= camSpeed;
	if (GetAsyncKeyState(67))
		camRot.z += camSpeed;
}

void set_camera_position(vector* pos)
{
	Camera* cam = CameraManager_GetCurrentCamera();
	cam->pos = *pos;
	*(float*)0x6CBAD0 = pos->x;
	*(float*)0x6CBAD4 = pos->y;
	*(float*)0x6CBAD8 = pos->z;
}

void set_camera_rotation(vector* rot)
{
	Camera* cam = CameraManager_GetCurrentCamera();
	cam->rot = *rot;
	*(float*)0x6CBAE0 = rot->x;
	*(float*)0x6CBAE4 = rot->y;
	*(float*)0x6CBAE8 = rot->z;
}
