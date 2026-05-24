#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    std::ifstream vertexFile(vertexPath);
    std::ifstream fragmentFile(fragmentPath);
    
    std::stringstream vertexStream;
    std::stringstream fragmentStream;
    
    vertexStream << vertexFile.rdbuf();
    fragmentStream << fragmentFile.rdbuf();
    
    if (!vertexFile.is_open()) {
        std::cout << "Failed to open vertex shader: " << vertexPath << '\n';
    }
    if (!fragmentFile.is_open()) {
        std::cout << "Failed to open fragment shader: " << fragmentPath << '\n';
    }

    vertexFile.close();
    fragmentFile.close();
    
    std::string vertexSrc(vertexStream.str());
    std::string fragmentSrc(fragmentStream.str());
    
    const char* vertexCode = vertexSrc.c_str();
    const char* fragmentCode = fragmentSrc.c_str();
    
    char infoLog[512];
    int success;
    
    unsigned int vertexID;
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexID, 1, &vertexCode, NULL);
    glCompileShader(vertexID);
    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
        std::cout << "-- VERTEX COMILE ERROR --\n" << infoLog << '\n';
    }
    
    unsigned int fragmentID;
    fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &fragmentCode, NULL);
    glCompileShader(fragmentID);
    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
        std::cout << "-- FRAGMENT COMPILE ERROR --\n" << infoLog << '\n';
    }

    m_programID = glCreateProgram();
    glAttachShader(m_programID, vertexID);
    glAttachShader(m_programID, fragmentID);
    glLinkProgram(m_programID);
    glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_programID, 512, NULL, infoLog);
        std::cout << "-- PROGRAM LINK ERROR --\n" << infoLog << '\n';
    }
    
    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
}

void Shader::Use() const
{
    glUseProgram(m_programID);
}

void Shader::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_programID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(m_programID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(m_programID, name.c_str()), value);
}