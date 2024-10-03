#include "Button.h"

namespace gui
{
	unsigned Button::m_class_ID = 0;

	Button::Button()
	{
		m_class_ID++;
		m_text.setFillColor(sf::Color::Black);
		m_text.setString("");
		m_rect.setPosition(0, 0);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
		m_name = "Button";
		m_pos = sf::Vector2f(0, 0);
	}

	Button::Button
	(
		const sf::Vector2f& _size,
		const sf::String& _string,
		const sf::Vector2f& _pos,
		const sf::String& _name
	)
	{
		m_class_ID++;
		m_text.setFillColor(sf::Color::Black);
		m_text.setString(_string);
		m_rect.setOrigin(0, 0);
		m_rect.setSize(_size); m_rect.setPosition(_pos);
		m_pos = _pos;
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
		m_name = _name;
	}

	Button::Button(const gui::Button& _button)
	{
		m_class_ID++;
		this->setFont(*_button.getFont());
		this->setString(_button.getString());
		this->setCharacterSize(_button.getCharacterSize());
		this->setRectFillColor(_button.getRectFillColor());
		this->setRectFillColorAdditional(_button.getRectFillColorAdditional());
		this->setRectOutlineColor(_button.getRectOutlineColor());
		this->setRectOutlineThickness(_button.getRectOutlineThickness());
		this->setRectScale(_button.getRectScale());
		this->setRectSize(_button.getRectSize());
		this->setRotation(_button.getRotation());
		this->setTextColor(_button.getTextColor());
		this->setTextOutlineColor(_button.getTextOutlineColor());
		this->setTextOutlineThickness(_button.getTextOutlineThickness());
		this->setTextScale(_button.getTextScale());
		this->setTextStyle(_button.getTextStyle());
		this->setTexture(_button.getTexture());
		this->setTextureRect(_button.getTextureRect());
		this->setOrigin(_button.getOrigin());
		this->setPosition(_button.getPosition());
		this->alignText(_button.getTextAlignment(), _button.getTextOffsetX(), _button.getTextOffsetY());
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_isShown)
		{
			target.draw(m_rect);
			target.draw(m_text);
		}
	}

	void Button::ImGui()
	{
		/*ImGui::Begin("Debug");
		ImGui::BeginTabBar("1");
		ImGui::TabItemButton(m_name.c_str());
		
		if (ImGui::Checkbox("Show", &m_isShown))
		{

		}
		if (ImGui::CollapsingHeader("Transform"))
		{
			ImGui::DragFloat("X", &m_pos.x);
			ImGui::DragFloat("Y", &m_pos.y);
			ImGui::Separator();
		}
		this->setPosition(m_pos);
		ImGui::EndTabBar();
		ImGui::End();*/
	}

	bool Button::isPressed(sf::Event& _event, const sf::RenderWindow& _window)
	{
		if (_event.type == sf::Event::MouseButtonReleased) {
			if (m_rect.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
			{
				return true; 
			}
			return false;
		}
		return false;
	}
	
	bool Button::isPressed(sf::Event& _event, const sf::RenderWindow& _window, const sf::Mouse::Button& _btn)
	{
		if (_event.type == sf::Event::MouseButtonReleased && _event.mouseButton.button == _btn) {
			if (m_rect.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
			{
				return true;
			}
			return false;
		}
		return false;
	}

	bool Button::isPointedByMouse(const sf::RenderWindow& _window)
	{
		if (m_rect.getGlobalBounds().contains(_window.mapPixelToCoords(sf::Mouse::getPosition(_window))))
		{
			m_tooltip.showAndUpdateToolTip(_window);
			return true;
		}
		m_tooltip.m_isShown = false;
		return false;
	}

	void Button::alignText(Alignment _alignment, float _offsetX, float _offsetY)
	{
		m_textAlignment = _alignment;
		m_textOffsetX = _offsetX;
		m_textOffsetY = _offsetY;
		setOriginByAlignment(m_text, m_textAlignment);
		setPositionByAlignment(m_text, m_rect, m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::highlight(const sf::Color& _color)
	{
		if (!m_isHighlighted)
		{
			m_colorHolder = m_rectFillColor;
			this->setRectFillColor(_color);
			m_isHighlighted = true;
		}
	}

	void Button::disableHighlight()
	{
		if (m_isHighlighted)
		{
			this->setRectFillColor(m_colorHolder);
			m_isHighlighted = false;
		}
	}

	void Button::setString(const sf::String& _string)
	{
		m_text.setString(_string);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setFont(const sf::Font& _font)
	{
		m_text.setFont(_font);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setCharacterSize(unsigned _size)
	{
		m_text.setCharacterSize(_size);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setTextColor(const sf::Color& _color)
	{
		m_text.setFillColor(_color);
	}

	void Button::setTextOutlineColor(const sf::Color& _color)
	{
		m_text.setOutlineColor(_color);
	}

	void Button::setTextOutlineThickness(float _thickness)
	{
		m_text.setOutlineThickness(_thickness);
	}

	void Button::setTextStyle(sf::Uint32 _style)
	{
		m_text.setStyle(_style);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setTextScale(const sf::Vector2f& _factors)
	{
		m_text.setScale(_factors);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}
	
	void Button::setPosition(float _x, float _y)
	{
		m_rect.setPosition(_x, _y);
		m_pos.x = m_pos.x + _x;
		m_pos.y = m_pos.y + _y;
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setPosition(const sf::Vector2f& _pos)
	{
		m_rect.setPosition(_pos);
		m_pos = _pos;
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setPosition(Alignment _alignment, const sf::RenderTarget& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_rect, _target, _alignment, _offsetX, _offsetY);
		m_pos = m_rect.getPosition();
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setPosition(Alignment _alignment, const sf::RectangleShape& _target, float _offsetX, float _offsetY)
	{
		setPositionByAlignment(m_rect, _target, _alignment, _offsetX, _offsetY);
		m_pos = m_rect.getPosition();
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::move(const sf::Vector2f& _offset)
	{
		m_rect.move(_offset);
		m_pos = m_rect.getPosition();
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::move(float _offsetX, float _offsetY)
	{
		m_rect.move(_offsetX, _offsetY);
		m_pos = m_rect.getPosition();
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}
	
	void Button::setRotation(float _angle)
	{
		sf::Vector2f tmp;
		tmp = m_rect.getOrigin();
		m_rect.setRotation(_angle);
		setOriginByAlignment(m_rect, Alignment::Center);
		m_text.setRotation(_angle);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
		m_rect.setOrigin(tmp);
	}

	void Button::setOrigin(const sf::Vector2f& _origin)
	{
		m_rect.setOrigin(_origin);
	}

	void Button::setOrigin(Alignment _alignment)
	{
		setOriginByAlignment(m_rect, _alignment);
	}

	void Button::setRectFillColor(const sf::Color& _color)
	{
		m_rectFillColor = _color;
		m_rect.setFillColor(_color);
	}

	void Button::setRectFillColorAdditional(const sf::Color& _color)
	{
		m_rectFillColorAdditional = _color;
	}

	void Button::setRectOutlineColor(const sf::Color& _color)
	{
		m_rect.setOutlineColor(_color);
	}

	void Button::setRectOutlineThickness(float _thickness)
	{
		m_rect.setOutlineThickness(_thickness);
	}

	void Button::setRectScale(const sf::Vector2f& _factors)
	{
		m_rect.setScale(_factors);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setRectSize(const sf::Vector2f& _size)
	{
		m_rect.setSize(_size);
		alignText(m_textAlignment, m_textOffsetX, m_textOffsetY);
	}

	void Button::setTexture(const sf::Texture* _texture, bool _resetRect)
	{
		m_rect.setTexture(_texture, _resetRect);
	}

	void Button::setTextureRect(const sf::IntRect& _rect)
	{
		m_rect.setTextureRect(_rect);
	}

	void Button::setName(const sf::String& _str)
	{
		m_name = _str;
	}

	//GETTERS

	const sf::Font* Button::getFont() const
	{
		return m_text.getFont();
	}

	unsigned Button::getCharacterSize() const
	{
		return m_text.getCharacterSize();
	}

	const sf::Color& Button::getTextColor() const
	{
		return m_text.getFillColor();
	}

	const sf::Color& Button::getTextOutlineColor() const
	{
		return m_text.getOutlineColor();
	}

	float Button::getTextOutlineThickness() const
	{
		return m_text.getOutlineThickness();
	}

	sf::Uint32 Button::getTextStyle() const
	{
		return m_text.getStyle();
	}

	const sf::Vector2f& Button::getTextScale() const
	{
		return m_text.getScale();
	}

	const char* Button::getString() const
	{
		return m_text.getString().toAnsiString().c_str();
	}

	const sf::Vector2f& Button::getPosition() const
	{
		return m_pos;
	}

	const sf::Vector2f& Button::getOrigin() const
	{
		return m_rect.getOrigin();
	}

	float Button::getRotation() const
	{
		return m_rect.getRotation();
	}

	const sf::Color& Button::getRectFillColor() const
	{
		return m_rectFillColor;
	}

	const sf::Color& Button::getRectFillColorAdditional() const
	{
		return m_rectFillColorAdditional;
	}

	const sf::Color& Button::getRectOutlineColor() const
	{
		return m_rect.getOutlineColor();
	}

	float Button::getRectOutlineThickness() const
	{
		return m_rect.getOutlineThickness();
	}

	sf::FloatRect Button::getLocalBounds() const
	{
		return m_rect.getLocalBounds();
	}

	sf::FloatRect Button::getGlobalBounds() const
	{
		return m_rect.getGlobalBounds();
	}

	const sf::Vector2f& Button::getRectScale() const
	{
		return m_rect.getScale();
	}

	const sf::Vector2f& Button::getRectSize() const
	{
		return m_rect.getSize();
	}

	const sf::Transform& Button::getRectTransform() const
	{
		return m_rect.getTransform();
	}

	const sf::Texture* Button::getTexture() const
	{
		return m_rect.getTexture();
	}

	const sf::IntRect& Button::getTextureRect() const
	{
		return m_rect.getTextureRect();
	}

	const Alignment& Button::getTextAlignment() const
	{
		return m_textAlignment;
	}

	float Button::getTextOffsetX() const
	{
		return m_textOffsetX;
	}

	float Button::getTextOffsetY() const
	{
		return m_textOffsetY;
	}

	const gui::Button& Button::getButton() const
	{
		return *this;
	}

	const char* Button::getName() const
	{
		return m_name.c_str();
	}

	bool& Button::isHighlighted()
	{
		return m_isHighlighted;
	}

	unsigned Button::getID() const
	{
		return m_ID;
	}

	unsigned Button::getClassID() const
	{
		return m_class_ID;
	}
}