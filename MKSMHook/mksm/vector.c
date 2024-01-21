#include "vector.h"


void vector_set(vector* left, vector* right)
{
	left->x = right->x;
	left->y = right->y;
	left->z = right->z;
}

void vector_add(vector* left, vector* right)
{
	left->x += right->x;
	left->y += right->y;
	left->z += right->z;
}

void vector_sub(vector* left, vector* right)
{
	left->x -= right->x;
	left->y -= right->y;
	left->z -= right->z;
}

void vector_add_flt(vector* left, float value)
{
	left->x += value;
	left->y += value;
	left->z += value;
}

void vector_mult(vector* left, vector* right)
{
	left->x *= right->x;
	left->y *= right->y;
	left->z *= right->z;
}

void vector_mult_flt(vector* left, float value)
{
	left->x *= value;
	left->y *= value;
	left->z *= value;
}
