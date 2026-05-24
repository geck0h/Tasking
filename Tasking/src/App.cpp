#include "App.h"

void App::Init()
{
    /* Initialize the library */
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);

    glewExperimental = GL_TRUE;
    glewInit();

    glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
    
    Callback callback(m_window);

    m_renderer = new Renderer;
}

void App::Run()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        m_renderer->Draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(m_window);
        /* Poll for and process events */
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
