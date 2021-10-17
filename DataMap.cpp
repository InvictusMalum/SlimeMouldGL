#include<iostream>
#include"Slime.h"

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

#include"DrawingData.h"

#include"Vector2.h"
#include"Vector3.h"

#include"DataMap.h"

DataMap::DataMap()
{

}

DataMap::DataMap(int SQUARES_WIDTH_, int SQUARES_HEIGHT_)
{
	SQUARES_WIDTH = SQUARES_WIDTH_;
	SQUARES_HEIGHT = SQUARES_HEIGHT_;

	VERTS_WIDTH = SQUARES_WIDTH + 1;
	VERTS_HEIGHT = SQUARES_HEIGHT + 1;

	map = new Vector3 * [SQUARES_HEIGHT];
	for (int i = 0; i < SQUARES_HEIGHT; i++)
	{
		map[i] = new Vector3[SQUARES_WIDTH];
	}

	old = new Vector3 * [SQUARES_HEIGHT];
	for (int i = 0; i < SQUARES_HEIGHT; i++)
	{
		old[i] = new Vector3[SQUARES_WIDTH];
	}

	vertices = new GLfloat[(int64_t)VERTS_WIDTH * VERTS_HEIGHT * 6];
	mainMesh = DrawingData((int64_t)VERTS_WIDTH * VERTS_HEIGHT * 6);
}

void DataMap::GenerateVertices()
{
	for (int i = 0; i < VERTS_HEIGHT; i++)
	{
		for (int j = 0; j < VERTS_WIDTH; j++)
		{
			*(vertices + ((int64_t)i * VERTS_WIDTH + j) * 3) = (GLfloat)(j) / (VERTS_WIDTH - 1) * 2 - 1;
			*(vertices + ((int64_t)i * VERTS_WIDTH + j) * 3 + 1) = -((GLfloat)(i) / (VERTS_HEIGHT - 1) * 2 - 1);
			*(vertices + ((int64_t)i * VERTS_WIDTH + j) * 3 + 2) = 0;
		}
	}
}

void DataMap::Diffuse()
{
	for (int i = 0; i < SQUARES_HEIGHT; i++)
	{
		for (int j = 0; j < SQUARES_WIDTH; j++)
		{
			old[i][j].SetValues(map[i][j].GetValues());
		}
	}

	for (int iKernelCenter = 0; iKernelCenter < SQUARES_HEIGHT; iKernelCenter++)
	{
		for (int jKernelCenter = 0; jKernelCenter < SQUARES_WIDTH; jKernelCenter++)
		{
			Vector3 total;
			for (int i = iKernelCenter - diffuseSize + 1; i < iKernelCenter + diffuseSize; i++)
			{
				for (int j = jKernelCenter - diffuseSize + 1; j < jKernelCenter + diffuseSize; j++)
				{
					if (i > 0 && i < SQUARES_HEIGHT && j>0 && j < SQUARES_WIDTH)
					{
						total.Add(old[i][j]);
					}
				}
			}
			total.ScalarMultiply(1.0f/9.0f);
			map[iKernelCenter][jKernelCenter].SetValues(total.GetValues());
		}
	}

}
void DataMap::Decay()
{
	for (int i = 0; i < SQUARES_HEIGHT; i++)
	{
		for (int j = 0; j < SQUARES_WIDTH; j++)
		{
			if (map[i][j].x + map[i][j].y + map[i][j].z < minValue)
			{
				map[i][j].SetValues(std::make_tuple(0.0f, 0.0f, 0.0f));
			}
			else
			{
				map[i][j].ScalarMultiply(decayFactor);
			}
		}
	}
}

void DataMap::MapToInd()
{
	mainMesh.Reset();
	for (int i = 0; i < SQUARES_HEIGHT; i++)
	{
		for (int j = 0; j < SQUARES_WIDTH; j++)
		{
			if (map[i][j].x > .6)
			{
				mainMesh.AddIndex(i * VERTS_WIDTH + j);
				mainMesh.AddIndex(i * VERTS_WIDTH + j + 1);
				mainMesh.AddIndex(i * VERTS_WIDTH + j + VERTS_WIDTH + 1);

				mainMesh.AddIndex(i * VERTS_WIDTH + j);
				mainMesh.AddIndex(i * VERTS_WIDTH + j + VERTS_WIDTH + 1);
				mainMesh.AddIndex(i * VERTS_WIDTH + j + VERTS_WIDTH);
			}
		}
	}
}

void DataMap::GenerateShaders()
{
	// Generates Vertex Buffer Object and links it to vertices
	VBO.Generate(vertices, (int64_t)VERTS_WIDTH * VERTS_HEIGHT * 3 * sizeof(*vertices));

	mainMesh.Generate(VBO, "default.vert", "black.frag", sizeof(*vertices));

	VBO.Unbind();
	VBO.Delete();
}

void DataMap::Draw()
{
	mainMesh.shaderProgram.Activate();
	mainMesh.VAO.Bind();
	glDrawElements(GL_TRIANGLES, mainMesh.numVerts, GL_UNSIGNED_INT, 0);
}

void DataMap::ShaderClean()
{
	// Clean up, delete objects created
	VBO.Delete();
	mainMesh.ShaderClean();
}