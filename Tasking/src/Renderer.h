#pragma once

#include "Shader.h"

class Renderer
{
public:
    Renderer();

    void Draw() const;

private:
    unsigned int VBO, VAO;
    Shader m_shader;
};

