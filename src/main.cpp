#include <Core.h>
#include <Render.h>

class ExampleLayer : public ar::Layer
{
public:
    ExampleLayer()
    {
        // Data
        float vertices[] = {
            100.0f, 100.0f, 0.0f, 0.0f,
            100.0f, 300.0f, 0.0f, 1.0f,
            300.0f, 300.0f, 1.0f, 1.0f,
            300.0f, 100.0f, 1.0f, 0.0f
        };
        unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
        };
        // !Data

        tran = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f);

        shader = std::make_unique<ar::Shader>("rrc/shaders/texture_shader.glsl");
    
        vao = std::make_shared<ar::VertexArrayObject>();

        std::unique_ptr<ar::VertexBuffer> vb =
            std::make_unique<ar::VertexBuffer>(vertices, sizeof(vertices));
        std::unique_ptr<ar::IndexBuffer> ib =
            std::make_unique<ar::IndexBuffer>(indices, sizeof(indices));
        std::unique_ptr<ar::VertexBufferLayout> layout =
            std::make_unique<ar::VertexBufferLayout>();
        layout->Push(ar::Type::Float, 2);
        layout->Push(ar::Type::Float, 2);

        vao->AddVertexBuffer(std::move(vb), std::move(layout));
        vao->AddIndexBuffer(std::move(ib));

        ar::Renderer::SetClearColor(0.1f, 0.6f, 0.4f);
    }

    virtual void OnUpdate()
    {
        shader->Bind();
        std::unique_ptr<ar::Texture> tex = std::make_unique<ar::Texture>("rrc/textures/wood.jpg");
        shader->UploadUniformMat4("transform", tran);
        ar::Renderer::Draw(vao);
    }

    virtual void OnEvent(ar::Event& ev)
    {

    }
private:
    std::unique_ptr<ar::Shader> shader;
    std::shared_ptr<ar::VertexArrayObject> vao;
    glm::mat4 tran;
};

class Sandbox : public ar::UserApplication
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

ar::UserApplication* ar::CreateUserApplication()
{
    return new Sandbox();
}