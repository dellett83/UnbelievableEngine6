#pragma once

#include "Component.h"
#include "UnbelievableEngine6/UnbelievableEngine6.h"


namespace UnbelievableEngine6
{
	struct Model;
	struct Texture;

	struct ModelRenderer : Component
	{
		ModelRenderer();
		void on_initialize();
		//~ModelRenderer();
		void on_render();

		void setModel(std::shared_ptr<Model> _model);
		void setTex(std::shared_ptr<Texture> _tex);
	private:
		std::shared_ptr<Model> m_model;
		std::shared_ptr<rend::Shader> m_shader;
		std::shared_ptr<Texture> m_texture;
	};
}
