#pragma once

#include <memory>
#include <vector>

#include "Audio.h"

namespace UnbelievableEngine6
{
	struct Entity;
	struct Window;
	struct Resources;
	struct Input;
	struct Keyboard;

	/**
  * @brief Core class that manages the main engine functionalities.
  */
	struct Core
	{
		/**
   * @brief Initializes the Core system.
   * 
   * @return std::shared_ptr<Core> A shared pointer to the initialized Core.
   */
		static std::shared_ptr<Core> initialize();

		/**
   * @brief Starts the main loop of the Core.
   */
		void start();

		/**
   * @brief Adds a new entity to the Core.
   * 
   * @return std::shared_ptr<Entity> A shared pointer to the newly added Entity.
   */
		std::shared_ptr<Entity> add_entity();

		/**
   * @brief Gets the window associated with the Core.
   * 
   * @return std::shared_ptr<Window> A shared pointer to the Window.
   */
		std::shared_ptr<Window> window() const;

		/**
   * @brief Gets the resource manager.
   * 
   * @return std::shared_ptr<Resources> A shared pointer to the Resources.
   */
		std::shared_ptr<Resources> getResources();

		/**
   * @brief Gets the keyboard input handler.
   * 
   * @return std::shared_ptr<Keyboard> A shared pointer to the Keyboard.
   */
		std::shared_ptr<Keyboard> getKeyboard();

		/**
   * @brief Gets the audio system.
   * 
   * @return std::shared_ptr<Audio> A shared pointer to the Audio.
   */
		std::shared_ptr<Audio> getAudio();

		/**
   * @brief Finds all components of a specific type in all entities.
   * 
   * @tparam T The type of the components to find.
   * @param _out A vector to store the found components.
   */
		template <typename T>
		void find_components(std::vector<std::shared_ptr<T>>& _out)
		{
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				std::shared_ptr<Entity> e = m_entities.at(ei);
				for (size_t ci = 0; ci < e->m_components.size(); ++ci)
				{
					std::shared_ptr<Component> c = e->m_components.at(ci);
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}

	private:
		std::vector<std::shared_ptr<Entity>> m_entities; ///< Vector of entities managed by the Core.
		std::weak_ptr<Core> m_self; ///< Weak pointer to the Core itself.
		std::shared_ptr<Window> m_window; ///< Shared pointer to the Window.
		std::shared_ptr<Audio> m_audio; ///< Shared pointer to the Audio system.
		std::shared_ptr<Resources> m_resources; ///< Shared pointer to the Resources manager.
		std::shared_ptr<Input> m_input; ///< Shared pointer to the Input handler.
	};
}