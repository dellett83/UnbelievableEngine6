#pragma once

#include <memory>
#include <glm/glm.hpp>
namespace UnbelievableEngine6
{
	struct Entity;
	struct Transform;

	struct Component
	{

	public:
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();
		std::shared_ptr<Entity> entity();
		std::shared_ptr<Transform> transform();
		glm::vec3 position();
		void setPosition(glm::vec3 _position);

	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;

		void tick();

	};


}