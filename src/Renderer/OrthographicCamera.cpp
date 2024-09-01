#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace ar
{
    OrthographicCamera::OrthographicCamera(float left, float right, float top, float bottom)
        : m_Proj(glm::ortho(left, right, bottom, top)),
        m_View(1.0f),
        m_Pos({0.0f, 0.0f, 0.0f}),
        m_Rot({0.0f, 0.0f, 0.0f})
    {
        m_ViewProj = m_Proj * m_View;
    }
    
    OrthographicCamera::~OrthographicCamera()
    {

    }

    const glm::vec3& OrthographicCamera::GetPosition() const
    {
        return m_Pos;
    }

    void OrthographicCamera::SetPosition(const glm::vec3& pos)
    {
        m_Pos = pos;
        CalculateMatrices();
    }
    
    const glm::vec3& OrthographicCamera::GetRotation() const
    {
        return m_Rot;
    }
    
    void OrthographicCamera::SetRotation(const glm::vec3& rot)
    {
        m_Rot = rot;
        CalculateMatrices();
    }

    const glm::mat4& OrthographicCamera::GetProjectionMatrix() const
    {
        return m_Proj;
    }

	const glm::mat4& OrthographicCamera::GetViewMatrix() const
    {
        return m_View;
    }

	const glm::mat4& OrthographicCamera::GetViewProjectionMatrix() const
    {
        return m_ViewProj;
    }

    void OrthographicCamera::CalculateMatrices()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Pos) * 
            glm::rotate(glm::mat4(1.0f), glm::radians(m_Rot.z), glm::vec3(0, 0, 1));
        
        m_View = glm::inverse(transform);
        m_ViewProj = m_Proj * m_View;
    }
}
