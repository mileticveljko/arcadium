#include "Timestamp.h"

#include <GLFW/glfw3.h>

namespace ar
{
    Timestamp::Timestamp()
        : m_DeltaTime(0), m_LastTime(0)
    {

    }
    
    Timestamp::~Timestamp()
    {

    }

    const double Timestamp::GetDeltaTime() const
    {
        return m_DeltaTime;
    }
        
    void Timestamp::CalculateDeltaTime()
    {
        m_DeltaTime = glfwGetTime() - m_LastTime;
        m_LastTime = glfwGetTime();
    }

}
