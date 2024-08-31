#ifndef WINDOW_H__
#define WINDOW_H__

#include "Event.h"
#include <string>

namespace ar
{
    using WindowProcFunc = void*(*)(const char*);

    class Event;
    
    class Window {
    public:
        Window(int w, int h, const std::string& title);
        ~Window();

        void OnUpdate();
        void SetEventCallback(void (*)(Event&));
        WindowProcFunc GetWindowProc();
    private:
        void *m_NativeWindow;
    };   
}
#endif