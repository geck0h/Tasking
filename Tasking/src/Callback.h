#pragma once

#include "GLheaders.h"

class Callback
{
public:
    Callback() = delete;
    Callback(GLFWwindow *window);
    
private:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    
private:
    GLFWwindow* m_window;
};

