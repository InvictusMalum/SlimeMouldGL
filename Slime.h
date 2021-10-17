#pragma once

#ifndef SLIME_H
#define SLIME_H

#include"Vector2.h"
#include"Vector3.h"
#include"DataMap.h"
#include<list>
#include<math.h>

using namespace std;

class Slime
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static int SQUARES_WIDTH;
	static int SQUARES_HEIGHT;
	static list<Slime> AllSlimes;
	static DataMap map;
	static void UpdateAll();
	static bool SensorOut(Vector2 sensor);
	float GetPowerAtPosition(Vector2 position);

	Vector2 position = Vector2();
	Vector2 vector = Vector2();
	float speed = 0;
	
	float sensorAngle = 22.5;
	float sensorDistance = 20;
	float turnPerStep = 10;

	int drawRadius = 1;

	Vector2 leftSensorVec;
	Vector2 rightSensorVec;

	Vector2 vectorLeft;
	Vector2 vectorRight;

	Vector2 sensor0;
	Vector2 sensor1;
	Vector2 sensor2;

	Vector3 color = Vector3(1);
	
	int speedMin = 1;
	int speedMax = 10;

	int colorThreshold = 20;

	int turningAwayFromWall = NULL;


	Slime(Vector2 position_, Vector2 vector_, float speed_);

	void Update();
	
	void GetSensorCoords();
	void Sense();

	void TurnLeft();
	void TurnRight();

	void Trail();
	void Move();

	void WallCollision();
	void WallTeleport();

	
	//static void AddSlime(Slime s);
	//static void UpdateAll();
	//static void DrawAll();
};

#endif