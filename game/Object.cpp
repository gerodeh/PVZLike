#include "Object.h"


unsigned Object::m_ID = -1;

Object::Object()
{
	m_ID++;
}

void Object::ImGui()
{

}

void Object::setPosition(const sf::Vector2f& _pos)
{

}

void Object::setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX, float _offsetY)
{

}

const sf::Vector2f& Object::getPosition() const
{
	return m_pos;
}
