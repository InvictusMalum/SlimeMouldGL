#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

using namespace std;

class Vector3
{
public:
	Vector3();
	Vector3(float x_, float y_, float z_);

	void Add(Vector3 other);

	void Subtract(Vector3 other);

	void ScalarMultiply(float s);

	float Magnitude();

	void Normalize();

	float x;
	float y;
	float z;
};

#endif