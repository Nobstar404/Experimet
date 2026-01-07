#pragma once

#include "WindowsWindow.h"

Window* Window::Create(const WindowProps& props)
{
	return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps& props)
{
	Init(props);
}

void WindowsWindow::Init(const WindowProps& props)
{
	m_Data.Title = props.m_Title;
	m_Data.Height = props.m_Height;
	m_Data.Width = props.m_Width;


}