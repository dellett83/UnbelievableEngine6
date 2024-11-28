#pragma once

#include <memory>
#include <vector>
namespace UnbelievableEngine6
{
	struct Entity;
	struct Window;

	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void start();

		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;

	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		std::shared_ptr<Window> m_window;
	};
}