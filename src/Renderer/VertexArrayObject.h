#ifndef VERTEX_ARRAY_OBJECT_H__
#define VERTEX_ARRAY_OBJECT_H__

#include <VertexBuffer.h>
#include <IndexBuffer.h>

#include <memory>

namespace ar
{
	class VertexArrayObject
	{
	public:
		VertexArrayObject();
		~VertexArrayObject();

		void Bind();
		void Unbind();

		void AddVertexBuffer(std::unique_ptr<ar::VertexBuffer>,
            std::unique_ptr<ar::VertexBufferLayout>);
		void AddIndexBuffer(std::unique_ptr<ar::IndexBuffer>);

        inline unsigned int GetNumberOfElements() const { return m_Count; }
	private:
		unsigned int m_ID;
        unsigned int m_Count;
	};
}

#endif