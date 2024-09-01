#include "Renderer.h"

#include <glad/glad.h>

namespace ar
{    
    Renderer::SceneData Renderer::m_SceneData = {glm::mat4(1.0f)};

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

    void Renderer::Draw(std::shared_ptr<VertexArrayObject> vao, std::shared_ptr<Shader> sh, const glm::mat4& trans)
    {
        sh->Bind();
        sh->UploadUniformMat4("u_ViewProj", m_SceneData.m_ViewProj);
        sh->UploadUniformMat4("u_Model", trans);

        vao->Bind();
        glDrawElements(GL_TRIANGLES, vao->GetNumberOfElements(), GL_UNSIGNED_INT, nullptr);
    }

    void Renderer::BeginScene(std::shared_ptr<ar::OrthographicCamera> cam)
    {
        m_SceneData.m_ViewProj = cam->GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {

    }
}