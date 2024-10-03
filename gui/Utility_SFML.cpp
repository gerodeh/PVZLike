#include "Utility_sfml.h"


void setOriginByAlignment
(
	sf::RectangleShape& _obj,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{ 
	sf::FloatRect Rect = _obj.getLocalBounds();
	switch (_alignment)
	{
		case Alignment::Center:
			_obj.setOrigin(Rect.left + Rect.width/2.0f + _offsetX, Rect.top + Rect.height/2.0f + _offsetY);
			break;
		case Alignment::Left:
			_obj.setOrigin(Rect.left + _offsetX, Rect.top + Rect.height/2.0f + _offsetY);
			break;
		case Alignment::Right:
			_obj.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + Rect.height/2.0f + _offsetY);
			break;
		case Alignment::Top:
			_obj.setOrigin(Rect.left + Rect.width/2.0f + _offsetX, Rect.top + _offsetY);
			break;
		case Alignment::Bottom:
			_obj.setOrigin(Rect.left + Rect.width/2.0f + _offsetX, Rect.top + Rect.height + _offsetY);
			break;
		case Alignment::TopLeft:
			_obj.setOrigin(Rect.left + _offsetX, Rect.top + _offsetY);
			break;
		case Alignment::TopRight:
			_obj.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + _offsetY);
			break;
		case Alignment::BottomLeft:
			_obj.setOrigin(Rect.left + _offsetX, Rect.top + Rect.height + _offsetY);
			break;
		case Alignment::BottomRight:
			_obj.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + Rect.height + _offsetY);
			break;
		default:
			break;
	}
}

void setOriginByAlignment
(
	sf::Text& _obj,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	sf::FloatRect Rect = _obj.getLocalBounds();
	switch (_alignment)
	{
	case Alignment::Center:
		_obj.setOrigin(Rect.left + Rect.width / 2.0f + _offsetX, Rect.top + Rect.height / 2.0f + _offsetY);
		break;
	case Alignment::Left:
		_obj.setOrigin(Rect.left + _offsetX, Rect.top + Rect.height / 2.0f + _offsetY);
		break;
	case Alignment::Right:
		_obj.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + Rect.height / 2.0f + _offsetY);
		break;
	case Alignment::Top:
		_obj.setOrigin(Rect.left + Rect.width / 2.0f + _offsetX, Rect.top + _offsetY);
		break;
	case Alignment::Bottom:
		_obj.setOrigin(Rect.left + Rect.width / 2.0f + _offsetX, Rect.top + Rect.height + _offsetY);
		break;
	case Alignment::TopLeft:
		_obj.setOrigin(Rect.left + _offsetX, Rect.top + _offsetY);
		break;
	case Alignment::TopRight:
		_obj.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + _offsetY);
		break;
	case Alignment::BottomLeft:
		_obj.setOrigin(Rect.left + _offsetX, Rect.top + Rect.height + _offsetY);
		break;
	case Alignment::BottomRight:
		_obj.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + Rect.height + _offsetY);
		break;
	default:
		break;
	}
}

void setOriginByAlignment
(
	sf::Sprite& _sprite,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	sf::FloatRect Rect = _sprite.getLocalBounds();
	switch (_alignment)
	{
	case Alignment::Center:
		_sprite.setOrigin(Rect.left + Rect.width / 2.0f + _offsetX, Rect.top + Rect.height / 2.0f + _offsetY);
		break;
	case Alignment::Left:
		_sprite.setOrigin(Rect.left + _offsetX, Rect.top + Rect.height / 2.0f + _offsetY);
		break;
	case Alignment::Right:
		_sprite.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + Rect.height / 2.0f + _offsetY);
		break;
	case Alignment::Top:
		_sprite.setOrigin(Rect.left + Rect.width / 2.0f + _offsetX, Rect.top + _offsetY);
		break;
	case Alignment::Bottom:
		_sprite.setOrigin(Rect.left + Rect.width / 2.0f + _offsetX, Rect.top + Rect.height + _offsetY);
		break;
	case Alignment::TopLeft:
		_sprite.setOrigin(Rect.left + _offsetX, Rect.top + _offsetY);
		break;
	case Alignment::TopRight:
		_sprite.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + _offsetY);
		break;
	case Alignment::BottomLeft:
		_sprite.setOrigin(Rect.left + _offsetX, Rect.top + Rect.height + _offsetY);
		break;
	case Alignment::BottomRight:
		_sprite.setOrigin(Rect.left + Rect.width + _offsetX, Rect.top + Rect.height + _offsetY);
		break;
	default:
		break;
	}
}

