#pragma once

#include <fstream>
#include <memory>
#include <vector>
#include "Resource.h"
#include "rend/Model.h"

namespace UnbelievableEngine6
{
	struct Model : Resource
	{
		void onLoad() { m_model = std::make_shared<rend::Model>(getPath() + ".obj"); }
		std::shared_ptr<rend::Model> getModel() { return m_model; }

	private:
		friend struct ModelRenderer;
		std::shared_ptr<rend::Model> m_model;
	};
};