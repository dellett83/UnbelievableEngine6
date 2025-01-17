#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace UnbelievableEngine6
{
	struct Entity;
	struct Transform;

	/**
  * @brief Base class for all components in the engine.
  */
	struct Component
	{
	public:
		/**
   * @brief Called when the component is initialized.
   */
		virtual void on_initialize();

		/**
   * @brief Called every frame to update the component.
   */
		virtual void on_tick();

		/**
   * @brief Called every frame to render the component.
   */
		virtual void on_render();

		/**
   * @brief Gets the entity that this component is attached to.
   * 
   * @return std::shared_ptr<Entity> A shared pointer to the entity.
   */
		std::shared_ptr<Entity> entity();

		/**
   * @brief Gets the transform component of the entity.
   * 
   * @return std::shared_ptr<Transform> A shared pointer to the transform component.
   */
		std::shared_ptr<Transform> transform();

		/**
   * @brief Gets the position of the entity.
   * 
   * @return glm::vec3 The position of the entity.
   */
		glm::vec3 position();

		/**
   * @brief Sets the position of the entity.
   * 
   * @param _position The new position of the entity.
   */
		void setPosition(glm::vec3 _position);

	private:
		friend struct Entity;

		/**
   * @brief Updates the component by calling the on_tick method.
   */
		void tick();

		std::weak_ptr<Entity> m_entity; ///< Weak pointer to the entity that this component is attached to.
	};
}