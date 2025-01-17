#include "Sound.h"

#include <vector>
#include <stdexcept>

#include "stb_vorbis.c"

namespace UnbelievableEngine6
{
	void Sound::onLoad()
	{
		std::vector<unsigned char> buffer;

		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;
		size_t samples = stb_vorbis_decode_filename((getPath() + ".ogg").c_str(), &channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file '" + getPath() + "' for decoding");
		}

		if (channels < 2)
		{
			m_format = AL_FORMAT_MONO16;
		}
		else
		{
			m_format = AL_FORMAT_STEREO16;
		}

		buffer.resize(samples * channels * sizeof(short));
		memcpy(&buffer.at(0), output, buffer.size());

		m_frequency = sampleRate;

		free(output);
		alGenBuffers(1, &m_BufferId);

		alBufferData(m_BufferId, m_format, &buffer.at(0), static_cast<ALsizei>(buffer.size()), m_frequency);

	}
}