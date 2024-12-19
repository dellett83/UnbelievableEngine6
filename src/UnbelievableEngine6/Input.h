#pragma once

#include "Keyboard.h"

#include <SDL2/sdl.h>
#include <memory>


namespace UnbelievableEngine6
{
	struct Core;

	struct Input
	{
		Input();

		void Update();

		std::shared_ptr<Keyboard> getKeyboard() { return m_keyboard; }


	private:
		friend class Core;

		void InputHandler(const SDL_Event& _event);

		std::shared_ptr<Keyboard> m_keyboard;
	};
}