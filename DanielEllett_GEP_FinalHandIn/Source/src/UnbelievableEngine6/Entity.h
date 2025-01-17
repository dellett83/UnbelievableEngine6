#pragma once

#include <memory>
#include <vector>

namespace UnbelievableEngine6
{
	struct Core;
	struct Component;

	/**
  * @brief Represents an entity in the engine.
  */
	struct Entity
	{
		/**
   * @brief Adds a new component to the entity.
   * 
   * @tparam T The type of the component to add.
   * @return std::shared_ptr<T> A shared pointer to the newly added component.
   */
		template<typename T>
		std::shared_ptr<T> add_component()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			
			rtn->m_entity = m_self;
			rtn->on_initialize();
			m_components.push_back(rtn);

			return rtn;
		}

		/**
   * @brief Gets a component of the specified type from the entity.
   * 
   * @tparam T The type of the component to get.
   * @return std::shared_ptr<T> A shared pointer to the component.
   * @throws std::runtime_error If the component is not found.
   */
		template<typename T>
		std::shared_ptr<T> get_component()
		{
			for (size_t ci = 0; ci < m_components.size(); ++ci)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_components.at(ci));

				if (rtn) return rtn;
			}
			throw std::runtime_error("Failed to find component");
		}

		/**
   * @brief Gets the core system that this entity is part of.
   * 
   * @return std::shared_ptr<Core> A shared pointer to the Core.
   */
		std::shared_ptr<Core> core()
		{
			return m_core.lock();
		}

	private:
		friend struct UnbelievableEngine6::Core;

		std::weak_ptr<Core> m_core; ///< Weak pointer to the Core system.
		std::weak_ptr<Entity> m_self; ///< Weak pointer to the entity itself.
		std::vector<std::shared_ptr<Component>> m_components; ///< Vector of components attached to the entity.

		/**
   * @brief Updates all components of the entity.
   */
		void tick();

		/**
   * @brief Renders all components of the entity.
   */
		void on_render();
	};

}