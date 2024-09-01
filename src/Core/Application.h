#ifndef APPLICATION_H__
#define APPLICATION_H__

#include <Event.h>

namespace ar
{
    class UserApplication;

    class Application {
    public:
        ~Application();

        void SetUserApplication(UserApplication*);

        void Run();
        void OnEvent(Event&);

        const UserApplication* GetUserApplication() const;

        static Application* GetInstance();

    private:
        Application() = default;

    private:
        static Application* s_Instance;
        UserApplication* m_UserApplication;
    };
}

#endif