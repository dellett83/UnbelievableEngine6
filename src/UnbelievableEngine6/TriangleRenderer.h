#include "Component.h"
#include "Entity.h"
#include "Transform.h"
#include "rend/Model.h"
#include "rend/Shader.h"
#include "rend/Texture.h"
#include "rend/Mesh.h"
#include "rend/RenderTexture.h"


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
