#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "GLheaders.h"

class Shader
{
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    
    void Use() const;
    
    void SetBool(const std::string& name, bool val) const;
    void SetInt(const std::string& name, int val) const;
    void SetFloat(const std::string& name, float val) const;
    
public:
    unsigned int m_programID;
};