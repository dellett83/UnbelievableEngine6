#include "Keyboard.h"

#include <iostream>

namespace UnbelievableEngine6
{
	void Keyboard::Update()
	{
		m_keyPressed.clear();
		m_keyReleased.clear();
	}

	bool Keyboard::isKeyPressed(int _key)
	{
		for (int i = 0; i < m_keyPressed.size(); i++)
		{
			if (m_keyPressed[i] == _key)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::isKeyReleased(int _key)
	{
		for (int i = 0; i < m_keyReleased.size(); i++)
		{
			if (m_keyReleased[i] == _key)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::isKeyDown(int _key)
	{
		for (int i = 0; i < m_key.size(); i++)
		{
			if (m_key[i] == _key)
			{
				return true;
			}
		}
		return false;
	}
}