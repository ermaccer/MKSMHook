#include "actorManager.h"

int ActorManager_GetPlayerActor(int id)
{
	return ((int(*)(int, int))0x289730)(gActorManager, id);
}
