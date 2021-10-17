#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"glfwClass.h"

#include"Slime.h"
#include"DataMap.h"
#include"Vector2.h"
#include"Vector3.h"


using namespace std;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;

const int SQUARES_WIDTH = 360;
const int SQUARES_HEIGHT = 360;

DataMap dM(SQUARES_WIDTH, SQUARES_HEIGHT);


int main()
{
	Slime::map = dM;
	Slime::SCREEN_WIDTH = SCREEN_WIDTH;
	Slime::SCREEN_HEIGHT = SCREEN_HEIGHT;
	Slime::SQUARES_WIDTH = SQUARES_WIDTH;
	Slime::SQUARES_HEIGHT = SQUARES_HEIGHT;

	for (int i = 0; i < 1; i++)
	{
		Slime s(Vector2(20, 20), Vector2(1, 0), 3);
	}
	Slime::UpdateAll();


	GLFWwindow* window = GLFWClass::StartUp(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (window == NULL)
	{
		return -1;
	}

	dM.GenerateVertices();

	dM.GenerateShaders();

	// Main while loop until window should close
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Slime::UpdateAll();
		Slime::map.MapToInd();
		Slime::map.GenerateShaders();
		Slime::map.Draw();
		Slime::map.Diffuse();
		Slime::map.Decay();


		// Update Screen
		// Swap back and front buffers
		glfwSwapBuffers(window);
		// Get and process events
		glfwPollEvents();
	}

	dM.ShaderClean();

	// End program
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}