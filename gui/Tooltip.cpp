#include "Tooltip.h"

namespace gui
{
	Tooltip::Tooltip()
	{
		m_lbl.setCharacterSize(30);
		m_lbl.setTextColor(sf::Color(255, 255, 255));
		m_lbl.setBackColor(sf::Color(140, 140, 140, 200));
		m_lbl.backIsShown(true);
	}

	Tooltip::Tooltip
	(
		const sf::String& _str,
		const sf::Font& _font,
		unsigned _charSize,
		const sf::Color& _textColor,
		const sf::Color& _backColor
	)
	{
		m_lbl.setFont(_font);
		m_lbl.setString(_str);
		m_lbl.setCharacterSize(_charSize);
		m_lbl.setBackColor(_backColor);
		m_lbl.setTextColor(_textColor);
		m_lbl.backIsShown(true);
	}

	void Tooltip::showAndUpdateToolTip(const sf::RenderTarget& _target)
	{
		m_lbl.setPosition(sf::Vector2f(_target.mapPixelToCoords(sf::Mouse::getPosition()).x + 11,
			_target.mapPixelToCoords(sf::Mouse::getPosition()).y + 11));
		m_isShown = true;
	}

	void Tooltip::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_isShown && !m_doNotShowToolTip)
		{
			target.draw(m_lbl);
		}
	}

	void Tooltip::backIsShown(bool _bool)
	{
		m_lbl.backIsShown(_bool);
	}

	void Tooltip::alignText(Alignment _alignment)
	{
		m_lbl.alignText(_alignment);
	}


	void Tooltip::setPosition(const sf::Vector2f& _pos)
	{
		m_lbl.setPosition(_pos);
	}

	void Tooltip::setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX, float _offsetY)
	{
		m_lbl.setPosition(_alignment, _target, _offsetX, _offsetY);
	}

	void Tooltip::setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX, float _offsetY)
	{
		m_lbl.setPosition(_alignment, _target, _offsetX, _offsetY);
	}

	void Tooltip::setRotation(float _angle)
	{
		m_lbl.setRotation(_angle);
	}

	void Tooltip::setOrigin(const sf::Vector2f& _origin)
	{
		m_lbl.setOrigin(_origin);
	}

	void Tooltip::setOrigin(Alignment _alignment, float _offsetX, float _offsetY)
	{
		m_lbl.setOrigin(_alignment, _offsetX, _offsetY);
	}

	void Tooltip::setString(const sf::String& _string)
	{
		m_lbl.setString(_string);
	}

	void Tooltip::setFont(const sf::Font& _font)
	{
		m_lbl.setFont(_font);
	}

	void Tooltip::setCharacterSize(unsigned _size)
	{
		m_lbl.setCharacterSize(_size);
	}

	void Tooltip::setTextColor(const sf::Color& _color)
	{
		m_lbl.setTextColor(_color);
	}

	void Tooltip::setTextOutlineColor(const sf::Color& _color)
	{
		m_lbl.setTextOutlineColor(_color);
	}

	void Tooltip::setTextOutlineThickness(float _thickness)
	{
		m_lbl.setTextOutlineThickness(_thickness);
	}

	void Tooltip::setTextStyle(sf::Uint32 _style)
	{
		m_lbl.setTextStyle(_style);
	}

	void Tooltip::setTextScale(const sf::Vector2f& _factors)
	{
		m_lbl.setTextScale(_factors);
	}

	void Tooltip::setBackSizeOffset(const sf::Vector2f& _offset)
	{
		m_lbl.setBackSizeOffset(_offset);
	}

	void Tooltip::setBackColor(const sf::Color& _color)
	{
		m_lbl.setBackColor(_color);
	}

	void Tooltip::setBackOutlineColor(const sf::Color& _color)
	{
		m_lbl.setBackOutlineColor(_color);
	}

	void Tooltip::setBackOutlineThickness(float _thickness)
	{
		m_lbl.setBackOutlineThickness(_thickness);
	}

	//GETTERS

	const sf::Font* Tooltip::getFont() const
	{
		return m_lbl.getFont();
	}

	unsigned Tooltip::getCharacterSize() const
	{
		return m_lbl.getCharacterSize();
	}

	const sf::Color& Tooltip::getTextColor() const
	{
		return m_lbl.getTextColor();
	}

	const sf::Color& Tooltip::getTextOutlineColor() const
	{
		return m_lbl.getTextOutlineColor();
	}

	float Tooltip::getTextOutlineThickness() const
	{
		return m_lbl.getTextOutlineThickness();
	}

	sf::Uint32 Tooltip::getTextStyle() const
	{
		return m_lbl.getTextStyle();
	}

	const sf::Vector2f& Tooltip::getTextScale() const
	{
		return m_lbl.getTextScale();
	}

	const char* Tooltip::getString() const
	{
		return m_lbl.getString();
	}

	const sf::Vector2f& Tooltip::getBackSize() const
	{
		return m_lbl.getBackSize();
	}
}