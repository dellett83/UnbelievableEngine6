#pragma once

#include "Component.h"

namespace UnbelievableEngine6
{
	class BoxCollider : public Component
	{
	public:
		bool isColliding(std::shared_ptr<BoxCollider> _other);

		void setSize(glm::vec3 _size) { m_size = _size; }

		void setOffset(glm::vec3 _offset) { m_offset = _offset; }

		
	private:
		glm::vec3 m_size{ 1 };
		glm::vec3 m_offset{ 0 };
	};
};