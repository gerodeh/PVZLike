#include "Building.h"

void Building::takeDamage(int val)
{
	m_protection -= val;
	if (m_protection <= 0)
	{
		val = std::abs(m_protection);
		m_protection = 0;
	}
	val -= m_armorInt;
	if (val <= 0) return;
	val *= 1-(double)m_armorPer*0.01;
	m_hp -= val;
}

void Building::restoreHp(int val)
{
	m_hp += val;
	if (m_hp > m_hpMax) m_hp = m_hpMax;
}

void Building::restoreProtection(int val)
{
	m_protection += val;
	if (m_protection > m_protectionMax) m_protection = m_protectionMax;
}

void Building::produce()
{

}

void Building::doSomething()
{

}