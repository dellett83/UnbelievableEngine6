#include "Audio.h"
#include <stdexcept>

namespace UnbelievableEngine6
{
    Audio::Audio()
    {
        ALCdevice* device = alcOpenDevice(NULL);

        if (!device)
        {
            throw std::runtime_error("Failed to open audio device");
        }

        ALCcontext* context = alcCreateContext(device, NULL);

        if (!context)
        {
            alcCloseDevice(device);
            throw std::runtime_error("Failed to create audio context");
        }

        if (!alcMakeContextCurrent(context))
        {
            alcDestroyContext(context);
            alcCloseDevice(device);
            throw std::runtime_error("Failed to make context current");
        }

        alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
    }

    Audio::~Audio()
    {
        alcMakeContextCurrent(NULL);
        alcDestroyContext(m_context);
        alcCloseDevice(m_device);
    }
}