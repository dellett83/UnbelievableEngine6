#pragma once

#include <fstream>
#include <memory>
#include <vector>

namespace UnbelievableEngine6
{
	struct Resource
	{
		virtual void onLoad() = 0;
		std::string getPath() const { return m_path; }
		void setPath(std::string _path) { m_path = _path; }

	private:
		std::string m_path;
		void Load();
	};
};