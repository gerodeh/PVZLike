#pragma once

#include <SFML/Graphics.hpp>

#include "../game/Object.h"
#include "Utility_SFML.h"

#include <iostream>

#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

namespace gui
{
    class Tab : public Object, public sf::Transformable, public sf::Drawable
    {
		std::string m_name;
		sf::RectangleShape m_rect;
		sf::Text m_headerText;
		sf::Text m_text;
	private:
		Alignment m_headerTextAlignment = Alignment::Top;
		float m_headerTextOffsetX = 0;
		float m_headerTextOffsetY = 0;
		Alignment m_textAlignment = Alignment::Center;
		float m_textOffsetX = 0;
		float m_textOffsetY = 0;
		static unsigned m_class_ID;
    public:

        Tab();

		Tab
		(
			const sf::Vector2f& _size,
			const sf::String& _headerString = "",
			const sf::Vector2f& _pos = sf::Vector2f(0,0),
			const sf::String& _name = "Tab"
		);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;
		
		void alignText(Alignment _alignment = Alignment::Center, float _offsetX = 0, float _offsetY = 0);

		void setPosition(const sf::Vector2f& _pos);
		void setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setRotation(float _angle);
		void setOrigin(const sf::Vector2f& _origin);
		void setOrigin(Alignment _alignment);
		void setRectFillColor(const sf::Color& _color);
		void setRectOutlineColor(const sf::Color& _color);
		void setRectOutlineThickness(float _thickness);
		void setRectScale(const sf::Vector2f& _factors);
		void setRectSize(const sf::Vector2f& _size);
		void setTexture(const sf::Texture* _texture, bool _resetRect = false);
		void setTextureRect(const sf::IntRect& _rect);

		const sf::RectangleShape& getRect() const;
    }; 

} /// End of namespace gui

