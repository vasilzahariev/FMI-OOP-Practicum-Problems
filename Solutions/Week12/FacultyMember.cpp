#include "FacultyMember.h"

FacultyMember::FacultyMember(std::string_view name, const int number, const double salary)
				: Student(name, number), Lecturer(name, salary), Person(name) {
}

std::istream& operator>>(std::istream& in, FacultyMember& facultyMember) {
	return std::getline((in >> facultyMember.m_number >> facultyMember.m_salary), facultyMember.m_name);
}

std::ostream& operator<<(std::ostream& out, const FacultyMember& facultyMember) {
	return (out << facultyMember.getNumber() << " " << facultyMember.getSalary() << " " << facultyMember.getName() << std::endl);
}
