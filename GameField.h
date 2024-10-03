#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "gui/Utility_SFML.h"

class Cell
{
	static int m_id;
public:
	sf::Sprite m_sprite;
	Cell();
	~Cell();
};

class GameField : public sf::Drawable
{
	std::vector<std::vector<std::shared_ptr<Cell>>> m_cells;
public:
	void init(int height, int width, const sf::Texture& texture, sf::View* view);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void move(const sf::Vector2f& vector);

	GameField();
	~GameField();
};