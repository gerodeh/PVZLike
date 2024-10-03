#pragma once

#include "Game.h"

#include "SFML/Graphics.hpp"

class GameState
{
public:
    Game* m_game;
    sf::Color m_backgrdColor = sf::Color::Black;

    virtual void initGui();
    virtual void init();
    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput(const float dt) = 0;

    virtual ~GameState();
};

