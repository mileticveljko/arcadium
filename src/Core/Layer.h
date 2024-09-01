#ifndef LAYER_H__
#define LAYER_H__

#include <Event.h>

namespace ar
{
    class Layer
    {
    public:
        Layer() = default;
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event&) {}
    };
}


#endif