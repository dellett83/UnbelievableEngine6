#include <UnbelievableEngine6/UnbelievableEngine6.h>
#include <iostream>

using namespace UnbelievableEngine6;

struct Test : Component
{
	int m_temp;
};

int main() {
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ent = core->add_entity();

	ent->add_component<Test>();

	core->start();

	return 0;
}

//right click demo, click Set as Startup Project if all_build is not working.