#ifndef SHADER_H__
#define SHADER_H__

#include <string>
#include <glm/glm.hpp>

namespace ar
{

	class Shader
	{
	public:
		Shader(const std::string& vertex, const std::string& fragment);
		Shader(const std::string& filepath);
		~Shader();

		void Bind();
		void Unbind();

		void UploadUniformInt(const std::string& name, int i);
		void UploadUniformInt2(const std::string& name, int v1, int v2);
		void UploadUniformInt3(const std::string& name, int v1, int v2, int v3);
		void UploadUniformInt4(const std::string& name, int v1, int v2, int v3, int v4);

		void UploadUniformUInt(const std::string& name, unsigned int i);
		void UploadUniformUInt2(const std::string& name, unsigned int v1, unsigned int v2);
		void UploadUniformUInt3(const std::string& name, unsigned int v1, unsigned int v2, unsigned int v3);
		void UploadUniformUInt4(const std::string& name, unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4);

		void UploadUniformFloat(const std::string& name, float f);
		void UploadUniformFloat2(const std::string& name, float v1, float v2);
		void UploadUniformFloat3(const std::string& name, float v1, float v2, float v3);
		void UploadUniformFloat4(const std::string& name, float v1, float v2, float v3, float v4);
    
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		unsigned int ShaderTypeFromString(const std::string& type);
	
    private:
		unsigned int m_ID;
	};
}

#endif