#ifndef LAYER_H__
#define LAYER_H__

#include <Event.h>
#include <Timestamp.h>

namespace ar
{
    class Layer
    {
    public:
        Layer() = default;
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(Timestamp&) {}
        virtual void OnEvent(Event&) {}
    };
}


#endif