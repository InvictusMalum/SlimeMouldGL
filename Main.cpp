#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"glfwClass.h"

#include"Slime.h"
#include"DataMap.h"
#include"Vector2.h"
#include"Vector3.h"


using namespace std;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

const int SQUARES_WIDTH = 150;
const int SQUARES_HEIGHT = 100;


int main()
{

	GLFWwindow* window = GLFWClass::StartUp(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (window == NULL)
	{
		return -1;
	}

	// Main while loop until window should close
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Update Screen
		// Swap back and front buffers
		glfwSwapBuffers(window);
		// Get and process events
		glfwPollEvents();

	}

	// End program
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}