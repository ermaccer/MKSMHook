#pragma once
#include "mksm/mksm.h"


/* PS2 CONTROL SCHEME
D-Pad - movement
Butttons - rotation
L1/R1 - up/down
L2/R2 - tilt
SELECT - speed up
*/

extern vector camPos;
extern vector camRot;

void activate_freecam();
void restore_freecam();

void process_freecam();
void freecamera_control();

void set_camera_position(vector* pos);
void set_camera_rotation(vector* rot);