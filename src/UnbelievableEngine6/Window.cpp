#include "Window.h"

namespace UnbelievableEngine6
{
	Window::Window(int _width, int _height)
	{
		m_height = 1080;
		m_width = 720;
		window_initialize(m_width, m_height);
	}
	Window ::~Window()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_raw);
		SDL_Quit();
	}
	void Window::window_initialize(int m_width, int m_height)
	{
		m_raw = SDL_CreateWindow("Game",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			m_width, m_height,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!m_raw)
		{
			throw std::exception();
		}
		m_context = SDL_GL_CreateContext(m_raw);

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		std::cout << "Width: " << m_width << " ," << "Height: " << m_height << std::endl;
	}
}