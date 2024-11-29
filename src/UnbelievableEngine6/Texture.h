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
		void onLoad() { m_texture = std::make_shared<rend::Texture>(getPath() + ".png"); }

	private:
		std::shared_ptr<rend::Texture> m_texture;
	};
};