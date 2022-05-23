#include "Factory.h"

Factory::Factory() {
}

void Factory::getComponentInput(std::string& label) const {
	std::cout << "Enter Label: " << std::endl;
	std::getline(std::cin, label);
}

void Factory::getCPUInput(std::string& label, unsigned short& numberOfCores, unsigned short& clockSpeed) const {
	getComponentInput(label);

	std::cout << "Enter Number of Cores: " << std::endl;
	std::cin >> numberOfCores;

	std::cout << "Enter Clock Speed: " << std::endl;
	std::cin >> clockSpeed;
}

void Factory::getMemoryInput(std::string& label, unsigned short& capacity) const {
	getComponentInput(label);

	std::cout << "Enter Capacity: " << std::endl;
	std::cin >> capacity;
}

Component* Factory::createCPU() const {
	std::string label;
	unsigned short numberOfCores;
	unsigned short clockSpeed;

	getCPUInput(label, numberOfCores, clockSpeed);

	return new CPU(label, numberOfCores, clockSpeed);
}

Component* Factory::createMemory() const {
	std::string label;
	unsigned short capacity;

	getMemoryInput(label, capacity);

	return new Memory(label, capacity);
}

Factory& Factory::getInstance() {
	static Factory factory;
	
	return factory;
}

Component* Factory::createComponent() {
	std::string input;

	std::cout << "Enter component type (cpu | memory): " << std::endl;
	std::getline(std::cin, input);

	if (input == "cpu")
		return createCPU();
	else if (input == "memory")
		return createMemory();
	
	return nullptr;
}
