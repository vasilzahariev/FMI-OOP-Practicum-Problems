#include "Person.h"

Person::Person() {
}

Person::Person(std::string_view name)
		 : m_name(name) {
}

std::string_view Person::getName() const {
	return m_name;
}
