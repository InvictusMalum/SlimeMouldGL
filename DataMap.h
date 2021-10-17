#pragma once

#ifndef DATAMAP_H
#define DATAMAP_H

#include"Vector2.h"
#include"Vector3.h"

using namespace std;

class DataMap
{
public:
	static Vector3** map;
	
	static int diffuseSize;
	static double decayFactor;

	static double minValue;

	static void StartUp(int SQUARES_WIDTH, int SQUARES_HEIGHT);
	static void Diffuse();
	static void Decay();
	static void Draw();
};

#endif