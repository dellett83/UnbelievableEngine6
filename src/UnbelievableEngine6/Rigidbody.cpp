#include "Rigidbody.h"
#include "Entity.h"
#include "Core.h"
#include "Component.h"
#include "BoxCollider.h"

#include <vector>
#include <iostream>

namespace UnbelievableEngine6
{
	void Rigidbody::on_tick()
	{
		std::vector<std::shared_ptr<BoxCollider>> boxColliders;
		entity()->core()->find_components(boxColliders);
		for (auto boxCollider : boxColliders)
		{
			if (boxCollider->transform() == transform())
			{
				continue;
			}
			if (boxCollider->isColliding(entity()->get_component<BoxCollider>()))
			{
				std::cout << "hit" << std::endl;
			}
			else
			{
				std::cout << "not hit" << std::endl;
			}
		}
	}
}