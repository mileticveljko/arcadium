#ifndef TEXTURE_H__
#define TEXTUER_H__

#include <string>

namespace ar
{
	class Texture
	{
	public:
		Texture(const std::string& path);
		Texture(unsigned char* data, int width, int height, int nrChannels);
		~Texture();

		void Bind(unsigned int slot = 0);
		void Unbind();

		unsigned int GetID() const { return m_ID; }
	private:
		unsigned int m_ID;
	};
}

#endif