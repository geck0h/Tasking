#include <iostream>

#include "TaskTable.h"
#include "GLFW/glfw3.h"

int main()
{
        GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
    
	TaskTable tasktable(7);
	tasktable.onDay(0).addTask("Task name");
	tasktable.onDay(0).addTask("Task name 2");

	tasktable.onDay(0).tickTask("Task name");

	std::cout << tasktable.onDay(0).checkTask("Task name") << std::endl;
    
	//tasktable.onDay(Day::MONDAY).removeTask("Task name");

	std::cout << tasktable.onDay(0).viewPercentFinished();

	std::cin.get();
}