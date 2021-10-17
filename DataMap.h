#pragma once

#ifndef DATAMAP_H
#define DATAMAP_H

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

#include"DrawingData.h"

#include"Vector2.h"
#include"Vector3.h"

using namespace std;

class DataMap
{
public:
	int SQUARES_WIDTH;
	int SQUARES_HEIGHT;

	int VERTS_WIDTH;
	int VERTS_HEIGHT;

	Vector3** map;
	Vector3** old;
	
	int diffuseSize = 2;
	double decayFactor = .85;

	double minValue = 0.05;

	DataMap();
	DataMap(int SQUARES_WIDTH_, int SQUARES_HEIGHT_);
	
	void GenerateVertices();

	
	
	void Diffuse();
	void Decay();
	

	GLfloat* vertices = NULL;
	VBO VBO;
	DrawingData mainMesh = NULL;

	void MapToInd();

	void GenerateShaders();
	void Draw();
	void ShaderClean();


};

#endif