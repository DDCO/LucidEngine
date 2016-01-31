#pragma once

#include <GL\glew.h>
#include <GL\GL.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace LucidEngine
{
	class Shader
	{
	public:
		GLuint Load(char * filename, GLenum type);
		void Unload(GLuint id);
	private:

	};
}