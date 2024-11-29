#pragma once

#include "Component.h"
#include "rend/rend.h"


namespace UnbelievableEngine6
{
	struct ModelRenderer : Component
	{
		ModelRenderer();
		void on_render();

	private:
		rend::Model m_model;
		rend::Shader m_shader;
		rend::Texture m_texture;
	};
}
