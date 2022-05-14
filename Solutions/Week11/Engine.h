#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

#include "Utility.h"

#include "Furniture.h"
#include "Table.h"
#include "Chair.h"
#include "Bed.h"

class Engine {
public:
	~Engine();

	static Engine& getInstance();

	void run();

private:
	Engine();
	Engine(const Engine& engine) = delete;
	Engine& operator=(const Engine& other) = delete;

private:
	Furniture** m_data;
	size_t m_size;
	size_t m_capacity;

	void deleteData();
	void allocData(size_t newCapacity);

	void printOperations();
	void enterOperation(char& operation) const;
	void executeOperation(const char operation);

	const int getFurnitureIdFromUser() const;
	Furniture* getFurnitureAtID(const int id) const;

	void addFurniture();
	Furniture* getFurnitureTypeFromUser() const;
	const std::string getValidFurnitureTypeFromUser() const;
	const bool checkIfFurnitureExists(Furniture* furniture);

	void removeFurnitureByID();
	void removeFurniture(Furniture* furniture);

	void printFurnitureByID() const;

	void printTheMostExpensiveFurniture() const;
	const Furniture* getTheMostExpensiveFurniture() const;
};

#endif // !ENGINE_H
