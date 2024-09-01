#ifndef ORTHOGRAPHIC_CAMERA_H__
#define ORTHOGRAPHIC_CAMERA_H__

#include <glm/glm.hpp>

namespace ar
{
    class OrthographicCamera
    {
    public:
        OrthographicCamera(float left, float right, float top, float bottom);
        virtual ~OrthographicCamera();

        const glm::vec3& GetPosition() const;
        void SetPosition(const glm::vec3& pos);

        const glm::vec3& GetRotation() const;
        void SetRotation(const glm::vec3& rot);

        const glm::mat4& GetProjectionMatrix() const;
		const glm::mat4& GetViewMatrix() const;
		const glm::mat4& GetViewProjectionMatrix() const;
    private:
        void CalculateMatrices();
    
    private:
        const glm::mat4 m_Proj;
        glm::mat4 m_View;
        glm::mat4 m_ViewProj;

        glm::vec3 m_Pos;
        glm::vec3 m_Rot;
    };
}


#endif