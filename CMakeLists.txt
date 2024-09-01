cmake_minimum_required(VERSION 3.5)
project(arcadium)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/stb-image)
add_subdirectory(vendor/glm)

set(SRCS 
    src/main.cpp

    src/Core/Application.cpp
    src/Core/UserApplication.cpp
    src/Core/Window.cpp
    src/Core/Input.cpp

    src/Renderer/Renderer.cpp
    src/Renderer/VertexArrayObject.cpp
    src/Renderer/VertexBuffer.cpp
    src/Renderer/IndexBuffer.cpp
    src/Renderer/Shader.cpp
    src/Renderer/Texture.cpp
    src/Renderer/OrthographicCamera.cpp
)

set(COMPILE_OPTIONS "-Wall;-Wno-int-to-pointer-cast;-Wno-unused-function")

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad stb-image glm)
target_include_directories(${PROJECT_NAME} PRIVATE src/Renderer src/Core src)
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})