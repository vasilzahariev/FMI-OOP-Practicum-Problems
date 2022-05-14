#include "Table.h"

Table::Table(const double height, const double width, const double length, const int quantity, const TableType type)
	: Furniture(height, width, length, quantity), m_type(type) {
	m_price = calculatePrice();
}

void Table::read(std::istream& in) {
	Furniture::read(in);

	std::cout << "Enter Table Type (living room | kitchen): ";

	std::string tableType;

	do {
		std::getline(in, tableType);

		tableType = Utility::toLowerStr(tableType);
	} while (tableType != "living room" && tableType != "kitchen");

	m_type = (tableType == "living room" ? TableType::LIVING_ROOM : TableType::KITCHEN);
}

const std::string Table::getInfo() const {
	std::string result = Furniture::getInfo();

	result.replace(0, 9, "Table");

	std::string type = (m_type == TableType::LIVING_ROOM ? "Living Room" : "Kitchen");

	result += "Type: " + type + '\n';

	return result;
}

const std::string Table::getStrComparator() const {
	return "Table " +
		Furniture::getStrComparator() + " " +
		std::to_string(m_type == TableType::LIVING_ROOM ? 0 : 1);
}

double Table::calculatePrice() const {
	return m_width * m_length * 15;
}
