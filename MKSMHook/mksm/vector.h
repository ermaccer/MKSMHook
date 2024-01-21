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


void vector_set(vector* left, vector* right);
void vector_add(vector* left, vector* right);
void vector_sub(vector* left, vector* right);
void vector_add_flt(vector* left, float value);
void vector_mult(vector* left, vector* right);
void vector_mult_flt(vector* left, float value);