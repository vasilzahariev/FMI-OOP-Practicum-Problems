#include "Computer.h"

int Computer::COUNTER = 0;

Computer::Computer(std::string_view brand, std::string_view processor, std::string_view GPU, std::string_view HDD, const double weight, std::string_view batteryLife, const double price, const int quantity)
			: m_brand(brand), m_processor(processor), m_GPU(GPU),
			  m_HDD(HDD), m_weight(weight), m_batteryLife(batteryLife),
			  m_price(price), m_quantity(quantity) {
	m_serialNumber = ++COUNTER;
}

int Computer::getSerialNumber() const {
	return m_serialNumber;
}

void Computer::setBrand(std::string_view brand) {
	m_brand = brand;
}

std::string_view Computer::getBrand() const {
	return m_brand;
}

void Computer::setProcessor(std::string_view processor) {
	m_processor = processor;
}

std::string_view Computer::getProcessor() const {
	return m_processor;
}

void Computer::setGPU(std::string_view GPU) {
	m_GPU = GPU;
}

std::string_view Computer::getGPU() const {
	return m_GPU;
}

void Computer::setHDD(std::string_view HDD) {
	m_HDD = HDD;
}

std::string_view Computer::getHDD() const {
	return m_HDD;
}

void Computer::setWeight(const double weight) {
	m_weight = weight;
}

double Computer::getWeigth() const {
	return m_weight;
}

void Computer::setBatteryLife(std::string_view batteryLife) {
	m_batteryLife = batteryLife;
}

std::string_view Computer::getBatteryLife() const {
	return m_batteryLife;
}

void Computer::setPrice(const double price) {
	m_price = price;
}

double Computer::getPrice() const {
	return m_price;
}

void Computer::setQuantity(const int quantity) {
	m_quantity = quantity;
}

int Computer::getQuantity() const {
	return m_quantity;
}

std::istream& operator>>(std::istream& in, Computer& computer) {
	std::getline(in, computer.m_brand);
	std::getline(in, computer.m_processor);
	std::getline(in, computer.m_GPU);
	std::getline(in, computer.m_HDD);
	in >> computer.m_weight;
	std::getline(in, computer.m_batteryLife);
	in >> computer.m_price;
	in >> computer.m_quantity;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Computer& computer) {
	out << "Computer:" << '\n';
	out << "Serial Number: " << computer.m_serialNumber << '\n';
	out << "Brand: " << computer.m_brand << '\n';
	out << "Processor: " << computer.m_processor << '\n';
	out << "GPU: " << computer.m_GPU << '\n';
	out << "HDD: " << computer.m_HDD << '\n';
	out << "Weight: " << computer.m_weight << '\n';
	out << "Battery Life: " << computer.m_batteryLife << '\n';
	out << "Price: " << computer.m_price << '\n';
	out << "Quantity: " << computer.m_quantity << '\n';

	return out;
}
