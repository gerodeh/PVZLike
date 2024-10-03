#include "Label.h"

namespace gui
{
	unsigned Label::m_class_ID = 0;

	Label::Label()
	{
		m_class_ID++;
		setOriginByAlignment(m_back, m_labelOriginAlignment);
		m_back.setFillColor(sf::Color(255,255,255,100));
		m_name = "Label";
		alignBack();
	}

	Label::Label
	(
		const sf::String& _string,
		const unsigned _charSize,
		const sf::String& _name
	)
	{
		m_class_ID++;
		m_text.setString(_string);
		m_text.setCharacterSize(_charSize);
		m_name = _name;

		setOriginByAlignment(m_back, m_labelOriginAlignment);
		m_back.setFillColor(sf::Color(255, 255, 255, 100));
		alignBack();
	}

	Label::Label
	(
		const sf::String& _string,
		const sf::Font& _font,
		const unsigned _charSize,
		const sf::String& _name
	)
	{
		m_class_ID++;
		m_text.setFont(_font);
		m_text.setString(_string);
		m_text.setCharacterSize(_charSize);
		m_name = _name;

		setOriginByAlignment(m_back, m_labelOriginAlignment);
		m_back.setFillColor(sf::Color(255, 255, 255, 100));
		alignBack();
	}

	Label::Label(const gui::Label& _label)
	{
		alignBack();
	}

	void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_backIsShown)
		{
			target.draw(m_back);
		}
		if (m_isShown)
		{
			target.draw(m_text);
		}
	}
		          
	void Label::backIsShown(bool _bool)
	{
		m_backIsShown = _bool;
	}

	void Label::alignBack()
	{
		m_back.setSize(sf::Vector2f(m_text.getGlobalBounds().width + m_backSizeOffset.x, m_text.getGlobalBounds().height + m_backSizeOffset.y));
		//m_back.setPosition(m_text.getPosition());
		alignText(m_textAlignment);
	}

	void Label::alignText(Alignment _alignment)
	{
		m_textAlignment = _alignment;
		setOriginByAlignment(m_text, m_textAlignment);
		setPositionByAlignment(m_text, m_back, _alignment);
	}

	void Label::setPosition(float _x, float _y)
	{
		m_back.setPosition(_x, _y);
		m_pos.x = _x;
		m_pos.y = _y;
		alignText(m_textAlignment);
	}

	void Label::setPosition(const sf::Vector2f& _pos)
	{
		m_back.setPosition(_pos);
		m_pos = _pos;
		alignText(m_textAlignment);
	}

	void Label::setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_back, _target, _alignment, _offsetX, _offsetY);
		m_pos = m_back.getPosition();
		alignText(m_textAlignment);
	}

	void Label::setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_back, _target, _alignment, _offsetX, _offsetY);
		m_pos = m_back.getPosition();
		alignText(m_textAlignment);
	}

	void Label::move(const sf::Vector2f& _offset)
	{
		m_back.move(_offset);
		m_pos.x = m_pos.x + _offset.x;
		m_pos.y = m_pos.y + _offset.y;
		alignText(m_textAlignment);
	}

	void Label::move(float _offsetX, float _offsetY)
	{
		m_back.move(_offsetX, _offsetY);
		m_pos.x = m_pos.x + _offsetX;
		m_pos.y = m_pos.y + _offsetY;
		alignText(m_textAlignment);
	}

	void Label::setRotation(float _angle)
	{
		m_text.setRotation(_angle);
		alignBack();
	}

	void Label::setOrigin(const sf::Vector2f& _origin)
	{
		m_labelOriginAlignment = Alignment::NONE;
		m_back.setOrigin(_origin);
	}

	void Label::setOrigin(Alignment _alignment, float _offsetX, float _offsetY)
	{
		m_labelOriginAlignment = _alignment;
		setOriginByAlignment(m_back, _alignment, _offsetX, _offsetY);
		//alignText(m_textAlignment);
	}

	void Label::setString(const sf::String& _string)
	{
		m_text.setString(_string);
		alignBack();
		//this->setPosition(m_pos);
	}

	void Label::setFont(const sf::Font& _font)
	{
		m_text.setFont(_font);
		alignBack();
	}

	void Label::setCharacterSize(unsigned _size)
	{
		m_text.setCharacterSize(_size); 
		alignBack();
	}

	void Label::setTextColor(const sf::Color& _color)
	{
		m_text.setFillColor(_color);
	}

	void Label::setTextOutlineColor(const sf::Color& _color)
	{
		m_text.setOutlineColor(_color);
		alignBack();
	}

	void Label::setTextOutlineThickness(float _thickness)
	{
		m_text.setOutlineThickness(_thickness);
		alignBack();
	}

	void Label::setTextStyle(sf::Uint32 _style)
	{
		m_text.setStyle(_style);
		alignBack();
	}

	void Label::setTextScale(const sf::Vector2f& _factors)
	{
		m_text.setScale(_factors);
		alignBack();
	}

	void Label::setScale(const sf::Vector2f& _factors)
	{
		m_text.setScale(_factors);
		alignBack();
	}

	void Label::setBackSizeOffset(const sf::Vector2f& _offset)
	{
		m_backSizeOffset = _offset;
	}

	void Label::setBackColor(const sf::Color& _color)
	{
		m_back.setFillColor(_color);
	}

	void Label::setBackOutlineColor(const sf::Color& _color)
	{
		m_back.setOutlineColor(_color);
	}

	void Label::setBackOutlineThickness(float _thickness)
	{
		m_back.setOutlineThickness(_thickness);
	}

	void Label::setName(const sf::String& _name)
	{
		m_name = _name;
	}

	//GETTERS

	const sf::Vector2f& Label::getPosition() const
	{
		return m_text.getPosition();
	}

	sf::FloatRect Label::getGlobalBounds() const
	{
		return m_text.getGlobalBounds();
	}

	const sf::Font* Label::getFont() const
	{
		return m_text.getFont();
	}

	unsigned Label::getCharacterSize() const
	{
		return m_text.getCharacterSize();
	}

	const sf::Color& Label::getTextColor() const
	{
		return m_text.getFillColor();
	}

	const sf::Color& Label::getTextOutlineColor() const
	{
		return m_text.getOutlineColor();
	}

	float Label::getTextOutlineThickness() const
	{
		return m_text.getOutlineThickness();
	}

	sf::Uint32 Label::getTextStyle() const
	{
		return m_text.getStyle();
	}

	const sf::Vector2f& Label::getTextScale() const
	{
		return m_text.getScale();
	}

	const char* Label::getString() const
	{
		return m_text.getString().toAnsiString().c_str();
	}

	const sf::Vector2f& Label::getBackSize() const
	{
		return m_back.getSize();
	}

	const char* Label::getName() const
	{
		return m_name.c_str();
	}

	unsigned Label::getID() const
	{
		return m_ID;
	}

	unsigned Label::getClassID() const
	{
		return m_class_ID;
	}
}