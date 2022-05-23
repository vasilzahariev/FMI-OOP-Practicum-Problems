#include "Configuration.h"

Configuration::~Configuration() {

}

double Configuration::price() const {
	double sum = 0;

	for (size_t index = 0; index < m_components.size(); ++index)
		sum += m_components[index];

	return sum;
}

std::size_t Configuration::size() const {
	return m_components.size();
}

const Component& Configuration::operator[](const size_t index) const {
	if (index < 0 || index >= m_components.size())
		throw "Index out of bounds!";

	return *m_components[index];
}
