#pragma once

#include <iostream>

struct WindowProps
{
    unsigned int m_Width;
    unsigned int m_Height;
    std::string m_Title;

    WindowProps(std::string title = "Window", 
        unsigned int width = 9,
        unsigned int height = 10)
        :m_Width(width), m_Height(height), m_Title(title) {};
};

class Window
{
public:
    Window* Create(const WindowProps & = WindowProps());
};