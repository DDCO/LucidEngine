#pragma once

#include <GL\glew.h>
#include <GL\GL.h>
#include <GLFW\glfw3.h>

namespace LucidEngine
{
	class Context
	{
	public:
		Context();
		Context(int width, int height, char * title);
		int GetWidth();
		int GetHeight();
		void SetDimensions(int width, int height);
		void SetTitle(char * title);
		char * GetTitle();
		void OpenWindow();
		~Context();
	private:
		GLFWwindow * WindowContext;
		int Width;
		int Height;
		char * Title;
	};
}