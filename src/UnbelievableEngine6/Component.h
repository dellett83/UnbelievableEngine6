#include <memory>
namespace UnbelievableEngine6
{
	struct Entity;

	struct Component
	{
		virtual void on_initialize();
		virtual void on_tick();

	private:
		friend struct UnbelievableEngine6::Entity;

		std::weak_ptr<Entity> m_entity;

		void tick();

	};


}