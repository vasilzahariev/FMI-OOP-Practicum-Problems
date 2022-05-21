#ifndef COMPUTERSHOP_H
#define COMPUTERSHOP_H

#include "List.h"
#include "Computer.h"

class ComputerShop {
public:
	ComputerShop(std::string_view name);

	void addComputer(const Computer& computer);

	void buyComputer(std::string_view pcBrand, const double buyerMoney);

	void printAllAvailablePcByCriteria(bool (*criteria)(const Computer&)) const;

	void print() const;

private:
	std::string m_name;
	List<Computer> m_computers;

	int getIndexOfPc(const Computer& computer) const;
};

#endif // !COMPUTERSHOP_H
