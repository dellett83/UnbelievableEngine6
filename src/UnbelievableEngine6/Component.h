#pragma once

#include <memory>
namespace UnbelievableEngine6
{
	struct Entity;

	struct Component
	{
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();

		std::shared_ptr<Entity> entity();
		glm::vec3 getPosition();
		void setPosition(glm::vec3 _position);

	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;

		void tick();

	};


}