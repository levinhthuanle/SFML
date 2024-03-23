#pragma once
//Make vector class to store CSV files' data
#include "Requirement.h"

template <class T>

class Vector {
private:
	std::string Name;
	T* vector;
	int size;		//Current size of the vector (Number of element)
	int maxSize;	//Maximum size of the vector's array (If reached double it)

public:
	Vector() {
		vector = new T[1];
		size = 0;
		maxSize = 0;
	}

	Vector(std::string Name) {
		vector = new T[1];
		size = 0;
		maxSize = 0;
		this->Name = Name;
	}

	void push_back(T add) {					//Push element to the back of vector
		if (size == maxSize) {
			T* temp = new T[2 * maxSize];
			for (int i = 0; i < size; i++)
				temp[i] = vector[i];
			delete[] vector;
			vector = temp;
			maxSize *= 2;
		}
		vector[size++] = add;
	}

	T getElement(int index) {				//Return value of element at index
		if (index >= size) return -1;
		return vector[index];
	}

	bool setElement(int index, T val) {		//Set value of element at index
		if (index >= size) return false;
		vector[index] = val;
		return true;
	}

	//void pop_back() {						//Pop element from the back of vector
	//	if (size == 0) return;
	//	if (std::is_pointer<T>::vall) delete[] 
	//}

	int sizeOf() {							//Return vector's size
		return this->size;
	}

	void del() {
		delete[] vector;
	}

	//~Vector() {
	//	for (int i = 0; i < this->maxSize; i++) {
	//		if (std::is_pointer<T>::value) delete[] vector[i];
	//		else delete vector[i];
	//	}
	//}
};
#pragma once
//Make vector class to store CSV files' data

#include <iostream>
#include <type_traits>

template <class T>

class Vector {
private:
	std::string Name;
	T* vector;
	int size;		//Current size of the vector (Number of element)
	int maxSize;	//Maximum size of the vector's array (If reached double it)

public:
	Vector() {
		vector = new T[1];
		size = 0;
		maxSize = 0;
	}

	Vector(std::string Name) {
		vector = new T[1];
		size = 0;
		maxSize = 0;
		this->Name = Name;
	}

	void push_back(T add) {					//Push element to the back of vector
		if (size == maxSize) {
			T* temp = new T[2 * maxSize];
			for (int i = 0; i < size; i++)
				temp[i] = vector[i];
			delete[] vector;
			vector = temp;
			maxSize *= 2;
		}
		vector[size++] = add;
	}

	T getElement(int index) {				//Return value of element at index
		if (index >= size) return -1;
		return vector[index];
	}

	bool setElement(int index, T val) {		//Set value of element at index
		if (index >= size) return false;
		vector[index] = val;
		return true;
	}

	//void pop_back() {						//Pop element from the back of vector
	//	if (size == 0) return;
	//	if (std::is_pointer<T>::vall) delete[] 
	//}

	int sizeOf() {							//Return vector's size
		return this->size;
	}

	void del() {
		delete[] vector;
	}

	//~Vector() {
	//	for (int i = 0; i < this->maxSize; i++) {
	//		if (std::is_pointer<T>::value) delete[] vector[i];
	//		else delete vector[i];
	//	}
	//}
};
