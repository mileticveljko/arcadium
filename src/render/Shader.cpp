#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <array>
#include <vector>

#include <glm/gtc/type_ptr.hpp>

namespace ar
{

	Shader::Shader(const std::string& vertex, const std::string& fragment)
	{
		int success;
		char infoLog[512];

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const GLchar* source = (const GLchar*)vertex.c_str();
        glShaderSource(vertexShader, 1, &source, 0);
        glCompileShader(vertexShader);
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPALATION_FAILED\n" <<
				infoLog << std::endl;
		}

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        source = (const GLchar*)fragment.c_str();
        glShaderSource(fragmentShader, 1, &source, 0);
        glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPALATION_FAILED\n" <<
				infoLog << std::endl;
		}

        m_ID = glCreateProgram();
        glAttachShader(m_ID, vertexShader);
        glAttachShader(m_ID, fragmentShader);
        glLinkProgram(m_ID);
		glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<
				infoLog << std::endl;

		}

        glDetachShader(m_ID, vertexShader);
        glDetachShader(m_ID, fragmentShader);
	}

    Shader::Shader(const std::string& filepath)
    {
		std::string source;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			source.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&source[0], source.size());
			in.close();
		}
		else
		{
			std::cout << "Could not open file: " << filepath << std::endl;
		}
		std::unordered_map<GLenum, std::string> shaderSources;
		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = source.find(typeToken, 0);
		while (pos != std::string::npos)
		{
			size_t eol = source.find_first_of("\r\n", pos);
			size_t begin = pos + typeTokenLength + 1;
			std::string type = source.substr(begin, eol - begin);

			size_t nextLinePos = source.find_first_not_of("\r\n", eol);
			pos = source.find(typeToken, nextLinePos);
			shaderSources[ShaderTypeFromString(type)] = source.substr(nextLinePos, pos - (nextLinePos == std::string::npos ? source.size() - 1 : nextLinePos));
		}

		GLuint program = glCreateProgram();
		std::array<GLenum, 2> glShaderIDs;
		int glShaderIDIndex = 0;
		for (auto& kv : shaderSources)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);

			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);

			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				char InfoLog[50];
				std::vector<GLchar> infoLog(maxLength);

				glGetShaderInfoLog(shader, maxLength, &maxLength, InfoLog);
				std::cout << "ERROR::SHADER\n" <<
					InfoLog << std::endl;

				glDeleteShader(shader);

				break;
			}

			glAttachShader(program, shader);
			glShaderIDs[glShaderIDIndex++] = shader;
		}

		m_ID = program;

		glLinkProgram(program);

		for (auto id : glShaderIDs)
			glDetachShader(program, id);
    }

	Shader::~Shader()
	{
        glDeleteProgram(m_ID);
	}

	void Shader::Bind()
	{
        glUseProgram(m_ID);
	}

	void Shader::Unbind()
	{
        glUseProgram(0);
	}

	unsigned int Shader::ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;

		std::cout << "Unknown shader type!" << std::endl;
		return 0;
	}

	void Shader::UploadUniformInt(const std::string& name, int i)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform1i(location, i);
	}

	void Shader::UploadUniformInt2(const std::string& name, int v1, int v2)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform2i(location, v1, v2);
	}

	void Shader::UploadUniformInt3(const std::string& name, int v1, int v2, int v3)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform3i(location, v1, v2, v3);
	}

	void Shader::UploadUniformInt4(const std::string& name, int v1, int v2, int v3, int v4)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform4i(location, v1, v2, v3, v4);
	}

	void Shader::UploadUniformUInt(const std::string& name, unsigned int i)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform1ui(location, i);
	}

	void Shader::UploadUniformUInt2(const std::string& name, unsigned int v1, unsigned int v2)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform2ui(location, v1, v2);
	}

	void Shader::UploadUniformUInt3(const std::string& name, unsigned int v1, unsigned int v2, unsigned int v3)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform3ui(location, v1, v2, v3);
	}

	void Shader::UploadUniformUInt4(const std::string& name, unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform4ui(location, v1, v2, v3, v4);
	}

	void Shader::UploadUniformFloat(const std::string& name, float f)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform1f(location, f);
	}

	void Shader::UploadUniformFloat2(const std::string& name, float v1, float v2)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform2f(location, v1, v2);
	}

	void Shader::UploadUniformFloat3(const std::string& name, float v1, float v2, float v3)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform3f(location, v1, v2, v3);
	}

	void Shader::UploadUniformFloat4(const std::string& name, float v1, float v2, float v3, float v4)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform4f(location, v1, v2, v3, v4);
	}

	void Shader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}