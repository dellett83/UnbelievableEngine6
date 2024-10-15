#include "Core.h"
#include "Entity.h"

#include <iostream>

namespace UnbelievableEngine6
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;

		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;
		rtn->m_core = m_self;
		m_entities.push_back(rtn);

		std::cout << rtn->m_core.lock().get() << std::endl;

		return rtn;
	}


	void Core::start()
	{
		for (size_t i = 0; i < 25; ++i)
		{
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->tick();
			}
		}
	}

}
