#include "Input.h"

#include <vector>
#include <memory>

namespace UnbelievableEngine6
{
	Input::Input()
	{
		m_keyboard = std::make_shared<Keyboard>();
	}

	bool Input::Update()
	{
		m_keyboard->Update();

		SDL_Event e = {};
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				return false;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				m_keyboard->m_key.push_back(e.key.keysym.sym);
				m_keyboard->m_keyPressed.push_back(e.key.keysym.sym);
			}
			else if (e.type == SDL_KEYUP)
			{
				m_keyboard->onKeyRelease(e.key.keysym.sym);
			}
		}
		return true;
	}
}