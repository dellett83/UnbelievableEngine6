#include <memory>
#include <vector>

namespace UnbelievableEngine6
{
	struct Core;
	struct Component;

	struct Entity
	{
		template<typename T>
		std::shared_ptr<T> add_component()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			
			rtn->m_entity = m_self;
			rtn->on_initialize();
			m_components.push_back(rtn);

			return rtn;
		}

	private:
		friend struct UnbelievableEngine6::Core;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
		std::vector<std::shared_ptr<Component> > m_components;

		void tick();

	};

}