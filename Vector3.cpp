#include<iostream>
#include<math.h>
#include <tuple>
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

Vector3::Vector3(float num)
{
	x = num;
	y = num;
	z = num;
};

void Vector3::SetValues(std::tuple<float, float, float> tuple)
{
	x = std::get<0>(tuple);
	y = std::get<1>(tuple);
	z = std::get<2>(tuple);
}

std::tuple<float, float, float> Vector3::GetValues()
{
	return std::make_tuple(x, y, z);
}

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

bool Vector3::Equals(Vector3 other)
{
	if (x == other.x && y == other.y && z == other.z)
	{
		return true;
	}
	return false;
}