#include <UnbelievableEngine6/UnbelievableEngine6.h>
#include <iostream>

using namespace UnbelievableEngine6;

struct Player : public Component
{
	int m_temp;
	void on_initialize()
	{
		printf("dan");
	}

	void on_tick()
	{
		printf("dan");
	}
};

int main() {
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ent = core->add_entity();

	ent->add_component<Player>();

	core->start();

	return 0;
}

//right click demo, click Set as Startup Project if all_build is not working.