#include "VertexArrayObject.h"

#include <glad/glad.h>

namespace ar
{
	VertexArrayObject::VertexArrayObject()
	{
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
	}
	VertexArrayObject::~VertexArrayObject()
	{
		glDeleteVertexArrays(1, &m_ID);
	}
	void VertexArrayObject::Bind()
	{
		glBindVertexArray(m_ID);
	}
	void VertexArrayObject::Unbind()
	{
		glBindVertexArray(0);
	}
	void VertexArrayObject::AddVertexBuffer(std::unique_ptr<ar::VertexBuffer> VB,
        std::unique_ptr<ar::VertexBufferLayout> layout)
	{
		Bind();
		VB->Bind();
		const auto& elements = layout->GetElements();
		unsigned int offset = 0;
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, element.count, element.type,
			element.normalized, layout->GetStride(), (const void*)offset);
			offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
		}
        Unbind();
        VB->Unbind();
	}
	void VertexArrayObject::AddIndexBuffer(std::unique_ptr<ar::IndexBuffer> IB)
	{
		Bind();
		IB->Bind();
        Unbind();
        IB->Unbind();

        m_Count = IB->GetCount();
	}
}