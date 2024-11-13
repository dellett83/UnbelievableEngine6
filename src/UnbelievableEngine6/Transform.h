#include "Component.h"
#include "glm/glm.hpp"


namespace UnbelievableEngine6
{
	struct Transform : Component
	{
		void on_initialize();

		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}