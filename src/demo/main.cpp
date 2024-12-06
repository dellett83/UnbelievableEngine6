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
	}
};

int main() {
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ent = core->add_entity();

	ent->add_component<Player>();

	std::shared_ptr<Model> m = core->getResources()->load<Model>("models/curuthers/cat");

	std::shared_ptr<ModelRenderer> mr = ent->add_component<ModelRenderer>();
	//mr->setModel(m);


	core->start();

	return 0;
}

//right click demo, click Set as Startup Project if all_build is not working.