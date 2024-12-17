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
	}
	void Input::InputHandler(const SDL_Event& _e)
	{
		 if (_e.type == SDL_KEYDOWN)
		{
			m_keyboard->m_key.push_back(_e.key.keysym.sym);
			m_keyboard->m_keyPressed.push_back(_e.key.keysym.sym);
		}
		else if (_e.type == SDL_KEYUP)
		{
			m_keyboard->onKeyRelease(_e.key.keysym.sym);
		}

	}
}