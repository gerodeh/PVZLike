#pragma once

#include "../gui/Utility_SFML.h"
#include <SFML/Graphics.hpp>



class Object : public sf::Transformable
{
protected:
	sf::Transform m_transform;
	sf::Vector2f m_pos;
	static unsigned m_ID;
public:
	bool m_isShown = true;  

	Object();

	void ImGui();

	void setPosition(const sf::Vector2f& _pos);
	void setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX = 0.f, float _offsetY = 0.f);

	const sf::Vector2f& getPosition() const;

	unsigned getID() const;
};
