#pragma once

#include <fstream>
#include <memory>
#include <vector>

#include "Resource.h"
#include "rend/Texture.h"

namespace UnbelievableEngine6
{
	struct Texture : public Resource
	{
		void onLoad();

	private:
		std::shared_ptr<rend::Texture> m_texture;
	};
};