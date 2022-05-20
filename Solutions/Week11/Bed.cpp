#include "Bed.h"

Bed::Bed(const double height, const double width, const double length, const int quantity)
	: Furniture(height, width, length, quantity) {
	m_price = calculatePrice();
}

Bed::Bed(const Bed& bed) : Furniture(bed) {
}

const std::string Bed::getInfo() const {
	std::string result = Furniture::getInfo();

	result.replace(0, 9, "Bed");

	return result;
}

const std::string Bed::getStrComparator() const {
	return "Bed " + Furniture::getStrComparator();
}

Furniture* Bed::clone() {
	return new Bed(m_height, m_width, m_length, m_quantity);
}

double Bed::calculatePrice() const {
	return m_length * m_height * 22;
}
