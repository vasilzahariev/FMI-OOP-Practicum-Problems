#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include <string_view>

class Computer {
public:
	static int COUNTER;

public:
	Computer(std::string_view brand, std::string_view processor, std::string_view GPU,
			 std::string_view HDD, const double weight, std::string_view batteryLife,
			 const double price, const int quantity);

	int getSerialNumber() const;

	void setBrand(std::string_view brand);
	std::string_view getBrand() const;

	void setProcessor(std::string_view processor);
	std::string_view getProcessor() const;

	void setGPU(std::string_view GPU);
	std::string_view getGPU() const;

	void setHDD(std::string_view HDD);
	std::string_view getHDD() const;

	void setWeight(const double weight);
	double getWeigth() const;

	void setBatteryLife(std::string_view batteryLife);
	std::string_view getBatteryLife() const;

	void setPrice(const double price);
	double getPrice() const;

	void setQuantity(const int quantity);
	int getQuantity() const;

	friend std::istream& operator>>(std::istream& in, Computer& computer);
	friend std::ostream& operator<<(std::ostream& out, const Computer& computer);

private:
	int m_serialNumber;
	std::string m_brand;
	std::string m_processor;
	std::string m_GPU;
	std::string m_HDD;
	double m_weight;
	std::string m_batteryLife;
	double m_price;
	int m_quantity;
};

#endif // !COMPUTER_H
