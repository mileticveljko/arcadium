#ifndef RENDERER_H__
#define RENDERER_H__

#include <VertexArrayObject.h>

namespace ar {
    enum Type {
        Byte = 0x1400,
        UnsignedByte = 0x1401,
        Short = 0x1402,
        UnsignedShort = 0x1403,
        Int = 0x1404,
        UnsignedInt = 0x1405,
        Float = 0x1406,
    };

    class Renderer {
    public:
        static int Init(void*(*)(const char*));
        static void SetClearColor(float r, float g, float b);
        static void ClearScreen();

        static void Draw(std::shared_ptr<VertexArrayObject>);
    };
}

#endif