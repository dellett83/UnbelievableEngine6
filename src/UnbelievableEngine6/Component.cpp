#include "Component.h"

namespace UnbelievableEngine6
{
	void Component::on_initialize() {}
	void Component::on_tick() {}
	void Component::on_render() {}

	void Component::tick()
	{
		on_tick();
	}

	std::shared_ptr<Entity> Component::entity()
	{
		return m_entity.lock();
	}
}