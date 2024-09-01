#include <arcadium.h>

class ExampleLayer : public ar::Layer
{
public:
    ExampleLayer()
    {
        // Data
        float vertices[] = {
            0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 50.0f, 0.0f, 1.0f,
            50.0f, 50.0f, 1.0f, 1.0f,
            50.0f, 0.0f, 1.0f, 0.0f
        };
        unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
        };
        // !Data
        shader = std::make_shared<ar::Shader>("rrc/shaders/texture_shader.glsl");
        vao = std::make_shared<ar::VertexArrayObject>();
        cam = std::make_shared<ar::OrthographicCamera>(0.0f, 640.0f, 0.0f, 480.0f);
        tex = std::make_unique<ar::Texture>("rrc/textures/wood.jpg");

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

    ~ExampleLayer()
    {

    }

    virtual void OnUpdate()
    {
        static glm::vec3 transform = {100, 100, 0};

        if(ar::Input::IsKeyPressed(ar::Key::Up))
        {
            transform.y--;
        }
        else if(ar::Input::IsKeyPressed(ar::Key::Down))
        {
            transform.y++;
        }
        
        if(ar::Input::IsKeyPressed(ar::Key::Left))
        {
            transform.x--;
        }
        else if(ar::Input::IsKeyPressed(ar::Key::Right))
        {
            transform.x++;
        }

        ar::Renderer::BeginScene(cam);
        tex->Bind();
        ar::Renderer::Draw(vao, shader, glm::translate(glm::mat4(1.0f), transform));
        ar::Renderer::Draw(vao, shader, glm::translate(glm::mat4(1.0f), glm::vec3(300, 300, 0)));
        ar::Renderer::EndScene();
    }

    virtual void OnEvent(ar::Event& ev)
    {

    }
    
private:
    std::shared_ptr<ar::OrthographicCamera> cam;
    std::shared_ptr<ar::Shader> shader;
    std::shared_ptr<ar::VertexArrayObject> vao;
    std::unique_ptr<ar::Texture> tex;
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