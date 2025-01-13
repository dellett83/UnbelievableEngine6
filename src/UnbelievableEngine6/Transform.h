#pragma once

#include "Component.h"
#include "glm/glm.hpp"
#include "rend/rend.h"


namespace UnbelievableEngine6
{
	struct Transform : Component
	{
		void on_initialize();
		glm::mat4 model();

		void setPosition(glm::vec3 _position) { m_position = _position; }
		glm::vec3 getPosition() { return m_position; }

		void setRotation(glm::vec3 _rotation) { m_rotation = _rotation; }
		glm::vec3 getRotation() { return m_rotation; }

		void setScale(glm::vec3 _scale) { m_scale = _scale; }
		glm::vec3 getScale() { return m_scale; }

		void Movement(glm::vec3 _amount) { m_position += _amount; }
		void Rotation(glm::vec3 _amount) { m_rotation += _amount; }

	private:
		glm::vec3 m_position{ 0.f };
		glm::vec3 m_rotation{ 0.f };
		glm::vec3 m_scale{ 0.f };
	};
}