#pragma once

#include "Component.h"
#include "rend/rend.h"


namespace UnbelievableEngine6
{
	struct triangleRenderer : Component
	{
		triangleRenderer();
		void on_render();

	private:
		rend::Mesh m_mesh;
		//rend::Model m_model;
		rend::Shader m_shader;
		rend::Texture m_texture;
	};
}
