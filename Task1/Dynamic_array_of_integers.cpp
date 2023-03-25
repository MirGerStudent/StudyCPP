#include <iostream>
#include "Dynamic_array_of_integers.h"

ArrayList::ArrayList() : arrayList{new int[100]}, size{100}, len{0} {}

ArrayList::ArrayList(int size) : arrayList{new int[size]}, size{size}, len{0} {}

ArrayList::ArrayList(ArrayList &Arr) : arrayList{new int[Arr.size]}, size{Arr.size}, len{Arr.len} {
	for (int i = 0; i < Arr.len; i++) {
		this->arrayList[i] = Arr.arrayList[i];
	}
}

ArrayList::ArrayList(ArrayList &&Arr) {
	arrayList = Arr.arrayList;
	size = Arr.size;
	len = Arr.len;

	Arr.len = 0;
	Arr.size = 0;
	Arr.arrayList = nullptr;
}

ArrayList::~ArrayList() {
	len = 0;
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

ArrayList& ArrayList::operator= (const ArrayList &Arr) {
	if (this != &Arr) {
		int *newArr = new int[Arr.size];

		for (int i = 0; i < Arr.size; i++) {
			newArr[i] = Arr.arrayList[i];
		}

		delete[] arrayList;

		arrayList = newArr;
		size = Arr.size;
	}

	return *this;
}

bool ArrayList::operator== (const ArrayList &Arr) {
	bool res = true;

	if (this->size == Arr.size) {
		for (int i = 0; i < size; i++) {
			if (Arr.arrayList[i] != this->arrayList[i]) {
				res = false;
				break;
			}
		}
	} else {
		
	}

	return res;
}

ArrayList& ArrayList::operator+ (const ArrayList &Arr) {
	ArrayList res = ArrayList(Arr.size + size);

	for (int i = 0; i < size; i++) {
		res.arrayList[i] = arrayList[i];
	}
	for (int i = size; i < Arr.size + size; i++ ) {
		res.arrayList[i] = Arr.arrayList[i];
	}

	return res;
}