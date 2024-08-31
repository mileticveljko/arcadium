#include "IndexBuffer.h"

#include <glad/glad.h>

namespace ar
{
	IndexBuffer::IndexBuffer(unsigned int* indices, unsigned int size)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

		m_Count = size / sizeof(unsigned int);
	}
	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}
	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}
	void IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}