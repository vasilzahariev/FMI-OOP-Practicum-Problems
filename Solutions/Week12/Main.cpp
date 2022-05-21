#include <iostream>

#include "FacultyMember.h"

int main() {
	std::string name = "Evgenia Velikova";
	FacultyMember* fm = new FacultyMember(name, 25, 1000);

	std::cout << fm->getName() << std::endl;
	std::cout << fm->getNumber() << std::endl;
	std::cout << fm->getSalary() << std::endl;

	delete fm;

	return 0;
}
