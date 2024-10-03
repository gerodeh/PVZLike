#include "GameField.h"

int Cell::m_id = -1;

Cell::Cell()
{
	m_id++;
	std::cout << "The Cell " << m_id << " was made" << std::endl;
}

Cell::~Cell()
{
	m_id--;
	std::cout << "The Cell " << m_id << " was destroyed" << std::endl;
}

GameField::GameField()
{

}

GameField::~GameField()
{
	std::cout << "GameField was destroyed" << std::endl;
}

void GameField::init(int height, int width, const sf::Texture& texture, sf::View* view)
{
	float scalefactor = 0.2f; 
	for (int i = 0; i < height; i++)
	{
		std::vector<std::shared_ptr<Cell>> v;
		for (int j = 0; j < width; j++)
		{
			v.push_back(std::make_shared<Cell>());
			v.back()->m_sprite.setTexture(texture);
			setOriginByAlignment(v.back()->m_sprite, Alignment::Center);
			setPositionByAlignment(v.back()->m_sprite, *view, Alignment::Center);
			v.back()->m_sprite.move(sf::Vector2f(
				-(float)v.back()->m_sprite.getTexture()->getSize().x * scalefactor * (width / 2) + (int)v.back()->m_sprite.getTexture()->getSize().x * scalefactor * j,
				-(float)v.back()->m_sprite.getTexture()->getSize().y * scalefactor * (height / 2) + (int)v.back()->m_sprite.getTexture()->getSize().y * scalefactor * i
			));
			v.back()->m_sprite.setScale(sf::Vector2f(scalefactor, scalefactor));
		}
		m_cells.push_back(v);
	}
}

void GameField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < m_cells.size(); i++)
	{
		for (int j = 0; j < m_cells.back().size(); j++)
		{
			target.draw(m_cells[i][j]->m_sprite);
		}
	}
}

void GameField::move(const sf::Vector2f& vector)
{
	for (int i = 0; i < m_cells.size(); i++)
	{
		for (int j = 0; j < m_cells.back().size(); j++)
		{
			m_cells[i][j]->m_sprite.move(vector);
		}
	}
}