#include<iostream>
#include<math.h>
#include"Vector2.h"

using namespace std;

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
};
	
Vector2::Vector2(float x_, float y_)
{
	x = x_;
	y = y_;
};

void Vector2::Add(Vector2 other)
{
	x += other.x;
	y += other.y;
}

void Vector2::Subtract(Vector2 other)
{
	x -= other.x;
	y -= other.y;
}

void Vector2::ScalarMultiply(float s)
{
	x *= s;
	y *= s;
}

float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}

void Vector2::Normalize()
{
	ScalarMultiply(1 / Magnitude());
}

Vector2 Vector2::GetRotatedOverVec(Vector2 other)
{
	float outx = x * other.x - y * other.y;
	float outy = x * other.y + y * other.x;
	return Vector2(outx, outy);
}

Vector2 Vector2::Duplicate()
{
	return Vector2(x, y);
}