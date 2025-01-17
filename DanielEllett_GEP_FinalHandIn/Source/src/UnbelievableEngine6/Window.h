#pragma once

#include "SDL2/SDL.h"
#include <exception>
#include <iostream>
#include "gl/glew.h"

namespace UnbelievableEngine6
{
	class Core;
	class Window
	{
	public:
		Window(int _width, int _height);
		~Window();

		void window_initialize(int _width, int _height);


	private:
		friend class UnbelievableEngine6::Core;
		SDL_Window* m_raw;
		SDL_GLContext m_context;


		Window(const Window& _copy);
		Window& operator*(const Window& _assign);


		int m_width;
		int m_height;


	};
};