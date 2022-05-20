#ifndef LECTURER_H
#define LECTURER_H

#include "Person.h"

class Lecturer : virtual public Person {
public:
	Lecturer(std::string_view name, const double salary);

	const double getSalary() const;

protected:
	double m_salary;
};

#endif // !LECURER_H
