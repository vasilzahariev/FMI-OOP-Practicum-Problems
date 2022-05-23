#ifndef MEMORY_H
#define MEMORY_H

#include "Component.h"

class Memory : public Component {
public:
	Memory(std::string_view label, const unsigned short capacity);

	double price() const override;

private:
	const double PRICE_MULTIPLIER = 89.99;

	unsigned short m_capacity;
};

#endif // !MEMORY_H
