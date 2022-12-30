#pragma once
#include "mksm/mksm.h"

extern vector camPos;
extern vector camRot;

void activate_freecam();
void restore_freecam();

void process_freecam();
void freecamera_control();

void set_camera_position(vector* pos);
void set_camera_rotation(vector* rot);