void setPositionByAlignment
(
	sf::RectangleShape& _obj,
	const sf::RenderTarget& _target,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	sf::Vector2u tpos = _target.getSize();
	switch (_alignment)
	{
	case Alignment::Center:
		_obj.setPosition(tpos.x / 2 + _offsetX, tpos.y / 2 + _offsetY);
		break;
	case Alignment::Left:
		_obj.setPosition(_offsetX, tpos.y / 2 + _offsetY);
		break;
	case Alignment::Right:
		_obj.setPosition(tpos.x + _offsetX, tpos.y / 2 + _offsetY);
		break;
	case Alignment::Top:
		_obj.setPosition(tpos.x / 2 + _offsetX, _offsetY);
		break;
	case Alignment::Bottom:
		_obj.setPosition(tpos.x / 2 + _offsetX, tpos.y + _offsetY);
		break;
	case Alignment::TopLeft:
		_obj.setPosition(_offsetX, _offsetY);
		break;
	case Alignment::TopRight:
		_obj.setPosition(tpos.x + _offsetX, _offsetY);
		break;
	case Alignment::BottomLeft:
		_obj.setPosition(_offsetX, tpos.y + _offsetY);
		break;
	case Alignment::BottomRight:
		_obj.setPosition(tpos.x + _offsetX, tpos.y + _offsetY);
		break;
	default:
		break;
	}
}

void setPositionByAlignment
(
	sf::Text& _obj,
	const sf::RenderTarget& _target,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	sf::Vector2u tpos = _target.getSize();
	switch (_alignment)
	{
	case Alignment::Center:
		_obj.setPosition(tpos.x / 2 + _offsetX, tpos.y / 2 + _offsetY);
		break;
	case Alignment::Left:
		_obj.setPosition(_offsetX, tpos.y / 2 + _offsetY);
		break;
	case Alignment::Right:
		_obj.setPosition(tpos.x + _offsetX, tpos.y / 2 + _offsetY);
		break;
	case Alignment::Top:
		_obj.setPosition(tpos.x / 2 + _offsetX, _offsetY);
		break;
	case Alignment::Bottom:
		_obj.setPosition(tpos.x / 2 + _offsetX, tpos.y + _offsetY);
		break;
	case Alignment::TopLeft:
		_obj.setPosition(_offsetX, _offsetY);
		break;
	case Alignment::TopRight:
		_obj.setPosition(tpos.x + _offsetX, _offsetY);
		break;
	case Alignment::BottomLeft:
		_obj.setPosition(_offsetX, tpos.y + _offsetY);
		break;
	case Alignment::BottomRight:
		_obj.setPosition(tpos.x + _offsetX, tpos.y + _offsetY);
		break;
	default:
		break;
	}
}

void setPositionByAlignment
(
	sf::Text& _obj,
	sf::RectangleShape _obj2,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	switch (_alignment)
	{
	case Alignment::Center:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Left:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Right:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Top:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::Bottom:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y - _obj2.getOrigin().y);
		break;
	case Alignment::TopLeft:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::TopRight:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::BottomLeft:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y - _obj2.getOrigin().y);
		break;
	case Alignment::BottomRight:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y - _obj2.getOrigin().y);
		break;
	default:
		break;
	}
}

void setPositionByAlignment
(
	sf::RectangleShape& _obj,
	sf::Text _obj2,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	sf::FloatRect rect = _obj2.getGlobalBounds();
	switch (_alignment)
	{
	case Alignment::Center:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + rect.width / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + rect.height / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Left:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + (float)rect.height / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Right:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + (float)rect.width - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + (float)rect.height / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Top:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + (float)rect.width / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::Bottom:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + (float)rect.width / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + (float)rect.height - _obj2.getOrigin().y);
		break;
	case Alignment::TopLeft:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::TopRight:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + (float)rect.width - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::BottomLeft:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + (float)rect.height - _obj2.getOrigin().y);
		break;
	case Alignment::BottomRight:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + (float)rect.width - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + (float)rect.height - _obj2.getOrigin().y);
		break;
	default:
		break;
	}
}

