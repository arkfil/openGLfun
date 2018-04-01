#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

typedef unsigned long DWORD;

// To use Nvidia Graphics Card
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}


int main(void)
{
	

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	/* Make the window's context current */
	glfwMakeContextCurrent(window);



	if (glewInit() != GLEW_OK) {
		std::cout << "Error" << std::endl;
	}
	else {
		printf("Renderer: %s\n", glGetString(GL_RENDERER));
		printf("OpenGL version supported %s\n", glGetString(GL_VERSION));
	}

	float positions[] = {	-0.5f, -0.5f,
							0.0f, 0.0f,
							0.5f, -0.5f		};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6* sizeof(float), positions, GL_STATIC_DRAW);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//NOTE:CODE HERE
		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}