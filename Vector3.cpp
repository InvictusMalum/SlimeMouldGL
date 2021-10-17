#include<iostream>
#include<math.h>
#include"Vector3.h"

using namespace std;

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
};

Vector3::Vector3(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
};

void Vector3::Add(Vector3 other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

void Vector3::Subtract(Vector3 other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

void Vector3::ScalarMultiply(float s)
{
	x *= s;
	y *= s;
	z *= s;
}

float Vector3::Magnitude()
{
	return (float)sqrt((int64_t)x * (int64_t)x + (int64_t)y * (int64_t)y + (int64_t)z * (int64_t)z);
}

void Vector3::Normalize()
{
	ScalarMultiply(1 / Magnitude());
}
