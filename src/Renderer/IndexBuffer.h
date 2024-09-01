#ifndef INDEX_BUFFER_H__
#define INDEX_BUFFER_H__

namespace ar
{
	class IndexBuffer
	{
	public:
		IndexBuffer(unsigned int* indices, unsigned int size);
		~IndexBuffer();

		void Bind();
		void Unbind();

		inline unsigned int GetCount() const { return m_Count; }
	private:
		unsigned int m_ID;
		unsigned int m_Count;
	};

}

#endif