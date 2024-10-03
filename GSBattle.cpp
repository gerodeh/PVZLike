#include "GSBattle.h"

GSBattle::GSBattle(Game* game)
{
    m_game = game;

    sf::Vector2f pos = sf::Vector2f(m_game->m_window.getSize());
 
    m_view.setSize(pos);

    pos *= 0.5f;

    m_view.setCenter(pos);

    init();
    initGui();

    m_backgrdColor = sf::Color(16, 16, 16);
}

GSBattle::~GSBattle() 
{
    std::cout << "GSBattle's gone" << std::endl;
}

void GSBattle::initGui()
{
    #pragma region Buttons
    m_buttons.push_back(std::make_unique<gui::Button>(
        sf::Vector2f(55, 25),
        sf::String(L"Μενώ"),
        sf::Vector2f(0, 0),
        sf::String("Button_Menu")
    ));
    m_buttons[0]->setFont(m_game->m_font);
    m_buttons[0]->setCharacterSize(12);
    m_buttons[0]->setTextColor(sf::Color(255, 255, 255));
    m_buttons[0]->setOrigin(Alignment::BottomRight);
    m_buttons[0]->setPosition(Alignment::BottomRight, m_game->m_window);
    m_buttons[0]->setRectFillColor(sf::Color(122, 122, 122, 100));
    m_buttons[0]->setRectFillColorAdditional(sf::Color());
    m_buttons[0]->setTextOutlineColor(sf::Color::Black);
    m_buttons[0]->setTextOutlineThickness(2);
    #pragma endregion
}

void GSBattle::init()
{
    m_gameField.init(5, 9, m_game->m_textureManager.GetTextureRef("Cell"), &m_view);
    m_gameField.move(sf::Vector2f(0,70.f));
}

void GSBattle::draw(const float dt)
{
    m_game->m_window.setView(m_view);
    m_game->m_window.draw(m_gameField);
    for (const auto& button : m_buttons)
    {
        m_game->m_window.draw(*button);
    }
    for (const auto& button : m_buttons)
    {
        m_game->m_window.draw(button->m_tooltip);
    }
}

void GSBattle::update(const float dt)
{
    m_view.setSize(m_game->m_window.getSize().x, m_game->m_window.getSize().y);
    m_view.setCenter(m_game->m_window.getSize().x * 0.5f, m_game->m_window.getSize().y * 0.5f);
}

void GSBattle::handleInput(const float dt)
{
    sf::Event event;
    while (m_game->m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_game->m_window.close();
            break; // End of Event::Closed

        case sf::Event::Resized:
            if (event.size.width >= m_game->standartWsizeX && event.size.height >= m_game->standartWsizeY)
            {
                m_view.setSize(event.size.width, event.size.height);
                m_view.setCenter(event.size.width * 0.5f, event.size.height * 0.5f);
            }
            else
            {
                m_game->m_window.setSize(sf::Vector2u(m_game->standartWsizeX, m_game->standartWsizeY));
                m_game->m_window.setPosition(sf::Vector2i((int)((m_game->scrXmetric * 0.5f) - m_game->standartWsizeX * 0.5f), (int)((m_game->scrYmetric * 0.5f) - m_game->standartWsizeY * 0.5f)));
                m_view.setCenter(sf::Vector2f(m_game->standartWsizeX * 0.5f, m_game->standartWsizeY * 0.5f));
            }
            break; // End of Event::Resized

        } // End of switch

        for (const auto& btn : m_buttons) // Start of handling buttons
        {
            if (btn->isPressed(event, m_game->m_window))
            {
                if (btn->getName() == std::string("Button_Menu")) { m_game->popState(); return; }
            } // End of checking if button is pressed
            if (btn->isPointedByMouse(m_game->m_window))
            {
                btn->highlight(sf::Color
                (
                    btn->getRectFillColor().r - 50,
                    btn->getRectFillColor().g - 50,
                    btn->getRectFillColor().b - 50,
                    btn->getRectFillColor().a
                ));
            }
            else
            {
                btn->disableHighlight();
            } // End of highlighting buttons

        } // End of handling buttons

    }// End of while cycle
}