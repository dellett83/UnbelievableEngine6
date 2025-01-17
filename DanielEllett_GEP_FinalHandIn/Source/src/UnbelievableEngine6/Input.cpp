#include "Input.h"

#include <vector>
#include <iostream>

namespace UnbelievableEngine6
{
	Input::Input()
	{
		m_keyboard = std::make_shared<Keyboard>();
	}

	void Input::Update()
	{
		m_keyboard->Update();
	}

	void Input::InputHandler(const SDL_Event& _event)
	{
		if (_event.type == SDL_KEYDOWN)
		{
			m_keyboard->m_key.push_back(_event.key.keysym.sym);
			m_keyboard->m_keyPressed.push_back(_event.key.keysym.sym);
		}
		else if (_event.type == SDL_KEYUP)
		{
			m_keyboard->onKeyRelease(_event.key.keysym.sym);
		}

	}
}