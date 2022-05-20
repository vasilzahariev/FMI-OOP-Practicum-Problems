#include "Lecturer.h"

Lecturer::Lecturer(std::string_view name, const double salary)
			: Person(name), m_salary(salary) {
}

const double Lecturer::getSalary() const {
	return m_salary;
}
