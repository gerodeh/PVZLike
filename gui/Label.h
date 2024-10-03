#pragma once

#include <SFML/Graphics.hpp>

#include "../game/Object.h"
#include "Utility_SFML.h"

#include <iostream>

#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

namespace gui
{
	class Label : public Object, public sf::Drawable
	{
		std::string m_name;
		sf::RectangleShape m_back;
		sf::Text m_text;
	private:
		static unsigned m_class_ID;
		sf::Vector2f m_backSizeOffset = sf::Vector2f(0,0);
		sf::Color m_backFillColor;
		Alignment m_labelOriginAlignment = Alignment::TopLeft;
		Alignment m_textAlignment = Alignment::TopLeft;
		bool m_backIsShown = false;
	public:

		Label();

		Label
		(
			const sf::String& _string,
			const unsigned _charSize = 3,
			const sf::String& _name = "Label"
		);

		Label
		(
			const sf::String& _string,
			const sf::Font& _font,
			const unsigned _charSize = 3,
			const sf::String& _name = "Label"
		);

		Label(const gui::Label& _label);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;
		
		void backIsShown(bool _bool);
		void alignBack();
		void alignText(Alignment _alignment);

		void setPosition(float _x, float _y);
		void setPosition(const sf::Vector2f& _pos);
		void setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void move(const sf::Vector2f& _offset);
		void move(float _offsetX, float _offsetY);
		void setRotation(float _angle);
		void setOrigin(const sf::Vector2f& _origin); // Is broken when is used with back rectangle
		void setOrigin(Alignment _alignment, float _offsetX = 0, float _offsetY = 0); // Is not recommended to use
		void setString(const sf::String& _string);
		void setFont(const sf::Font& _font);
		void setCharacterSize(unsigned _size);
		void setTextColor(const sf::Color& _color);
		void setTextOutlineColor(const sf::Color& _color);
		void setTextOutlineThickness(float _thickness);
		void setTextStyle(sf::Uint32 _style);
		void setTextScale(const sf::Vector2f& _factors); // Is the same as setScale
		void setScale(const sf::Vector2f& _factors); // Is the same as setTextScale

		void setBackSizeOffset(const sf::Vector2f& _offset);
		void setBackColor(const sf::Color& _color);
		void setBackOutlineColor(const sf::Color& _color);
		void setBackOutlineThickness(float _thickness);

		void setName(const sf::String& _name);

		const sf::Vector2f& getPosition() const;
		sf::FloatRect getGlobalBounds() const;
		const sf::Font* getFont() const;
		unsigned getCharacterSize() const;
		const sf::Color& getTextColor() const;
		const sf::Color& getTextOutlineColor() const;
		float getTextOutlineThickness() const;
		sf::Uint32 getTextStyle() const;
		const sf::Vector2f& getTextScale() const;
		const char* getString() const;
		const sf::Vector2f& getBackSize() const;

		const char* getName() const;

		unsigned getID() const;
		unsigned getClassID() const;
	};
}