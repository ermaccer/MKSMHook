#include "object.h"

void Object_GetPos(int object, vector* pos)
{
	((int(*)(int, vector*))0x326188)(object, pos);
}
