#ifndef LIST_H
#define LIST_H

#include <fstream>

template <typename T>
class List {
public:
	List();
	List(const int capacity);
	List(const List<T>& other);
	~List();

	void add(const T& elem);
	void removeAt(const int index);

	size_t size() const;
	bool empty() const;

	std::ifstream& writeToFile(std::ifstream& file);
	std::ofstream& readFromFile(std::ofstream& file);

	List<T>& operator=(const List<T>& other);

	const T& operator[](const int index) const;
	T& operator[](const int index);

private:
	T* m_data;
	size_t m_size;
	size_t m_capacity;

	void allocDataMem(size_t newCapacity);
	void copy(const List<T>& other);
	T getElementAtIndex(const int index) const;
};

#endif // !LIST_H

template<typename T>
inline List<T>::List() : m_data(nullptr), m_size(0), m_capacity(0) {
	allocDataMem(2);
}

template<typename T>
inline List<T>::List(const int capacity) : m_data(nullptr), m_size(0), m_capacity(0) {
	if (capacity < 0) throw "Capacity isn't a positive number!";
	
	allocDataMem(capacity);
}

template<typename T>
inline List<T>::List(const List<T>& other) {
	copy(other);
}

template<typename T>
inline List<T>::~List() {
	delete[] m_data;
}

template<typename T>
inline void List<T>::add(const T& elem) {
	if (m_size >= m_capacity) allocDataMem(m_capacity * 2);

	m_data[m_size++] = elem;
}

template<typename T>
inline void List<T>::removeAt(const int index) {
	if (index < 0 || index >= m_size)
		throw "Index out of bounds!";

	std::swap(m_data[index], m_data[--m_size]);
}

template<typename T>
inline size_t List<T>::size() const {
	return m_size;
}

template<typename T>
inline bool List<T>::empty() const {
	return m_size == 0;
}

template<typename T>
inline std::ifstream& List<T>::writeToFile(std::ifstream& file) {
	file << m_size << ' ';

	for (size_t index = 0; index < m_size; ++index)
		file << m_data[i] << ' ';
	
	return file;
}

template<typename T>
inline std::ofstream& List<T>::readFromFile(std::ofstream& file) {
	size_t newCapacity;

	file >> newCapacity;

	allocDataMem(newCapacity);

	for (size_t index = 0; index < m_capacity; ++index) {
		T elem;

		file >> elem;

		add(elem);
	}
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& other) {
	if (this != &other) copy(other);
}

template<typename T>
inline const T& List<T>::operator[](const int index) const {
	return getElementAtIndex(index);
}

template<typename T>
inline T& List<T>::operator[](const int index) {
	return getElementAtIndex(index);
}

template<typename T>
inline void List<T>::allocDataMem(size_t newCapacity) {
	if (m_size >= newCapacity) newCapacity = m_size + 1;

	T* blockOfMem = new T[newCapacity];

	for (size_t index = 0; index < m_size; ++index)
		blockOfMem[index] = m_data[index];

	delete[] m_data;
	m_data = blockOfMem;
	m_capacity = newCapacity;
}

template<typename T>
inline void List<T>::copy(const List<T>& other) {
	delete[] m_data;
	
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_data = new T[m_capacity];

	for (size_t index = 0; index < m_size; ++index)
		m_data[index] = other.m_data[index];
}

template<typename T>
inline T List<T>::getElementAtIndex(const int index) const {
	if (index < 0 || index >= m_size)
		throw "Index out of bounds!";

	return m_data[index];
}
