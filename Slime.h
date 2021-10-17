#pragma once

#ifndef SLIME_H
#define SLIME_H

#include"Vector2.h"
#include"Vector3.h"

using namespace std;

class Slime
{
public:
	Vector2 position;
	Vector2 vector;

	Vector3 color;
	
	int speedMin = 1;
	int speedMax = 10;

	int colorThreshold = 20;

	Slime(Vector2 position, Vector2 vector);
	void Update();
	
	void GetSensorCoords();
	static bool SensorOut(Vector2 sensorCoord);
	void Sense();

	void TurnLeft();
	void TurnRight();

	void Trail();
	void Move();

	void WallCollision();
	void WallTeleport();

	void Draw();

	static Slime* AllSlimes;
	static void AddSlime(Slime s);
	static void UpdateAll();
	static void DrawAll();


};

#endif