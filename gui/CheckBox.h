#pragma once

#include <SFML/Graphics.hpp>

#include "../game/Object.h"
#include "Utility_SFML.h"

#include <iostream>

#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

namespace gui
{
	class CheckBox : public Object, public sf::Drawable
	{
		std::string m_name;
		sf::RectangleShape m_rect;
		sf::RectangleShape m_rectChecked;
	private:
		static unsigned m_class_ID;
	public:
		bool m_isShown = true;
		bool m_isActive = false;

		CheckBox();

		CheckBox
		(
			const sf::Vector2f& _size,
			const sf::Color& _color = sf::Color(255, 255, 255),
			const sf::Color& _colorChecked = sf::Color(10, 10, 10),
			const sf::Vector2f& _pos = sf::Vector2f(0.f,0.f),
			const sf::String& _name = sf::String("CheckBox")
		);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

		bool isPressed(sf::Event& _event, const sf::RenderTarget& _window);

		void setPosition(const sf::Vector2f& _pos);
		void setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setRotation(float _angle);
		void setOrigin(const sf::Vector2f& _origin);
		void setOrigin(Alignment _alignment);
		void setRectFillColor(const sf::Color& _color);
		void setRectOutlineColor(const sf::Color& _color);
		void setRectOutlineThickness(float _thickness);
		void setTickedRectFillColor(const sf::Color& _color);
		void setTickedRectOutlineColor(const sf::Color& _color);
		void setTickedRectOutlineThickness(float _thickness);
		void setRectScale(const sf::Vector2f& _factors);
		void setRectSize(const sf::Vector2f& _size);
		void setTexture(const sf::Texture* _texture, bool _resetRect = false);
		void setTextureRect(const sf::IntRect& _rect);
		void setTickedTexture(const sf::Texture* _texture, bool _resetRect = false);
		void setTickedTextureRect(const sf::IntRect& _rect);
	};
}