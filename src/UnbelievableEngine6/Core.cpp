#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Window.h"
#include "Resource.h"

#include <GL/glew.h>
#include <iostream>

namespace UnbelievableEngine6
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>(1920, 1080);
		rtn->m_self = rtn;

		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;
		rtn->m_core = m_self;
		rtn->add_component<Transform>();

		m_entities.push_back(rtn);

		std::cout << rtn->m_core.lock().get() << std::endl;

		return rtn;
	}

	std::shared_ptr<Window> Core::window() const
	{
		return m_window;
	}

	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				if (m_resources.at(i)->getPath() == _path)
				{
					return m_resources.at(i);
				}
			}
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;
		}
	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
	};

	void Core::start()
	{
		bool running = true;
		while (running)
		{
			SDL_Event event = {};

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}
			}

			for (size_t ent = 0; ent < m_entities.size(); ent++)
			{
				m_entities.at(ent)->tick();
			}

			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			for (size_t ent = 0; ent < m_entities.size(); ent++)
			{
				m_entities.at(ent)->on_render();
			}

			SDL_GL_SwapWindow(m_window->m_raw);
		}
	}

}
