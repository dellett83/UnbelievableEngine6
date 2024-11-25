#include "Component.h"
#include "glm/glm.hpp"
#include "rend/rend.h"


namespace UnbelievableEngine6
{
	struct Transform : Component
	{
		void on_initialize();
		glm::mat4 model();
	private:
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}