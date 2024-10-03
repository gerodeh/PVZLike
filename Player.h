#pragma once

class Player
{
public:
    int m_health;
    int m_parts = 0;
    int m_bio = 0;

    bool isDefeated();
};