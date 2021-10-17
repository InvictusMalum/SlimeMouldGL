#include<iostream>
#include"Slime.h"
#include"Vector2.h"
#include"Vector3.h"
#include"DataMap.h"

void DataMap::StartUp(int SQUARES_WIDTH, int SQUARES_HEIGHT)
{
	Vector3** temp = new Vector3 * [SQUARES_HEIGHT];
	for (int i = 0; i < SQUARES_HEIGHT; i++)
	{
		temp[i] = new Vector3[SQUARES_WIDTH];
	}
	map = temp;
}

void DataMap::Diffuse()
{

}
void DataMap::Decay()
{

}
void DataMap::Draw()
{

}