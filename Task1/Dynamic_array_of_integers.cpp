#include <iostream>
#include "Dynamic_array_of_integers.h"

ArrayList::ArrayList() : arrayList{new int[100]}, size{0} {}

ArrayList::ArrayList(int size) : arrayList{new int[size]}, size{0} {}

ArrayList::ArrayList(ArrayList &Arr) : arrayList{nullptr}, size{0} {
	this->arrayList = new int[Arr.size];
	this->size = Arr.size;

	for (int i = 0; i < Arr.size; i++) {
		this->arrayList[i] = Arr.arrayList[i];
	}
}

ArrayList::ArrayList(ArrayList &&Arr) : arrayList{nullptr}, size{0} {
	arrayList = Arr.arrayList;
	size = Arr.size;
	Arr.size = 0;
}

ArrayList::~ArrayList() {
	size = 0;
	delete[] arrayList;
}

int& ArrayList::getArray() const {
	return *arrayList;
}

int ArrayList::length() {
	return size;
}

void ArrayList::resize(int newSize) {
	int *resArr = new int[newSize];

	if (size >= newSize) {
		for (int i = 0; i < size; i++) {
			resArr[i] = arrayList[i];
		}
	}
	if (size < newSize) {
		for (int i = 0; i < size; i++) {
			resArr[i] = arrayList[i];
		}
		for (int i = 0; i < newSize - size; i++) {
			resArr[i] = 0;
		}
	}

	delete[] arrayList;
	arrayList = resArr;
}

int ArrayList::operator[] (int index) {
	if ((index >= 0) && (index <= size - 1)) {
		return arrayList[index];
	}
}