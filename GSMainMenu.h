#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameState.h"
#include "GSBattle.h"
#include "gui/Button.h"
#include <vector>
#include <memory>

class GSMainMenu : public GameState 
{
    std::unique_ptr<sf::Text> m_headerText;
    std::vector<std::unique_ptr<gui::Button>> m_buttons;
    sf::View m_view;
public:

    virtual void initGui() override;

    virtual void init() override;

    virtual void draw(const float dt) override;

    virtual void update(const float dt) override;

    virtual void handleInput(const float dt) override;

    GSMainMenu(Game* game);

    ~GSMainMenu();

};