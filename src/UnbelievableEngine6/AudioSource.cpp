#include "AudioSource.h"
#include "Transform.h"
#include <iostream>

namespace UnbelievableEngine6
{
    AudioSource::AudioSource()
    {
        alGenSources(1, &m_SourceId);
    }

    AudioSource::~AudioSource()
    {
        alDeleteSources(1, &m_SourceId);
    }

    bool AudioSource::IsPlaying()
    {
        int state = 0;
        alGetSourcei(m_SourceId, AL_SOURCE_STATE, &state);
        if (state == AL_PLAYING)
        {
            return true;
        }

        return false;
    }

    void AudioSource::OnTick()
    {
        alSource3f(m_SourceId, AL_POSITION, transform()->getPosition().x, transform()->getPosition().y, transform()->getPosition().z);
        alSourcef(m_SourceId, AL_GAIN, 1.f);

        if (m_looping && !IsPlaying())
        {
            Play();
        }
    }
    void AudioSource::Play()
    {
        alSourcePlay(m_SourceId);
    }
}