#ifndef USER_APPLICATION_H__
#define USER_APPLICATION_H__

#include <Layer.h>

#include <vector>

namespace ar {
    class Event;
    class Window;

    class UserApplication {
    public:
        UserApplication();
        virtual ~UserApplication();

        void Run();
        void OnEvent(Event&);

        void PushLayer(Layer*);
    private:
        bool m_Running;
        Window* m_Window;
    
    private:
        std::vector<Layer*> m_Layers;
    };

    static UserApplication* CreateUserApplication();
}

#endif