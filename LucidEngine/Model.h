#pragma once

#include <GL\glew.h>
#include <GL\GL.h>

namespace LucidEngine
{
	class Model
	{
	public:
		GLuint ProgramID;
		Model(char * filename); //load mesh
		Model();
		~Model();

	private:

	};
}