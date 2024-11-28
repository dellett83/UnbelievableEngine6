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
		void onLoad();

	private:
		std::shared_ptr<rend::Model> m_model;
	};
};