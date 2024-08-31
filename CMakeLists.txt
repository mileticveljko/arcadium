cmake_minimum_required(VERSION 3.5)
project(lisum_map_engine)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/stb-image)
add_subdirectory(vendor/glm)

set(SRCS 
    src/main.cpp

    src/core/Application.cpp
    src/core/UserApplication.cpp
    src/core/Window.cpp

    src/render/Renderer.cpp
    src/render/VertexArrayObject.cpp
    src/render/VertexBuffer.cpp
    src/render/IndexBuffer.cpp
    src/render/Shader.cpp
    src/render/Texture.cpp
)

set(COMPILE_OPTIONS "-Wall;-Wno-int-to-pointer-cast;-Wno-unused-function")

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad stb-image glm)
target_include_directories(${PROJECT_NAME} PRIVATE src/render src/core)
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})