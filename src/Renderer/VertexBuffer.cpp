#include "VertexBuffer.h"

#include <glad/glad.h>

namespace ar
{
    unsigned int VertexBufferElement::GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
        }
        return 0;
    }

    void VertexBufferLayout::Push(unsigned int type, unsigned int count)
    {
        m_Elements.push_back({ type, count, GL_FALSE });
        m_Stride += count * VertexBufferElement::GetSizeOfType(type);
    }

	VertexBuffer::VertexBuffer(float* vertices, unsigned int size)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}