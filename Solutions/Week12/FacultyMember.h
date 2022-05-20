#ifndef FACULTYMEMBER_H
#define FACULTYMEMBER_H

#include "Student.h"
#include "Lecturer.h"

class FacultyMember : public Student, public Lecturer {
public:
	FacultyMember(std::string_view name, const int number, const double salary);

	friend std::istream& operator>>(std::istream& in, FacultyMember& facultyMember);
	friend std::ostream& operator<<(std::ostream& out, const FacultyMember& facultyMember);

private:
	//
};

#endif // !FACULTYMEMBER_H
