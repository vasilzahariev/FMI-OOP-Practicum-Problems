#ifndef CPU_H
#define CPU_H

#include "Component.h"

class CPU : public Component {
public:
	CPU(std::string_view label, const unsigned short numberOfCores, const unsigned short clockSpeed);

	double price() const override;

private:
	const double PRICE_MULTIPLIER = 29.99;

	unsigned short m_numberOfCores;
	unsigned short m_clockSpeed;
};

#endif // !CPU_H
