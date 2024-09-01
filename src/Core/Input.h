#ifndef INPUT_H__
#define INPUT_H__

#include <KeyCodes.h>

namespace ar
{
    class Input
    {
    public:
        Input() = default;
        ~Input() = default;

        static bool IsKeyPressed(Key);
        static bool IsKeyReleased(Key);
    private:
    };
}

#endif