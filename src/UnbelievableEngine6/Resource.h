#pragma once

#include <fstream>
#include <memory>
#include <vector>

namespace UnbelievableEngine6
{
	struct Resource
	{
		virtual void onLoad() = 0;
		std::string getPath() const;

	private:
		std::string m_path;
		void load();
	};
};