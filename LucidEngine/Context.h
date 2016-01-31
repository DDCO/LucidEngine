#pragma once

#include <GL\glew.h>
#include <GL\GL.h>
#include <GLFW\glfw3.h>

namespace LucidEngine
{
	typedef void(*MainLoopCallback)();

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
		void OpenWindow(MainLoopCallback callback = NULL);
		~Context();
	private:
		GLFWwindow * WindowContext;
		int Width;
		int Height;
		char * Title;
	};
}