#pragma once

#include "Component.h"
#include "Sound.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <vector>
#include <string>

namespace UnbelievableEngine6
{
	class AudioSource : public Component
	{
	public:
		AudioSource();
		~AudioSource();

		void setSound(std::shared_ptr<Sound> _sound) { m_sound = _sound; alSourcei(m_SourceId, AL_BUFFER, m_sound->m_BufferId); }

		bool IsPlaying();
		void OnTick();
		void Play();

	private:
		
		std::shared_ptr<Sound> m_sound = nullptr;
		ALenum m_format = 0;
		ALsizei m_frequency = 0;

		ALuint m_BufferId = 0;
		ALuint m_SourceId;

		bool m_looping = false;
	};
};