#pragma once

#include "Resource.h"

#include <AL/al.h>

namespace UnbelievableEngine6
{
	class AudioSource;

	class Sound : public Resource
	{
	public:
		void onLoad();
	private:
		friend class AudioSource;

		ALuint m_BufferId = 0;
		ALenum m_format = 0;
		ALsizei m_frequency = 0;
	};
};