#pragma once

#include "Window.h"

class WindowsWindow : public Window
{
public:
	WindowsWindow(const WindowProps& props);

	virtual void Init() {};

private:

	struct WindowData
	{
		std::string Title;
		unsigned int Width, Height;
		bool VSync;

	};

	WindowData m_Data;

	virtual void Init(const WindowProps& props);
};