#pragma once

#include <SFML/Graphics.hpp>

#include "../game/Object.h"
#include "../gui/Label.h"
#include "../gui/Tooltip.h"
#include "Utility_SFML.h"

#include <iostream>

#include "../imgui/imgui.h"
#include "../imgui/imgui-SFML.h"

namespace gui
{

	class Button : public Object, public sf::Drawable
	{
		std::string m_name;
		sf::RectangleShape m_rect;
		sf::Text m_text;
	public: gui::Tooltip m_tooltip;
	private:
		Alignment m_textAlignment = Alignment::Center;
		float m_textOffsetX = 0;
		float m_textOffsetY = 0;
		static unsigned m_class_ID;
		sf::Color m_rectFillColor; 
		sf::Color m_rectFillColorAdditional; // absolutely useless
		sf::Color m_colorHolder; /// it's needed to hold main color while changing it to highlighted
	public: 
		bool m_isHighlighted = false;

		Button();

		Button
		(
			const sf::Vector2f& _size,
			const sf::String& _string = "",
			const sf::Vector2f& _pos = sf::Vector2f(0, 0),
			const sf::String& _name = "Button"
		);

		Button(const gui::Button& _button);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

		void ImGui();
		bool isPressed(sf::Event& _event, const sf::RenderWindow& _window);
		bool isPressed(sf::Event& _event, const sf::RenderWindow& _window, const sf::Mouse::Button& _btn);
		bool isPointedByMouse(const sf::RenderWindow& _window);
		void alignText(Alignment _alignment = Alignment::Center, float _offsetX = 0, float _offsetY = 0);
		void highlight(const sf::Color& _color);
		void disableHighlight();

		void setString(const sf::String& _string);
		void setFont(const sf::Font& _font);
		void setCharacterSize(unsigned _size);
		void setTextColor(const sf::Color& _color);
		void setTextOutlineColor(const sf::Color& _color);
		void setTextOutlineThickness(float _thickness);
		void setTextStyle(sf::Uint32 _style);
		void setTextScale(const sf::Vector2f& _factors);
		
		void setPosition(float _x ,float _y);
		void setPosition(const sf::Vector2f& _pos);
		void setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX = 0.f, float _offsetY = 0.f);
		void move(const sf::Vector2f& _offset);
		void move(float _offsetX, float _offsetY);
		void setRotation(float _angle);
		void setOrigin(const sf::Vector2f& _origin);
		void setOrigin(Alignment _alignment);
		void setRectFillColor(const sf::Color& _color);
		void setRectFillColorAdditional(const sf::Color& _color);
		void setRectOutlineColor(const sf::Color& _color);
		void setRectOutlineThickness(float _thickness);
		void setRectScale(const sf::Vector2f& _factors);
		void setRectSize(const sf::Vector2f& _size);
		void setTexture(const sf::Texture* _texture, bool _resetRect = false);
		void setTextureRect(const sf::IntRect& _rect);
		void setName(const sf::String& _str);

		const sf::Font* getFont() const;
		unsigned getCharacterSize() const;
		const sf::Color& getTextColor() const;
		const sf::Color& getTextOutlineColor() const;
		float getTextOutlineThickness() const;
		sf::Uint32 getTextStyle() const;
		const sf::Vector2f& getTextScale() const;
		const char* getString() const;

		const sf::Vector2f& getPosition() const;
		const sf::Vector2f& getOrigin() const;
		float getRotation() const;
		const sf::Color& getRectFillColor() const;
		const sf::Color& getRectFillColorAdditional() const;
		const sf::Color& getRectOutlineColor() const;
		float getRectOutlineThickness() const;
		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;
		const sf::Vector2f& getRectScale() const;
		const sf::Vector2f& getRectSize() const;
		const sf::Transform& getRectTransform() const;
		const sf::Texture* getTexture() const;
		const sf::IntRect& getTextureRect() const;

		const Alignment& getTextAlignment() const;
		float getTextOffsetX() const;
		float getTextOffsetY() const;
		const gui::Button& getButton() const;
		const char* getName() const;
		bool& isHighlighted();

		unsigned getID() const;
		unsigned getClassID() const;
	};
}