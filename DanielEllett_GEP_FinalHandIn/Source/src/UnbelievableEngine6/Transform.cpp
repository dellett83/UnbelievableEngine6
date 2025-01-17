#include "Transform.h"

namespace UnbelievableEngine6
{
	void Transform::on_initialize()
	{
		m_position = glm::vec3(0, 0, 0);
		m_rotation = glm::vec3(0, 0, 0);
		m_scale = glm::vec3(1, 1, 1);
	}

	glm::mat4 Transform::model()
	{
		glm::mat4 rtn (1.0f);

		rtn = glm::translate(rtn, m_position);
		rtn = glm::scale(rtn, m_scale);

		return rtn;
	}
}