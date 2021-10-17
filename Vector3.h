#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

#include <tuple>

using namespace std;

class Vector3
{
public:
	Vector3();
	Vector3(float x_, float y_, float z_);
	Vector3(float num);

	void SetValues(std::tuple<float, float, float> tuple);
	std::tuple<float, float, float> GetValues();

	void Add(Vector3 other);

	void Subtract(Vector3 other);

	void ScalarMultiply(float s);

	float Magnitude();

	void Normalize();

	bool Equals(Vector3 other);

	float x;
	float y;
	float z;
};

#endif