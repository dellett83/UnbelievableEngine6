#include "Component.h"

namespace UnbelievableEngine6
{
	void Component::on_initialize() {}
	void Component::on_tick() {}

	void Component::tick()
	{
		on_tick();
	}
}