#pragma once

#include <SFML/Graphics.hpp>

#include "../game/Object.h"
#include "Utility_SFML.h"

#include <iostream>

#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

namespace gui
{
	class Caption : public Object, public sf::Transformable, public sf::Drawable
	{
		std::string m_name;
		sf::RectangleShape m_backrect;
		sf::Text m_text;
	private:
		Alignment m_textAlignment = Alignment::Center;
		float m_textOffsetX = 0;
		float m_textOffsetY = 0;
		static unsigned m_class_ID;
	public:
		Caption();
	};
}