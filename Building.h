#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Building
{
public:
	Building();
	virtual ~Building();
	void update()
	{
		this->produce();
		this->doSomething();
		this->attack();
	}
	void takeDamage(int val);
	void restoreHp(int val);
	void restoreProtection(int val);
protected:
	virtual void attack() = 0;
	virtual void produce();
	virtual void doSomething();
	int m_attackSpeed = 0;
	int m_attackDamage = 0;
	int m_costParts = 0;
	int m_costBio = 0;
	int m_hp = 0;
	int m_hpMax = 0;
	int m_armorInt = 0;
	int m_armorPer = 0;
	int m_protection = 0;
	int m_protectionMax = 0;

	sf::Sprite m_sprite;
};