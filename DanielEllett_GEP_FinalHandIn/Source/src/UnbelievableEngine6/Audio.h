#pragma once

#include <AL/al.h>
#include <AL/alc.h>

namespace UnbelievableEngine6
{
	class Audio
	{
	public:
		Audio();
		~Audio();


	private:
		ALCcontext* m_context;
		ALCdevice* m_device;
	};
};