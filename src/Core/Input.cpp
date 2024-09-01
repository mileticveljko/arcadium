#include "Input.h"

#include <GLFW/glfw3.h>
#include <Application.h>
#include <UserApplication.h>

namespace ar
{
    bool Input::IsKeyPressed(Key k)
    {
        GLFWwindow* window = (GLFWwindow*)Application::GetInstance()->GetUserApplication()->GetNativeWindow();
        auto state = glfwGetKey(window, k);
        return state == GLFW_PRESS;
    }

    bool Input::IsKeyReleased(Key k)
    {
        GLFWwindow* window = (GLFWwindow*)Application::GetInstance()->GetUserApplication()->GetNativeWindow();
        auto state = glfwGetKey(window, k);
        return state == GLFW_RELEASE;
    }
}
