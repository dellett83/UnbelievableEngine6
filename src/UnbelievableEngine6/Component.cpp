#include "Component.h"
#include "Transform.h"
#include "Entity.h"

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

	std::shared_ptr<Transform> Component::transform()
	{
		return entity()->get_component<Transform>();
	}

	glm::vec3 Component::position()
	{
		return transform()->getPosition();
	}

	void Component::setPosition(glm::vec3 _position)
	{
		transform()->setPosition(_position);
	}
}