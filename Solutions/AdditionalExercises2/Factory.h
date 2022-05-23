#ifndef FACTORY_H
#define FACTORY_H

#include "Component.h"
#include "CPU.h"
#include "Memory.h"

class Factory {
public:
	static Factory& getInstance();

	Component* createComponent();

private:
	Factory();
	Factory(const Factory& other) = delete;
	Factory& operator=(const Factory& other) = delete;

	void getComponentInput(std::string& label) const;
	void getCPUInput(std::string& label, unsigned short& numberOfCores, unsigned short& clockSpeed) const;
	void getMemoryInput(std::string& label, unsigned short& capacity) const;

	Component* createCPU() const;
	Component* createMemory() const;
};

#endif // !FACTORY_H
