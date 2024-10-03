#pragma once

#include "GameState.h"
#include "gui/Button.h"
#include <memory>
#include "GameField.h"

class GSBattle : public GameState
{
    GameField m_gameField;
    std::vector<std::unique_ptr<gui::Button>> m_buttons;
    sf::View m_view;
public:

    virtual void initGui() override;

    virtual void init() override;

    virtual void draw(const float dt) override;

    virtual void update(const float dt) override;

    virtual void handleInput(const float dt) override;
    
	GSBattle(Game* game);

	~GSBattle();
};