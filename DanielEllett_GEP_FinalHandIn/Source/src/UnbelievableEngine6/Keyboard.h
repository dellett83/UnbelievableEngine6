#pragma once

#include <exception>
#include <iostream>
#include <vector>
#include <memory>
#include "gl/glew.h"
#include "SDL2/SDL.h"

namespace UnbelievableEngine6
{
	class Keyboard
	{
	public:
		bool isKeyPressed(int _key);
		bool isKeyReleased(int _key);
		bool isKeyDown(int _key);

	private:
		friend class Input;

		void Update();

		void onKeyRelease(int _key)
		{
			for (int i = 0; i < m_key.size(); i++)
			{
				if (m_key[i] == _key)
				{
					m_key.erase(m_key.begin() + i);
					--i;
					break;
				}
			}
		}
		std::vector<int> m_key;
		std::vector<int> m_keyPressed;
		std::vector<int> m_keyReleased;
	};
};