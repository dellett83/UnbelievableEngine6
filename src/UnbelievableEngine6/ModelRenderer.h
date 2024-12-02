#pragma once

#include "Component.h"
#include "rend/rend.h"


namespace UnbelievableEngine6
{
	struct ModelRenderer : Component
	{
		ModelRenderer();
		void on_render();

		void setModel(std::shared_ptr<rend::Model> _model);
		void setTex(std::shared_ptr<rend::Texture> _tex);
	private:
		rend::Model m_model;
		rend::Shader m_shader;
		rend::Texture m_texture;
	};
}
