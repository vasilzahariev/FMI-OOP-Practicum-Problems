#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <vector>

#include "Component.h"

class Configuration {
public:
	~Configuration();

	double price() const;
	std::size_t size() const;

	const Component& operator[](const size_t index) const;

	friend std::ostream& operator<<(std::ostream& out, const Configuration& configuration);

private:
	Configuration() = default;

	std::vector<const Component*> m_components;
};

#endif // !CONFIGURATION_H
