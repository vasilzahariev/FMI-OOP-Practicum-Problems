#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <string>
#include <string_view>

class Component {
	virtual double price() const = 0;

	void output(std::ostream& out) const;

protected:
	Component(std::string_view label);

protected:
	std::string m_label;
};

#endif // !COMPONENT_H
