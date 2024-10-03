#include "CheckBox.h"

namespace gui
{
	unsigned CheckBox::m_class_ID = 0;

	CheckBox::CheckBox()
	{
		m_class_ID++;
		m_name = "CheckBox";
		m_rectChecked.setFillColor(sf::Color(10,10,10));
		setOriginByAlignment(m_rectChecked, Alignment::Center);
	}

	CheckBox::CheckBox
	(
		const sf::Vector2f& _size,
		const sf::Color& _color,
		const sf::Color& _colorChecked,
		const sf::Vector2f& _pos,
		const sf::String& _name
	)
	{
		m_rect.setSize(_size); m_rectChecked.setSize(sf::Vector2f(_size.x - _size.x * 0.1f, _size.y - _size.y * 0.1f));
		m_rect.setFillColor(_color);
		m_rectChecked.setFillColor(_colorChecked);
		setOriginByAlignment(m_rectChecked, Alignment::Center);
		m_rect.setPosition(_pos); m_rectChecked.setPosition(_pos);
		m_name = _name;
	}

	void CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_isShown)
		{
			target.draw(m_rect);
			if (m_isActive) target.draw(m_rectChecked);
		}
	}

	bool CheckBox::isPressed(sf::Event& _event, const sf::RenderTarget& _window)
	{
		if (_event.type == sf::Event::MouseButtonReleased) {
			if (m_rect.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition())) || m_rectChecked.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition())))
			{
				return true;
			}
		}
		return false;
	}

	void CheckBox::setPosition(const sf::Vector2f& _pos)
	{
		m_rect.setPosition(_pos);
		setPositionByAlignment(m_rectChecked, m_rect, Alignment::Center);
		m_pos = _pos;
	}

	void CheckBox::setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_rect, _target, _alignment, _offsetX, _offsetY);
		setPositionByAlignment(m_rectChecked, m_rect, Alignment::Center);
		m_pos = m_rect.getPosition();
	}

	void CheckBox::setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_rect, _target, _alignment, _offsetX, _offsetY);
		setPositionByAlignment(m_rectChecked, m_rect, Alignment::Center);
		m_pos = m_rect.getPosition();
	}

	void CheckBox::setRotation(float _angle)
	{
		m_rect.setRotation(_angle);
		m_rectChecked.setRotation(_angle);
	}

	void CheckBox::setOrigin(const sf::Vector2f& _origin)
	{
		m_rect.setOrigin(_origin);
	}

	void CheckBox::setOrigin(Alignment _alignment)
	{
		setOriginByAlignment(m_rect, _alignment);
	}

	void CheckBox::setRectFillColor(const sf::Color& _color)
	{
		m_rect.setFillColor(_color);
	}

	void CheckBox::setRectOutlineColor(const sf::Color& _color)
	{
		m_rect.setOutlineColor(_color);
	}

	void CheckBox::setRectOutlineThickness(float _thickness)
	{
		m_rect.setOutlineThickness(_thickness);
	}

	void CheckBox::setTickedRectFillColor(const sf::Color& _color)
	{
		m_rectChecked.setFillColor(_color);
	}

	void CheckBox::setTickedRectOutlineColor(const sf::Color& _color)
	{
		m_rectChecked.setOutlineColor(_color);
	}

	void CheckBox::setTickedRectOutlineThickness(float _thickness)
	{
		m_rectChecked.setOutlineThickness(_thickness);
	}

	void CheckBox::setRectScale(const sf::Vector2f& _factors)
	{
		m_rect.setScale(_factors);
		m_rectChecked.setScale(sf::Vector2f(_factors.x - _factors.x * 0.1f, _factors.y - _factors.y * 0.1f));
		setOriginByAlignment(m_rectChecked, Alignment::Center);
		setPositionByAlignment(m_rectChecked, m_rect, Alignment::Center);
	}

	void CheckBox::setRectSize(const sf::Vector2f& _size)
	{
		m_rect.setSize(_size);
		m_rectChecked.setSize(sf::Vector2f(_size.x - _size.x * 0.1f, _size.y - _size.y * 0.1f));
		setOriginByAlignment(m_rectChecked, Alignment::Center);
		setPositionByAlignment(m_rectChecked, m_rect, Alignment::Center);
	}

	void CheckBox::setTexture(const sf::Texture* _texture, bool _resetRect)
	{
		m_rect.setTexture(_texture, _resetRect);
	}

	void CheckBox::setTextureRect(const sf::IntRect& _rect)
	{
		m_rect.setTextureRect(_rect);
	}

	void CheckBox::setTickedTexture(const sf::Texture* _texture, bool _resetRect)
	{
		m_rectChecked.setTexture(_texture, _resetRect);
	}

	void CheckBox::setTickedTextureRect(const sf::IntRect& _rect)
	{
		m_rectChecked.setTextureRect(_rect);
	}
}