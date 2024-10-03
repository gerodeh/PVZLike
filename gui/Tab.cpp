#include "Tab.h"

namespace gui
{
	unsigned Tab::m_class_ID = 0;

	Tab::Tab()
	{
		m_class_ID++;
		m_text.setString("");
		m_headerText.setString("");
	}

	Tab::Tab
	(
		const sf::Vector2f& _size,
		const sf::String& _headerString,
		const sf::Vector2f& _pos,
		const sf::String& _name
	)
	{
		m_class_ID++;
		m_rect.setSize(_size);
		m_rect.setPosition(_pos);
		m_name = _name;
	}

	void Tab::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_rect);
		target.draw(m_headerText);
		target.draw(m_text);
	}

	void Tab::alignText(Alignment _alignment, float _offsetX, float _offsetY)
	{
		m_textAlignment = _alignment;
		m_textOffsetX = _offsetX;
		m_textOffsetY = _offsetY;
		setOriginByAlignment(m_text, m_textAlignment);
		setPositionByAlignment(m_text, m_rect, m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Tab::setPosition(const sf::Vector2f& _pos)
	{
		m_rect.setPosition(_pos);
		m_pos = _pos;
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Tab::setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_rect, _target, _alignment, _offsetX, _offsetY);
		m_pos = m_rect.getPosition();
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Tab::setRotation(float _angle)
	{
		m_rect.setRotation(_angle);
		m_text.setRotation(_angle);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Tab::setOrigin(const sf::Vector2f& _origin)
	{
		m_rect.setOrigin(_origin);
	}

	void Tab::setOrigin(Alignment _alignment)
	{
		setOriginByAlignment(m_rect, _alignment);
	}

	void Tab::setRectFillColor(const sf::Color& _color)
	{
		m_rect.setFillColor(_color);
	}

	void Tab::setRectOutlineColor(const sf::Color& _color)
	{
		m_rect.setOutlineColor(_color);
	}

	void Tab::setRectOutlineThickness(float _thickness)
	{
		m_rect.setOutlineThickness(_thickness);
	}

	void Tab::setRectScale(const sf::Vector2f& _factors)
	{
		m_rect.setScale(_factors);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Tab::setRectSize(const sf::Vector2f& _size)
	{
		m_rect.setSize(_size);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Tab::setTexture(const sf::Texture* _texture, bool _resetRect)
	{
		m_rect.setTexture(_texture, _resetRect);
	}

	void Tab::setTextureRect(const sf::IntRect& _rect)
	{
		m_rect.setTextureRect(_rect);
	}

	///Getters

	const sf::RectangleShape& Tab::getRect() const
	{
		return m_rect;
	}

} /// End of namespace gui