void setPositionByAlignment
(
	sf::RectangleShape& _obj,
	sf::RectangleShape _obj2,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	switch (_alignment)
	{
	case Alignment::Center:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Left:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Right:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y / 2.f - _obj2.getOrigin().y);
		break;
	case Alignment::Top:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::Bottom:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x / 2.f - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y - _obj2.getOrigin().y);
		break;
	case Alignment::TopLeft:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::TopRight:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY - _obj2.getOrigin().y);
		break;
	case Alignment::BottomLeft:
		_obj.setPosition(_obj2.getPosition().x + _offsetX - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y - _obj2.getOrigin().y);
		break;
	case Alignment::BottomRight:
		_obj.setPosition(_obj2.getPosition().x + _offsetX + _obj2.getSize().x - _obj2.getOrigin().x, _obj2.getPosition().y + _offsetY + _obj2.getSize().y - _obj2.getOrigin().y);
		break;
	default:
		break;
	}
}

void setPositionByAlignment
(
	sf::RectangleShape& _obj,
	sf::View _view,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	switch (_alignment)
	{
	case Alignment::Center:
		_obj.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x / 2.f, _view.getCenter().y + _offsetY + _view.getSize().y / 2.f );
		break;
	case Alignment::Left:
		_obj.setPosition(_view.getCenter().x + _offsetX, _view.getCenter().y + _offsetY + _view.getSize().y / 2.f);
		break;
	case Alignment::Right:
		_obj.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x, _view.getCenter().y + _offsetY + _view.getSize().y / 2.f);
		break;
	case Alignment::Top:
		_obj.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x / 2.f, _view.getCenter().y + _offsetY);
		break;
	case Alignment::Bottom:
		_obj.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x / 2.f, _view.getCenter().y + _offsetY + _view.getSize().y);
		break;
	case Alignment::TopLeft:
		_obj.setPosition(_view.getCenter().x + _offsetX, _view.getCenter().y + _offsetY);
		break;
	case Alignment::TopRight:
		_obj.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x, _view.getCenter().y + _offsetY);
		break;
	case Alignment::BottomLeft:
		_obj.setPosition(_view.getCenter().x + _offsetX, _view.getCenter().y + _offsetY + _view.getSize().y);
		break;
	case Alignment::BottomRight:
		_obj.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x, _view.getCenter().y + _offsetY + _view.getSize().y);
		break;
	default:
		break;
	}
}

void setPositionByAlignment
(
	sf::Sprite& _sprite,
	sf::View _view,
	Alignment _alignment,
	float _offsetX,
	float _offsetY
)
{
	switch (_alignment)
	{
	case Alignment::Center:
		_sprite.setPosition(_view.getCenter().x + _offsetX, _view.getCenter().y + _offsetY);
		break;
	case Alignment::Left:
		_sprite.setPosition(_view.getCenter().x + _offsetX - _view.getSize().x/2.f, _view.getCenter().y + _offsetY);
		break;
	case Alignment::Right:
		_sprite.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x/2.f, _view.getCenter().y + _offsetY);
		break;
	case Alignment::Top:
		_sprite.setPosition(_view.getCenter().x + _offsetX, _view.getCenter().y + _offsetY - _view.getSize().y/2.f);
		break;
	case Alignment::Bottom:
		_sprite.setPosition(_view.getCenter().x + _offsetX, _view.getCenter().y + _offsetY + _view.getSize().y/2.f);
		break;
	case Alignment::TopLeft:
		_sprite.setPosition(_view.getCenter().x + _offsetX - _view.getSize().x/2.f, _view.getCenter().y + _offsetY - _view.getSize().y / 2.f);
		break;
	case Alignment::TopRight:
		_sprite.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x/2.f, _view.getCenter().y + _offsetY - _view.getSize().y / 2.f);
		break;
	case Alignment::BottomLeft:
		_sprite.setPosition(_view.getCenter().x + _offsetX - _view.getSize().x/2.f, _view.getCenter().y + _offsetY + _view.getSize().y/2.f);
		break;
	case Alignment::BottomRight:
		_sprite.setPosition(_view.getCenter().x + _offsetX + _view.getSize().x/2.f, _view.getCenter().y + _offsetY + _view.getSize().y/2.f);
		break;
	default:
		break;
	}
}