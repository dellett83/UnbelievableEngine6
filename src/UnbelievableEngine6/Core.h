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

	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Audio> m_audio;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Input> m_input;
	};
}