#ifndef VERTEX_BUFFER_H__
#define VERTEX_BUFFER_H__

#include <vector>

namespace ar
{
    struct VertexBufferElement
    {
        unsigned int type;
        unsigned int count;
        unsigned char normalized;

        static unsigned int GetSizeOfType(unsigned int type);
    };

    class VertexBufferLayout
    {
    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;
    public:
        VertexBufferLayout()
            : m_Stride(0) {}
        ~VertexBufferLayout() {}

        void Push(unsigned int type, unsigned int count);

        inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
        inline unsigned int GetStride() const { return m_Stride; }
    protected:
    };

	class VertexBuffer
	{
	public:
		VertexBuffer(float* vertices, unsigned int size);
		~VertexBuffer();

		void Bind();
		void Unbind();

	private:
		unsigned int m_ID;
	};
}

#endif