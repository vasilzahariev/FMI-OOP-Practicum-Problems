#include "Engine.h"

Engine::~Engine() {
	deleteData();
}

Engine& Engine::getInstance() {
	static Engine engine;

	return engine;
}

Engine::Engine() : m_data(nullptr), m_size(0), m_capacity(0) {
	allocData(2);
}

void Engine::run() {
	char operation;

	do {
		printOperations();
		enterOperation(operation);
		executeOperation(operation);
	} while (operation != '5');
}

void Engine::deleteData() {
	for (size_t i = 0; i < m_capacity; ++i) {
		delete m_data[i];
		m_data[i] = nullptr;
	}

	delete[] m_data;
	m_data = nullptr;
}

void Engine::allocData(size_t newCapacity) {
	if (m_size >= newCapacity) newCapacity = m_size + 1;

	Furniture** blockMem = new Furniture*[newCapacity] { nullptr, };

	Furniture::COUNTER = 0;

	for (size_t i = 0; i < m_size; ++i)
		blockMem[i] = m_data[i]->clone();

	deleteData();
	m_data = blockMem;
	m_capacity = newCapacity;
}

void Engine::printOperations() {
	std::cout << "Select an operation:" << std::endl;
	std::cout << "1) Add a furniture" << std::endl;
	std::cout << "2) Remove a furniture" << std::endl;
	std::cout << "3) Show information about a furniture" << std::endl;
	std::cout << "4) Show information about the most expensive furniture" << std::endl;
	std::cout << "5) Exit" << std::endl;
}

void Engine::enterOperation(char& operation) const {
	std::cout << "Enter: ";

	std::cin >> operation;
}

void Engine::executeOperation(const char operation) {
	if (operation == '1')
		addFurniture();
	else if (operation == '2')
		removeFurnitureByID();
	else if (operation == '3')
		printFurnitureByID();
	else if (operation == '4')
		printTheMostExpensiveFurniture();
	else if (operation != '5')
		std::cout << "Invalid operation!" << std::endl;
}

const int Engine::getFurnitureIdFromUser() const {
	std::cout << "Enter Furniture Id: ";

	int id;

	std::cin >> id;

	return id;
}

Furniture* Engine::getFurnitureAtID(const int id) const {
	for (size_t i = 0; i < m_size; ++i)
		if (m_data[i]->getID() == id)
			return m_data[i];

	return nullptr;
}

void Engine::addFurniture() {
	if (m_size == m_capacity) allocData(m_capacity * 2);

	Furniture* newFurniture = getFurnitureTypeFromUser();

	newFurniture->read(std::cin);

	if (checkIfFurnitureExists(newFurniture)) {
		delete newFurniture;
		newFurniture = nullptr;

		return;
	}

	m_data[m_size++] = newFurniture;
}

Furniture* Engine::getFurnitureTypeFromUser() const {
	std::string furnitureType = getValidFurnitureTypeFromUser();

	if (furnitureType == "bed")
		return new Bed();
	else if (furnitureType == "chair")
		return new Chair();
	else if (furnitureType == "table")
		return new Table();

	return nullptr;
}

const std::string Engine::getValidFurnitureTypeFromUser() const {
	std::cout << "Enter furniture type (bed, chair, table): ";

	std::string furnitureType;

	do {
		std::cin >> furnitureType;

		furnitureType = Utility::toLowerStr(furnitureType);
	} while (furnitureType != "bed" && furnitureType != "chair" && furnitureType != "table");

	return furnitureType;
}

const bool Engine::checkIfFurnitureExists(Furniture* furniture) {
	for (size_t i = 0; i < m_size; ++i) {
		if (m_data[i]->getStrComparator() == furniture->getStrComparator()) {
			m_data[i]->setQuantity(m_data[i]->getQuantity() + furniture->getQuantity());

			--Furniture::COUNTER;

			return true;
		}
	}

	return false;
}

void Engine::removeFurnitureByID() {
	const int ID = getFurnitureIdFromUser();

	Furniture* furniture = getFurnitureAtID(ID);

	if (furniture == nullptr) std::cout << "Invalid ID" << std::endl;
	else removeFurniture(furniture);
}

void Engine::removeFurniture(Furniture* furniture) {
	furniture->setQuantity(furniture->getQuantity() - 1);

	if (furniture->getQuantity() == 0) {
		std::swap(furniture, m_data[--m_size]);
	}
}

void Engine::printFurnitureByID() const {
	const int ID = getFurnitureIdFromUser();

	const Furniture* furniture = getFurnitureAtID(ID);

	if (furniture == nullptr) std::cout << "Invalid ID" << std::endl;
	else std::cout << furniture->getInfo() << std::endl;
}

void Engine::printTheMostExpensiveFurniture() const {
	if (m_size == 0)
		std::cout << "There are no furnitures in store!" << std::endl;
	else
		std::cout << getTheMostExpensiveFurniture()->getInfo() << std::endl;
}

const Furniture* Engine::getTheMostExpensiveFurniture() const {
	Furniture* mostExpensiveFurniture = nullptr;

	for (size_t i = 0; i < m_size; ++i)
		if (mostExpensiveFurniture == nullptr ||
			m_data[i]->getPrice() > mostExpensiveFurniture->getPrice())
			mostExpensiveFurniture = m_data[i];

	return mostExpensiveFurniture;
}
