#include "Memory.h"
#include "Memory.h"

Memory::Memory(std::string_view label, const unsigned short capacity)
		: Component(label) {
	if (capacity < 1 || capacity > 10000)
		throw "Capacity should be between 1 and 10 000";

	m_capacity = capacity;
}

double Memory::price() const {
	return m_capacity * PRICE_MULTIPLIER;
}
