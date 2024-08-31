#include "Application.h"

#include <UserApplication.h>

namespace ar {
    Application* Application::s_Instance = nullptr;

    Application* Application::GetInstance()
    {
        if(!s_Instance) 
        {
            s_Instance = new Application();
        }
        return s_Instance;
    }

    Application::~Application()
    {
        delete m_UserApplication;
    }

    void Application::SetUserApplication(UserApplication* ua)
    {
        m_UserApplication = ua;
    }

    void Application::Run()
    {
        m_UserApplication->Run();
    }

    void Application::OnEvent(Event& ev)
    {
        m_UserApplication->OnEvent(ev);
    }
}