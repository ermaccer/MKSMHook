#include "camera.h"

int GetCameraManager()
{
    return ((int(*)(void))0x143B18)();
}

Camera* CameraManager_GetCurrentCamera()
{
   int mgr = GetCameraManager();
   if (!mgr)
       return 0;

   return ((Camera*(*)(int))0x36F570)(mgr);
}

void BaseCamera_CalculateCameraRotationMatrix(Camera* camera)
{
    ((void(*)(Camera*))0x36D6C8)(camera);
}

void SetCameraFOV(float value)
{
    *(float*)0x4F4D4C = value;
}
