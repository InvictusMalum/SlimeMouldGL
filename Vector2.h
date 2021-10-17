#pragma once

#ifndef VECTOR2_H
#define VECTOR2_H

using namespace std;

class Vector2
{
public:
	Vector2();
	Vector2(float x_, float y_);

	void Add(Vector2 other);

	void Subtract(Vector2 other);

	void ScalarMultiply(float s);

	float Magnitude();

	void Normalize();
	void NormalizeTo(float length);

	Vector2 GetRotatedOverVec(Vector2 other);

	Vector2 Duplicate();
	
	float x;
	float y;
};

#endif