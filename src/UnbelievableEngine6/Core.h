#pragma once

#include <memory>
#include <vector>

#include "Audio.h"

namespace UnbelievableEngine6
{
	struct Entity;
	struct Window;
	struct Resources;
	struct Input;
	struct Keyboard;

	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void start();

		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<Resources> getResources();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Audio> getAudio();

		template <typename T>
		void find_components(std::vector < std::shared_ptr<T>>& _out)
		{
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				std::shared_ptr<Entity> e = m_entities.at(ei);
				for (size_t ci = 0; ci < e->m_components.size(); ++ci)
				{
					std::shared_ptr<Component> c = e->m_components.at(ci);
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}

	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Audio> m_audio;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Input> m_input;
	};
}