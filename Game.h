#pragma once

class GameState;

#include <vector>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <map>
#include <iostream>
#include <memory>
#include <iterator>
#include "Player.h"

class Game
{
    class _TextureManager
    {
        std::map<sf::String, std::shared_ptr<sf::Texture>> textures;
    public:

        void loadTexture(const sf::String& path, const sf::String& name);

        const sf::Texture& GetTextureRef(const sf::String& name) const;
    };

    void loadAllTextures();
public:

    void setFullscreenMode();
    void cancelFullscreenMode();

    unsigned int standartWsizeX = 950; 
    unsigned int standartWsizeY = 750; 

    unsigned int scrXmetric;
    unsigned int scrYmetric;

    _TextureManager m_textureManager;

    Player m_player;

    sf::Font m_font;

    bool m_fullscreen = true;

    sf::String m_language = "Russian";

    std::vector<GameState*> m_states;

    sf::RenderWindow m_window;

    void pushState(GameState* state);

    void popState();

    void changeState(GameState* state);

    GameState* peekState();

    void gameLoop();

    Game();

    ~Game();
};
