#include "Shader.h"

GLuint LucidEngine::Shader::Load(char * filename, GLenum type)
{
	GLuint shaderID = glCreateShader(type); //GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER, GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER, GL_FRAGMENT_SHADER, or GL_COMPUTE_SHADER
	
	//read file (may need to use vector instead)
	FILE * fHandle = fopen(filename, "r");
	if (fHandle == NULL)
		return;
	GLchar line[255];
	GLchar * buffer[255];
	GLsizei count = 0;
	while (fgets(line, 255, fHandle) != NULL)
	{
		buffer[count] = line;
		count++;
	}

	glShaderSource(shaderID, count, buffer, NULL);
	glCompileShader(shaderID);

	//error handling
	GLint isCompiled;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);

		//We don't need the shader anymore.
		glDeleteShader(shaderID);

		//In this simple program, we'll just leave
		return;
	}
	//Link shader to program
}

void LucidEngine::Shader::Unload(GLuint id)
{
	glDeleteShader(id);
}