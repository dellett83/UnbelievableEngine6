#include "SDL2/SDL.h"

namespace UnbelievableEngine6
{
	class Core;
	class Window
	{
	public:
		Window(int _width, int _height);
		~Window();

		void window_initialize();


	private:
		friend class UnbelievableEngine6::Core;
		SDL_Window* m_Raw;
		SDL_GLContext m_Context;


		Window(const Window& _copy);
		Window& operator*(const Window& _assign);


		int m_width;
		int m_height;


	};
};