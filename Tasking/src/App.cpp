#include "App.h"

#include <iostream>

#include "Renderer.h"

void App::init()
{
    /* Initialize the library */
    glfwInit();

    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);

    glewInit();

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(m_window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}

void App::run()
{
    while (!glfwWindowShouldClose(m_window))
    {
        std::cout << "Hello\n";

    }
}

void App::shutdown()
{
    
}

