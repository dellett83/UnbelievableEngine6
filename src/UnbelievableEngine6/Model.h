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

	private:
		std::shared_ptr<rend::Model> m_model;
	};
};