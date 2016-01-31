#include "Context.h"

LucidEngine::Context::Context() 
{
	if (!glfwInit())
		throw 1;

	WindowContext = glfwCreateWindow(Width, Height, Title, NULL, NULL);
	if (!WindowContext)
	{
		glfwTerminate();
		throw 2;
	}
}

LucidEngine::Context::Context(int width, int height, char * title)
{
	Width = width;
	Height = height;
	Title = title;

	if (!glfwInit())
		throw 1;

	WindowContext = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!WindowContext)
	{
		glfwTerminate();
		throw 2;
	}
}

LucidEngine::Context::~Context()
{
	delete Title;
	Title = nullptr;
	WindowContext = nullptr;
}

void LucidEngine::Context::OpenWindow()
{
	glfwMakeContextCurrent(WindowContext);
	
	GLenum err = glewInit();

	if (err != GLEW_OK)
		throw 3;

	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	while (!glfwWindowShouldClose(WindowContext))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */

		glfwSwapBuffers(WindowContext);
		glfwPollEvents();
	}

	glfwDestroyWindow(WindowContext);

	glfwTerminate();
}

void LucidEngine::Context::SetDimensions(int width, int height)
{
	Width = width;
	Height = height;
}

void LucidEngine::Context::SetTitle(char * title)
{
	Title = title;
}

int LucidEngine::Context::GetHeight()
{
	return Height;
}

int LucidEngine::Context::GetWidth()
{
	return Width;
}

char * LucidEngine::Context::GetTitle()
{
	return Title;
}