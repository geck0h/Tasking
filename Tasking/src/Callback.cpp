#include "Callback.h"

Callback::Callback(GLFWwindow* window)
    : m_window(window)
{
    glfwSetWindowUserPointer(m_window, this);
    
    glfwSetKeyCallback(m_window, keyCallback);
}

void Callback::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    App* appPtr = static_cast<App*>(glfwGetWindowUserPointer(window));
    
    appPtr->OnKey(key, action);
    
    delete appPtr;
}



