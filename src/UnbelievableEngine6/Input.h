#pragma once

#include "Keyboard.h"


namespace UnbelievableEngine6
{
	struct Input
	{
		Input();
		~Input();

		bool Update();

		std::shared_ptr<Keyboard> getKeyboard() { return m_keyboard; }
	private:
		std::shared_ptr<Keyboard> m_keyboard;
	};
}