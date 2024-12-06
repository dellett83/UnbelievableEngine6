#include "ModelRenderer.h"


namespace UnbelievableEngine6
{

	ModelRenderer::ModelRenderer(){
	}

	void ModelRenderer::on_initialize()
	{
		m_shader = std::make_shared<rend::Shader>(); 
		"../UnbelievableEngine6/src/shaders/texture.vert", "../UnbelievableEngine6/src/shaders/texture.frag";
	}

	void ModelRenderer::setTex(std::shared_ptr<Texture> _tex)
	{
		m_texture = _tex;
	}

	void ModelRenderer::setModel(std::shared_ptr<Model> _model)
	{
		m_model = _model;
	}

	void ModelRenderer::on_render()
	{
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)1080 / (float)720, 0.1f, 100.0f);
		m_shader->uniform("u_Projection", projection);

		glm::mat4 view(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(0, 1, 0));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(1, 0, 0));
		view = glm::rotate(view, glm::radians(0.0f), glm::vec3(0, 0, 1));
		view = glm::inverse(view);
		m_shader->uniform("u_View", view);

		Transform* transform = entity()->get_component<Transform>().get();

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -10.0f));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(0, 1, 0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(1, 0, 0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), glm::vec3(0, 0, 1));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
		m_shader->uniform("u_Model", transform->model());

		m_shader->draw(m_model->m_model.get() , m_texture->m_texture.get());
	}

}