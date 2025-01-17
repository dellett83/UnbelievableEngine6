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
		if (entity()->core()->getKeyboard()->isKeyPressed(SDLK_d))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(0.1f, 0.f, 0.f));
			entity()->get_component<AudioSource>()->Play();
		}

		else if (entity()->core()->getKeyboard()->isKeyPressed(SDLK_a))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(-0.1f, 0.f, 0.f));
			entity()->get_component<AudioSource>()->Play();
		}

		if (entity()->core()->getKeyboard()->isKeyPressed(SDLK_w))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(0.f, 0.f, 0.1f));
			entity()->get_component<AudioSource>()->Play();
		}

		else if (entity()->core()->getKeyboard()->isKeyPressed(SDLK_s))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(0.f, 0.f, -0.1f));
			entity()->get_component<AudioSource>()->Play();
		}

		else if (entity()->core()->getKeyboard()->isKeyPressed(SDLK_SPACE))
		{
			transform()->setPosition(transform()->getPosition() + glm::vec3(0.f, 0.1f, 0.f));
		}
	}
};

#undef main

int main() {
	std::shared_ptr<Core> core = Core::initialize();

  //Entity 1
	std::shared_ptr<Entity> ent = core->add_entity();
	ent->add_component<Player>();
	std::shared_ptr<ModelRenderer> mr = ent->add_component<ModelRenderer>();
	std::shared_ptr<Model> m = core->getResources()->load<Model>("models/curuthers/cat");
	std::shared_ptr<Texture> t = core->getResources()->load<Texture>("textures/cat");
	mr->setModel(m);
	mr->setTex(t);

	ent->get_component<Transform>()->setPosition(glm::vec3(-1.5f, 0.f, -10.f));

	std::shared_ptr<BoxCollider> bc = ent->add_component<BoxCollider>();
	bc->setOffset(glm::vec3(0, 0.3f, 0.5f));
	bc->setSize(ent->get_component<Transform>()->getScale());
	ent->add_component<Rigidbody>();

  //Entity 2
	std::shared_ptr<Entity> ent2 = core->add_entity();
	std::shared_ptr<ModelRenderer> mr2 = ent2->add_component<ModelRenderer>();
	std::shared_ptr<Model> m2 = core->getResources()->load<Model>("models/grass/grass");
	std::shared_ptr<Texture> t2 = core->getResources()->load<Texture>("textures/grass");
	mr2->setModel(m2);
	mr2->setTex(t2);

	ent2->get_component<Transform>()->setPosition(glm::vec3(1.5f, 0.f, -10.f));

	std::shared_ptr<BoxCollider> bc2 = ent2->add_component<BoxCollider>();
	bc2->setOffset(glm::vec3(0, 0.3f, 0.5f));
	bc2->setSize(ent2->get_component<Transform>()->getScale());
	ent2->add_component<Rigidbody>();

	std::shared_ptr<AudioSource> as = ent->add_component<AudioSource>();
	std::shared_ptr<Sound> sound = core->getResources()->load<Sound>("audio/footstep");

	as->setSound(sound);

	core->start();

	return 0;
}

//right click demo, click Set as Startup Project if all_build is not working.