#include "TextBox.h"

namespace gui
{
	unsigned TextBox::m_class_ID = 0;

	TextBox::TextBox()
	{
		m_class_ID++;
		m_textbox.setString("");
		m_textbox.setOrigin(Alignment::Center);
		m_rect.setSize(sf::Vector2f(100,75));
		m_rect.setFillColor(sf::Color::White);
		m_name = "TextBox";
	}

	TextBox::TextBox(int _charsize, const sf::Color& _color, bool _sel)
	{
		m_class_ID++;
		m_textbox.setCharacterSize(_charsize);
		m_textbox.setTextColor(_color);
		m_textbox.setOrigin(Alignment::Center);
		m_rect.setSize(sf::Vector2f(100, 75));
		m_rect.setFillColor(sf::Color::White);
		m_isSelected = _sel;
		if (_sel)
		{
			m_textbox.setString("_");
		}
		else
		{
			m_textbox.setString("");
		}
		m_name = "TextBox";
	}

	void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_rect);
		if (m_isShown) target.draw(m_textbox);
	}

	void TextBox::inputLogic(int _charTyped)
	{
		if (_charTyped != DELETE_KEY && _charTyped != ENTER_KEY && _charTyped != ESCAPE_KEY && !m_onlyNumbers)
		{
			m_text << static_cast<char>(_charTyped);
		}
		else if (_charTyped != DELETE_KEY && _charTyped != ENTER_KEY && _charTyped != ESCAPE_KEY && m_onlyNumbers)
		{
			if (_charTyped >= 48 && _charTyped <= 57)
			{
				m_text << static_cast<char>(_charTyped);
			}
		}
		else if (_charTyped == DELETE_KEY)
		{
			if (m_text.str().length() > 0)
			{
				deleteLastChar(2);
			}
		}
		else if (_charTyped == ENTER_KEY && m_enterUndoSelect)
		{
			this->setSelected(false); return;
		}
		else if (_charTyped == ENTER_KEY && !m_onlyNumbers && !m_enterUndoSelect)
		{
			m_text << '\n';
		}
		m_textbox.setString(m_text.str() + "_");
		alignTextBox();
	}

	void TextBox::deleteLastChar(int _num)
	{
		if (_num < 0) _num = 0;
		if (_num > 2) _num = 2;
		std::string text = m_text.str();
		std::string newText = "";
		for (int i = 0; i < text.length() + 1 - _num ; i++)
		{
			newText += text[i];
		}
		m_text.str("");
		m_text << newText;
		m_textbox.setString(m_text.str());
	}

	void TextBox::typedOn(sf::Event _event)
	{
		if (m_isSelected)
		{
			int charTyped = _event.text.unicode;
			if (charTyped < 128)
			{
				if (m_hasLimit)
				{
					if (m_text.str().length() < m_limit)
					{
						this->inputLogic(charTyped);
					}
					else if (m_text.str().length() >= m_limit && charTyped == DELETE_KEY)
					{
						this->deleteLastChar(2);
						m_textbox.setString(m_text.str() + "_");
						alignTextBox();
					}
					else if (m_text.str().length() >= m_limit && charTyped == ENTER_KEY)
					{
						this->setSelected(false);
					}
				}
				else
				{
					this->inputLogic(charTyped);
				}
			}
		}
	}

	void TextBox::setLimit(bool _bool)
	{
		m_hasLimit = _bool;
	}

	void TextBox::setLimit(bool _bool, int _lim)
	{
		m_hasLimit = _bool;
		m_limit = _lim;
	}

	void TextBox::setSelected(bool _bool)
	{
		m_isSelected = _bool;
		if (_bool == true) m_textbox.setString(m_text.str() + "_");
		else
		{
			if (m_text.str().length() > 0)
			{
				deleteLastChar(1);
			}
		}
		alignTextBox();
	}

	void TextBox::backIsShown(bool _bool)
	{
		m_textbox.backIsShown(_bool);
	}

	void TextBox::alignText(Alignment _alignment)
	{
		m_textbox.alignText(_alignment);
	}

	void TextBox::alignTextBox()
	{
		m_textbox.setOrigin(Alignment::Center);
		m_textbox.setPosition(Alignment::Center, m_rect);
	}

	bool TextBox::isPressed(sf::Event& _event, const sf::RenderWindow& _window)
	{
		if (_event.type == sf::Event::MouseButtonReleased) {
			if (m_textbox.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window)))||
				m_rect.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
			{
				if (m_isSelected == false) this->setSelected(true);
				else this->setSelected(false);
				return true;
			}
			return false;
		}
		return false;
	}

	bool TextBox::isPressed(sf::Event& _event, const sf::RenderWindow& _window, const sf::Mouse::Button& _btn)
	{
		if (_event.type == sf::Event::MouseButtonReleased && _event.mouseButton.button == _btn) {
			if (m_textbox.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window)))||
				m_rect.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
			{
				if (!m_isSelected) this->setSelected(true);
				else this->setSelected(false);
				return true;
			}
			return false;
		}
		return false;
	}

	bool TextBox::isPointedByMouse(const sf::RenderWindow& _window)
	{
		if (m_textbox.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))) ||
			m_rect.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
		{
			return true;
		}
		return false;
	}

	void TextBox::highlight(const sf::Color& _color)
	{
		if (!m_isHighlighted)
		{
			m_colorHolder = m_rect.getFillColor();
			this->setRectColor(_color);
			m_isHighlighted = true;
		}
	}

	void TextBox::disableHighlight()
	{
		if (m_isHighlighted)
		{
			this->setRectColor(m_colorHolder);
			m_isHighlighted = false;
		}
	}

	void TextBox::setString(const sf::String& _str)
	{
		m_text.str("");
		m_text << _str.toAnsiString().c_str();
		if (m_isSelected) m_textbox.setString(m_text.str() + "_");
		else m_textbox.setString(_str);
		alignTextBox();
	}

	void TextBox::setFont(const sf::Font& _font)
	{
		m_textbox.setFont(_font);
	}

	void TextBox::setCharacterSize(unsigned _size)
	{
		m_textbox.setCharacterSize(_size);
	}

	void TextBox::setTextColor(const sf::Color& _color)
	{
		m_textbox.setTextColor(_color);
	}

	void TextBox::setTextOutlineColor(const sf::Color& _color)
	{
		m_textbox.setTextOutlineColor(_color);
	}

	void TextBox::setTextOutlineThickness(float _thickness)
	{
		m_textbox.setTextOutlineThickness(_thickness);
	}

	void TextBox::setTextStyle(sf::Uint32 _style)
	{
		m_textbox.setTextStyle(_style);
	}

	void TextBox::setTextScale(const sf::Vector2f& _factors)
	{
		m_textbox.setScale(_factors);
	}

	void TextBox::setRectColor(const sf::Color& _color)
	{
		m_rect.setFillColor(_color);
	}

	void TextBox::setRectOutlineColor(const sf::Color& _color)
	{
		m_rect.setOutlineColor(_color);
	}

	void TextBox::setRectOutlineThickness(float _thickness)
	{
		m_rect.setOutlineThickness(_thickness);
	}

	void TextBox::setSize(const sf::Vector2f& _size)
	{
		m_rect.setSize(_size);
	}

	void TextBox::setPosition(float _x, float _y)
	{
		m_rect.setPosition(_x, _y);
		alignTextBox();
	}

	void TextBox::setPosition(const sf::Vector2f& _pos)
	{
		m_rect.setPosition(_pos);
		alignTextBox();
	}

	void TextBox::setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_rect, _target, _alignment, _offsetX, _offsetY);
		alignTextBox();
	}

	void TextBox::setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_rect, _target, _alignment, _offsetX, _offsetY);
		alignTextBox();
	}

	void TextBox::move(const sf::Vector2f& _offset)
	{
		m_rect.move(_offset);
		alignTextBox();
	}

	void TextBox::move(float _offsetX, float _offsetY)
	{
		m_rect.move(_offsetX, _offsetY);
		alignTextBox();
	}

	void TextBox::setRotation(float _angle)
	{
		m_textbox.rotate(_angle);
	}

	void TextBox::setOrigin(const sf::Vector2f& _origin)
	{
		m_rect.setOrigin(_origin);
	}

	void TextBox::setOrigin(Alignment _alignment, float _offsetX, float _offsetY)
	{
		setOriginByAlignment(m_rect, _alignment, _offsetX, _offsetY);
	}

	void TextBox::setBackSizeOffset(const sf::Vector2f& _offset)
	{
		m_textbox.setBackSizeOffset(_offset);
	}

	void TextBox::setBackColor(const sf::Color& _color)
	{
		m_textbox.setBackColor(_color);
	}

	void TextBox::setBackOutlineColor(const sf::Color& _color)
	{
		m_textbox.setBackOutlineColor(_color);
	}

	void TextBox::setBackOutlineThickness(float _thickness)
	{
		m_textbox.setTextOutlineThickness(_thickness);
	}

	//GETTERS

	bool TextBox::isEmpty() const
	{
		if (m_text.str().length() == 0)
			return true;
		return false;
	}

	std::string TextBox::getString() const
	{
		return  m_text.str();
	}

	const char* TextBox::getCstring() const
	{
		std::string const& str = m_text.str();
		return str.c_str();
	}

	const sf::Color& TextBox::getRectColor() const
	{
		return m_rect.getFillColor();
	}
}