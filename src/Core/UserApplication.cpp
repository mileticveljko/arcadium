#include "UserApplication.h"

#include <Application.h>
#include <Window.h>
#include <Event.h>
#include <Renderer.h>

namespace ar
{
    UserApplication::UserApplication()
        : m_Running(true)
    {
        m_Layers.clear();
        m_Window = new Window(640, 480, "Lisum");
        m_Window->SetEventCallback([](Event& ev)
        {
            Application::GetInstance()->OnEvent(ev);
        });
        Renderer::Init(m_Window->GetWindowProc());
    }

    UserApplication::~UserApplication()
    {
        for(Layer* layer : m_Layers)
        {
            delete layer;
        }

        delete m_Window;
    }

    void UserApplication::PushLayer(Layer* layer)
    {
        m_Layers.push_back(layer);
    }

    void UserApplication::Run()
    {
        while (m_Running)
        {
            Renderer::ClearScreen();

            for(Layer* layer : m_Layers)
            {
                layer->OnUpdate();
            }
            
            m_Window->OnUpdate();
        }
        
    }

    void UserApplication::OnEvent(Event& ev)
    {
        if(ev.GetEventType() == EventType::WindowClose)
        {
            m_Running = false;
            ev.SetHandled();
        }

        for(auto it = m_Layers.end(); it != m_Layers.begin(); --it)
        {
            if(ev.IsHandled()) 
            {
                break;
            }
            (*it)->OnEvent(ev);
        }
    }

    const void* UserApplication::GetNativeWindow() const
    {
        return m_Window->GetNativeWindow();
    }
}