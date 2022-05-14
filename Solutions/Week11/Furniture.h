#ifndef FURNITURE_H
#define FURNITURE_H

#include <iostream>
#include <string>

#include "Utility.h"

class Furniture {
public:
	static int COUNTER;

public:
	Furniture(const double height = 0, const double width = 0, const double length = 0, const int quantity = 0);

	int getID() const;

	int getQuantity() const;

	void setQuantity(const int quantity);

	double getPrice() const;

	virtual void read(std::istream& in);

	virtual const std::string getInfo() const;

	virtual const std::string getStrComparator() const;

protected:
	virtual double calculatePrice() const;

protected:
	int m_id;
	double m_height;
	double m_width;
	double m_length;
	int m_quantity;
	double m_price;
};

#endif // !FURNITURE_H
