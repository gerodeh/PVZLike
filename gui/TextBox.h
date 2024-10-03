#pragma once

#include <SFML/Graphics.hpp>

#include "../game/Object.h"
#include "Utility_SFML.h"
#include "Label.h"
#include "Tooltip.h"

#include <iostream>
#include <sstream>

#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

namespace gui
{
	class TextBox : public Object, public sf::Drawable
	{
	public:
		TextBox();

		TextBox(int _charsize, const sf::Color& _color, bool _sel);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

		void setLimit(bool _bool);
		void setLimit(bool _bool, int _lim);
		void setSelected(bool _bool);
		void typedOn(sf::Event _event);
		void backIsShown(bool _bool);
		void alignText(Alignment _alignment);
		bool isPressed(sf::Event& _event, const sf::RenderWindow& _window);
		bool isPressed(sf::Event& _event, const sf::RenderWindow& _window, const sf::Mouse::Button& _btn);
		bool isPointedByMouse(const sf::RenderWindow& _window);
		void highlight(const sf::Color& _color);
		void disableHighlight();

		void setString(const sf::String& _str);
		void setFont(const sf::Font& _font);
		void setCharacterSize(unsigned _size);
		void setTextColor(const sf::Color& _color);
		void setTextOutlineColor(const sf::Color& _color);
		void setTextOutlineThickness(float _thickness);
		void setTextStyle(sf::Uint32 _style);
		void setTextScale(const sf::Vector2f& _factors);

		void setRectColor(const sf::Color& _color);
		void setRectOutlineColor(const sf::Color& _color);
		void setRectOutlineThickness(float _thickness);
		void setSize(const sf::Vector2f& _size);
		void setPosition(float _x, float _y);
		void setPosition(const sf::Vector2f& _pos);
		void setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void move(const sf::Vector2f& _offset);
		void move(float _offsetX, float _offsetY);
		void setRotation(float _angle); // WIP
		void setOrigin(const sf::Vector2f& _origin);
		void setOrigin(Alignment _alignment, float _offsetX = 0.f, float _offsetY = 0.f);

		void setBackSizeOffset(const sf::Vector2f& _offset);
		void setBackColor(const sf::Color& _color);
		void setBackOutlineColor(const sf::Color& _color);
		void setBackOutlineThickness(float _thickness);

		bool isEmpty() const;

		std::string getString() const;
		const char* getCstring() const; // Doesn't work?
		const sf::Color& getRectColor() const;

	public: bool m_onlyNumbers = false;
	public: bool m_enterUndoSelect = false;
	private:
		void alignTextBox();

		std::string m_name;
		static unsigned m_class_ID;

		sf::RectangleShape m_rect;
		Label m_textbox;
		std::ostringstream m_text;
		bool m_isSelected = false;
		bool m_hasLimit = false;
		int m_limit;
		bool m_isHighlighted = false;
		sf::Color m_colorHolder;

		void inputLogic(int _charTyped);

		void deleteLastChar(int _num = 1);
	};
}