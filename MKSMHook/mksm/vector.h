#pragma once

typedef struct {
	float x;
	float y;
	float z;
}vector;


typedef struct {
	float M[4][4];
}matrix;


typedef struct {
	float x, y, z, w;
}quat;


inline void vector_set(vector* left, vector* right)
{
	left->x = right->x;
	left->y = right->y;
	left->z = right->z;
}

inline void vector_add(vector* left, vector* right)
{
	left->x += right->x;
	left->y += right->y;
	left->z += right->z;
}

inline void vector_sub(vector* left, vector* right)
{
	left->x -= right->x;
	left->y -= right->y;
	left->z -= right->z;
}

inline void vector_add_flt(vector* left, float value)
{
	left->x += value;
	left->y += value;
	left->z += value;
}

inline void vector_mult(vector* left, vector* right)
{
	left->x *= right->x;
	left->y *= right->y;
	left->z *= right->z;
}

inline void vector_mult_flt(vector* left, float value)
{
	left->x *= value;
	left->y *= value;
	left->z *= value;
}
