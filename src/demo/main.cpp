#include <UnbelievableEngine6/UnbelievableEngine6.h>
#include <iostream>

using namespace UnbelievableEngine6;

struct Player : public Component
{
	void on_initialize()
	{
	}

	void on_tick()
	{
		if (entity()->core()->getKeyboard()->isKeyDown(SDLK_d))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(0.1f, 0.f, 0.f));
		}

		else if (entity()->core()->getKeyboard()->isKeyDown(SDLK_a))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(-0.1f, 0.f, 0.f));
		}

		else if (entity()->core()->getKeyboard()->isKeyDown(SDLK_SPACE))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(0.f, 0.1f, 0.f));
		}
	}
};

#undef main

int main() {
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ent = core->add_entity();

	ent->add_component<Player>();

	std::shared_ptr<Model> m = core->getResources()->load<Model>("models/curuthers/cat");

	std::shared_ptr<Texture> t = core->getResources()->load<Texture>("textures/cat");

	std::shared_ptr<ModelRenderer> mr = ent->add_component<ModelRenderer>();
	mr->setModel(m);
	mr->setTex(t);

	std::shared_ptr<AudioSource> as = ent->add_component<AudioSource>();

	as->setSound("../assets/audio/dixie_horn.ogg");
	as->setLooping(true);

	core->start();

	return 0;
}

//right click demo, click Set as Startup Project if all_build is not working.