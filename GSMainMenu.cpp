#include "GSMainMenu.h"

GSMainMenu::GSMainMenu(Game* game)
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

GSMainMenu::~GSMainMenu() {}

void GSMainMenu::init()
{

}

void GSMainMenu::initGui()
{

#pragma region Texts
    m_headerText = std::make_unique<sf::Text>(
        sf::String("Planetary warfare"), // string
        m_game->m_font,                  // font
        77                               // char size
    );
    m_headerText->setFont(m_game->m_font);
    m_headerText->setFillColor(sf::Color(255, 255, 255, 200));
    m_headerText->setOutlineColor(sf::Color::Black);
    m_headerText->setOutlineThickness(4);
    setOriginByAlignment(*m_headerText, Alignment::TopLeft);
    setPositionByAlignment(*m_headerText, m_game->m_window, Alignment::TopLeft, 50, 100);
#pragma endregion

#pragma region Buttons
    m_buttons.push_back(std::make_unique<gui::Button>
        (
            sf::Vector2f(620, 60),
            sf::String(L"Играть"),
            sf::Vector2f(0, 0),
            sf::String("Button_Start")
        ));
    m_buttons[0]->setFont(m_game->m_font);
    m_buttons[0]->setCharacterSize(30);
    m_buttons[0]->setTextColor(sf::Color(255, 255, 255));
    m_buttons[0]->setOrigin(Alignment::Left);
    m_buttons[0]->setPosition(Alignment::Left, m_game->m_window);
    m_buttons[0]->setRectFillColor(sf::Color(122, 122, 122, 100));
    m_buttons[0]->setRectFillColorAdditional(sf::Color());
    m_buttons[0]->setTextOutlineColor(sf::Color::Black);
    m_buttons[0]->setTextOutlineThickness(2);

    m_buttons.push_back(std::make_unique<gui::Button>
        (
            sf::Vector2f(580, 60),
            sf::String(L"Настройки"),
            sf::Vector2f(0, 0),
            sf::String("Button_Settings")
        ));
    m_buttons[1]->setFont(m_game->m_font);
    m_buttons[1]->setCharacterSize(30);
    m_buttons[1]->setTextColor(sf::Color(255, 255, 255));
    m_buttons[1]->setOrigin(Alignment::Left);
    m_buttons[1]->setPosition(Alignment::Left, m_game->m_window, 0, 65);
    m_buttons[1]->setRectFillColor(sf::Color(122, 122, 122, 100));
    m_buttons[1]->setTextOutlineColor(sf::Color::Black);
    m_buttons[1]->setTextOutlineThickness(2);
    m_buttons[1]->m_tooltip.m_doNotShowToolTip = false;
    m_buttons[1]->m_tooltip.setString(sf::String(L"Тестовая\nНадпись"));
    m_buttons[1]->m_tooltip.setFont(m_game->m_font);
    m_buttons[1]->m_tooltip.setCharacterSize(30);
    m_buttons[1]->m_tooltip.setBackOutlineColor(sf::Color::Black);
    m_buttons[1]->m_tooltip.setBackOutlineThickness(2);
    m_buttons[1]->m_tooltip.setTextOutlineColor(sf::Color::Black);
    m_buttons[1]->m_tooltip.setTextOutlineThickness(2);
    m_buttons[1]->m_tooltip.setBackSizeOffset(sf::Vector2f(22, 22));
    m_buttons[1]->m_tooltip.alignText(Alignment::Center);

    m_buttons.push_back(std::make_unique<gui::Button>
        (
            sf::Vector2f(500, 60),
            sf::String(L"Выход"),
            sf::Vector2f(0, 0),
            sf::String("Button_Exit")
        ));
    m_buttons[2]->setFont(m_game->m_font);
    m_buttons[2]->setCharacterSize(30);
    m_buttons[2]->setTextColor(sf::Color(255, 255, 255));
    m_buttons[2]->setOrigin(Alignment::Left);
    m_buttons[2]->setPosition(Alignment::Left, m_game->m_window, 0, 130);
    m_buttons[2]->setRectFillColor(sf::Color(122, 100, 100, 100));
    m_buttons[2]->setTextOutlineColor(sf::Color::Black);
    m_buttons[2]->setTextOutlineThickness(2);
#pragma endregion

}

void GSMainMenu::draw(const float dt)
{
	m_game->m_window.setView(m_view);
    m_game->m_window.draw(*m_headerText);
    for (const auto& button : m_buttons)
    {
        m_game->m_window.draw(*button);
    }
}

void GSMainMenu::update(const float dt)
{
    m_view.setSize(m_game->m_window.getSize().x, m_game->m_window.getSize().y);
    m_view.setCenter(m_game->m_window.getSize().x * 0.5f, m_game->m_window.getSize().y * 0.5f);
}

void GSMainMenu::handleInput(const float dt)
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
                if (btn->getName() == std::string("Button_Start")) { m_game->pushState(new GSBattle(m_game)); }
                if (btn->getName() == std::string("Button_Exit")) { m_game->m_window.close(); }
                //if (btn->getName() == std::string("Button_Settings")) { m_game->pushState(new GameStateSettings(m_game)); }
                //if (btn->getName() == std::string("Button_Tutorial")) { m_game->pushState(new GameStateTutorial(m_game)); }

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