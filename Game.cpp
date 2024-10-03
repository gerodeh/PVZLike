#include "Game.h"
#include "GameState.h"
#include <iostream>
void Game::pushState(GameState* state)
{
    m_states.push_back(state);
    std::cout << "stack: " << m_states.size() << std::endl;
    std::cout << state << std::endl;
}

void Game::popState()
{   
    std::cout << m_states.back() << std::endl;
    auto ptr = m_states.back();
    m_states.pop_back();
    delete ptr;
    std::cout << "stack: " << m_states.size() << ". Popped" << std::endl;
}

void Game::changeState(GameState* state)
{
    if (!m_states.empty()) 
        popState();
    pushState(state);
}

GameState* Game::peekState()
{
    if (m_states.empty())
        return nullptr;
    return m_states.back();
}

void Game::gameLoop()
{
    sf::Clock clock;
    while (m_window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (this->peekState() == nullptr)
            continue;

        peekState()->handleInput(dt);
        peekState()->update(dt);

        m_window.clear(peekState()->m_backgrdColor);

        peekState()->draw(dt);

        m_window.display();
    }
}

void Game::setFullscreenMode()
{
    m_window.close();
    m_window.create(sf::VideoMode(scrXmetric, scrYmetric), "Robots vs mutants", sf::Style::Fullscreen);
    m_fullscreen = true;
    m_window.setFramerateLimit(60);
}

void Game::cancelFullscreenMode()
{
    m_window.close();
    m_window.create(sf::VideoMode(950, 750), "Robots vs mutants", sf::Style::Default);
    m_fullscreen = false;
    m_window.setFramerateLimit(60);
}

Game::Game()
{
    this->scrXmetric = GetSystemMetrics(SM_CXSCREEN);
    this->scrYmetric = GetSystemMetrics(SM_CYSCREEN);

    if (m_fullscreen) setFullscreenMode();
    else
    m_window.create(sf::VideoMode(standartWsizeX, standartWsizeY), "Robots vs mutants", sf::Style::Default);

    m_window.setFramerateLimit(60);
    m_font.loadFromFile("src/fonts/sfns-display-bold.ttf");
    loadAllTextures();
}

Game::~Game()
{
    std::cout << "pop of all states" << std::endl;
    while (!m_states.empty())
        popState();
    m_states.shrink_to_fit();
}

void Game::loadAllTextures()
{
    m_textureManager.loadTexture("src/textures/Cell.png", "Cell");
}

#pragma region Internal Class _TextureManager

void Game::_TextureManager::loadTexture(const sf::String& path, const sf::String& name)
{
    textures.emplace(std::make_pair(name, new sf::Texture));
    textures.at(name)->loadFromFile(path);
}

const sf::Texture& Game::_TextureManager::GetTextureRef(const sf::String& name) const
{
    return *textures.at(name);
}

#pragma endregion

