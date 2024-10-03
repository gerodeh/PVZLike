#pragma once

#include <SFML/Graphics.hpp>
#include "Utility_SFML.h"
#include "../game/Object.h"
#include "Label.h"

namespace gui
{
	class Tooltip : public Object, public sf::Drawable
	{
		Label m_lbl;
	public:

		void showAndUpdateToolTip(const sf::RenderTarget& _target);
		bool m_isShown = false;
		bool m_doNotShowToolTip = true;

		Tooltip();
		Tooltip
		(
			const sf::String& _str,
			const sf::Font& _font,
			unsigned _charSize = 30,
			const sf::Color& _textColor = sf::Color(255, 255, 255),
			const sf::Color& _backColor = sf::Color(140, 140, 140, 200)
		);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

		void alignText(Alignment _alignment);
		void backIsShown(bool _bool);

		void setPosition(const sf::Vector2f& _pos);
		void setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setRotation(float _angle);
		void setOrigin(const sf::Vector2f& _origin); // Is broken when is used with back rectangle
		void setOrigin(Alignment _alignment, float _offsetX = 0, float _offsetY = 0);
		void setString(const sf::String& _string);
		void setFont(const sf::Font& _font);
		void setCharacterSize(unsigned _size);
		void setTextColor(const sf::Color& _color);
		void setTextOutlineColor(const sf::Color& _color);
		void setTextOutlineThickness(float _thickness);
		void setTextStyle(sf::Uint32 _style);
		void setTextScale(const sf::Vector2f& _factors);

		void setBackSizeOffset(const sf::Vector2f& _offset);
		void setBackColor(const sf::Color& _color);
		void setBackOutlineColor(const sf::Color& _color);
		void setBackOutlineThickness(float _thickness);

		const sf::Font* getFont() const;
		unsigned getCharacterSize() const;
		const sf::Color& getTextColor() const;
		const sf::Color& getTextOutlineColor() const;
		float getTextOutlineThickness() const;
		sf::Uint32 getTextStyle() const;
		const sf::Vector2f& getTextScale() const;
		const char* getString() const;
		const sf::Vector2f& getBackSize() const;
	};
}
