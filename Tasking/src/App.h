#pragma once

#include <vector>

#include "GLheaders.h"

#include "TaskTable.h"
#include "Callback.h"
#include "Renderer.h"


class App
{
public:
    App() 
        : m_window(nullptr), m_renderer(nullptr) {}

    void Init();
    void Run();
    void Shutdown();
    
    void OnKey(int key, int action);
private:
    
private:
    std::vector<TaskTable> m_TaskTables;
    GLFWwindow* m_window;
    Renderer* m_renderer;
};

