#pragma once

#include "Component.h"
#include "rend/rend.h"


namespace UnbelievableEngine6
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		void on_render();

	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;
		rend::Texture m_texture;
	};
}
