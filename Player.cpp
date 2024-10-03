#pragma once

#include "Player.h"

bool Player::isDefeated()
{
    if (m_health <= 0) return true;
    return false;
}
