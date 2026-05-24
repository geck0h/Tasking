#include "App.h"

#include "Callback.h"

App::App()
    : m_window(nullptr), m_renderer(nullptr), m_callback(nullptr) {}

void App::Init()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    m_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    glfwMakeContextCurrent(m_window);

    glewExperimental = GL_TRUE;
    glewInit();

    glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
    
    m_callback = new Callback(m_window);

    m_renderer = new Renderer;
}

void App::Run()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        m_renderer->Draw();

        glfwSwapBuffers(m_window);

        glfwPollEvents();
    }
}

void App::Shutdown()
{
    glfwTerminate();
}

void App::OnKey(int key, int action)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}
