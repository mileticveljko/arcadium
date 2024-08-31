#include "Renderer.h"

#include <glad/glad.h>

namespace ar
{    
    int Renderer::Init(void*(*proc)(const char*))
    {
        int result = 1;
        if (!gladLoadGLLoader(proc))
        {
            result = 0;
        }

        return result;   
    }

    void Renderer::SetClearColor(float r, float g, float b)
    {
        glClearColor(r, g, b, 1.0f);
    }

    void Renderer::ClearScreen()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Draw(std::shared_ptr<VertexArrayObject> vao)
    {
        vao->Bind();
        glDrawElements(GL_TRIANGLES, vao->GetNumberOfElements(), GL_UNSIGNED_INT, nullptr);
    }
}