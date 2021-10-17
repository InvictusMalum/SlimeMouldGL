#include<iostream>
#include<cstdlib>
#include<ctime>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"glfwClass.h"

#include"Slime.h"
#include"DataMap.h"
#include"Vector2.h"
#include"Vector3.h"


using namespace std;

const int SCREEN_WIDTH = 90;
const int SCREEN_HEIGHT = 90;

const int SQUARES_WIDTH = 89;
const int SQUARES_HEIGHT = 89;

DataMap dM(SQUARES_WIDTH, SQUARES_HEIGHT);


int main()
{
	Slime::map = dM;
	Slime::SCREEN_WIDTH = SCREEN_WIDTH;
	Slime::SCREEN_HEIGHT = SCREEN_HEIGHT;
	Slime::SQUARES_WIDTH = SQUARES_WIDTH;
	Slime::SQUARES_HEIGHT = SQUARES_HEIGHT;
	std::srand(std::time(nullptr));
	
	float slimePercent = .07;
	int slimes = slimePercent * SQUARES_HEIGHT * SQUARES_WIDTH;
	for (int i = 0; i < 600; i++)
	{
		int angle = std::rand() / ((RAND_MAX + 1u) / 360);
		Slime s(Vector2(5 + std::rand() /((RAND_MAX + 1u) / (SCREEN_WIDTH-10)), 
					5+ std::rand() / ((RAND_MAX + 1u) / (SCREEN_HEIGHT - 10))), 
			Vector2(cos(3.1415 * angle / 180), 
					sin(3.1415*angle/180)),
			3);
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
		Slime::map.Diffuse();
		Slime::map.Decay();
		Slime::map.MapToInd();
		Slime::map.GenerateShaders();
		Slime::map.Draw();

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