#include "CPU.h"

CPU::CPU(std::string_view label, const unsigned short numberOfCores, const unsigned short clockSpeed)
	  : Component(label), m_clockSpeed(clockSpeed) {
	if (numberOfCores < 1 || numberOfCores > 8)
		throw "Number of cores should be between 1 and 8";

	m_numberOfCores = numberOfCores;
}

double CPU::price() const {
	return m_numberOfCores * PRICE_MULTIPLIER;
}
