#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "TaskTable.h"

class App
{
public:
    void init();
    void run();
    void shutdown();
    
private:
    std::vector<TaskTable> m_TaskTables;
    GLFWwindow* m_window;
};

