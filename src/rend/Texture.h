#include <GL/glew.h>

#include <vector>
#include <string>

namespace rend
{

	struct Texture
	{
	private:
		int m_width;
		int m_height;
		bool m_dirty;

		GLuint m_id;

		std::vector<unsigned char> m_data;

	public:
		Texture();
		Texture(const std::string& _path);

		GLuint getId();


	};
}