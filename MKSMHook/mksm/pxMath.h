#pragma once
#include "vector.h"

void pxMath_QuaternionToEuler(vector* v, quat* q);
void pxMath_QuaternionToMatrix(quat* q, matrix* m);