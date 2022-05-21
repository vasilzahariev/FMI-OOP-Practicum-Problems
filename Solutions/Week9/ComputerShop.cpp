#include "ComputerShop.h"

ComputerShop::ComputerShop(std::string_view name)
				: m_name(name) {
}

void ComputerShop::addComputer(const Computer& computer) {
	const int pcIndex = getIndexOfPc(computer);

	if (pcIndex == -1) m_computers.add(computer);
	else m_computers[pcIndex].setQuantity(m_computers[pcIndex].getQuantity() + 1);
}

void ComputerShop::buyComputer(std::string_view pcBrand, const double buyerMoney) {
	for (size_t index = 0; index < m_computers.size(); ++index) {
		Computer& pc = m_computers[index];
		
		if (pc.getBrand() == pcBrand) {
			if (pc.getPrice() <= buyerMoney &&
				pc.getQuantity() > 0)
				pc.setQuantity(pc.getQuantity() - 1);
			else
				std::cout << "Unable to Buy";
		}
	}
}

void ComputerShop::printAllAvailablePcByCriteria(bool(*criteria)(const Computer&)) const {
	for (size_t index = 0; index < m_computers.size(); ++index)
		if (criteria(m_computers[index]))
			std::cout << m_computers[index] << std::endl;
}

void ComputerShop::print() const {
	std::cout << "Computer Shop \"" << m_name << "\":" << std::endl;

	for (size_t index = 0; index < m_computers.size(); ++index)
		std::cout << m_computers[index] << std::endl;
}

int ComputerShop::getIndexOfPc(const Computer& computer) const {
	for (size_t index = 0; index < m_computers.size(); ++index)
		if (computer.getSerialNumber() == m_computers[index].getSerialNumber())
			return index;

	return -1;
}
