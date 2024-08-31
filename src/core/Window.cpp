#include "Window.h"

#include <GLFW/glfw3.h>

namespace ar {
    Window::Window(int w, int h, const std::string& title)
    {
        GLFWwindow* window;

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
        if (!window) glfwTerminate();

        glfwMakeContextCurrent(window);

        glfwSetWindowCloseCallback(window, [](GLFWwindow* window){
            void (*cb)(Event&) = (void (*)(Event&))glfwGetWindowUserPointer(window);
            WindowCloseEvent ev;
            
            cb(ev);
        });

        m_NativeWindow = window;
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::SetEventCallback(void (*cb)(Event&))
    {
        glfwSetWindowUserPointer((GLFWwindow*)m_NativeWindow, (void*)cb);
    }

    WindowProcFunc Window::GetWindowProc()
    {
        return (WindowProcFunc)glfwGetProcAddress;
    }

    void Window::OnUpdate()
    {
        glfwSwapBuffers((GLFWwindow*)m_NativeWindow);
        glfwPollEvents();
    }
}