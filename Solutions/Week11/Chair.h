#ifndef CHAIR_H
#define CHAIR_H

#include "Furniture.h"
#include "ChairType.h"

class Chair : public Furniture {
public:
	Chair(const double height = 0, const double width = 0, const double length = 0, const int quantity = 0, const ChairType type = ChairType::WOODEN);

	void read(std::istream& in) override;

	const std::string getInfo() const override;

	const std::string getStrComparator() const override;

protected:
	double calculatePrice() const override;

private:
	ChairType m_type;
};

#endif // !CHAIR_h
