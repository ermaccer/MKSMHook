#pragma once
#include "vector.h"

typedef struct {
	void* vTable; //0
	char  pad[28]; // 4
	matrix mat; // 32
	char _pad[144]; // 96
	vector unkVec;
	char __pad[4];
	vector unkVec_2;
	char ___pad[4];
	char ____pad[48];
	vector pos;
	char _____pad[4];
	vector rot;
	char ______pad[4];
	quat rotQuat;
}Camera;


int GetCameraManager();
Camera* CameraManager_GetCurrentCamera();
void BaseCamera_CalculateCameraRotationMatrix(Camera* camera);

void SetCameraFOV(float value);
