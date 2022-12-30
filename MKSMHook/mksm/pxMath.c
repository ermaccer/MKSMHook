#include "pxMath.h"

void pxMath_QuaternionToEuler(vector* v, quat* q)
{
	((void(*)(vector*, quat*))0x32E178)(v, q);
}

void pxMath_QuaternionToMatrix(quat* q, matrix* m)
{
	((void(*)(quat*, matrix*))0x32E3F8)(q, m);
}
