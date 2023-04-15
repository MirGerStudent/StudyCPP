#include "Dynamic_array_of_integers.h"
#include "Exception.cpp"

ArrayList::ArrayList() : arrayList{new int[10]}, size{10} {
	for (int i = 0; i < 10; i++) {
		arrayList[i] = 0;
	}
}

ArrayList::ArrayList(int size) : arrayList{new int[size]}, size{size} {
	for (int i = 0; i < size; i++) {
		arrayList[i] = 0;
	}
}

ArrayList::ArrayList(int size, int number) : arrayList{new int[size]}, size{size} {
	for (int i = 0; i < size; i++) {
		arrayList[i] = number;
	}
}

ArrayList::ArrayList(const ArrayList &Arr) : arrayList{new int[Arr.size]}, size{Arr.size} {
	for (int i = 0; i < Arr.size; i++) {
		this->arrayList[i] = Arr.arrayList[i];
	}
}

ArrayList::ArrayList(ArrayList &&Arr) : arrayList{Arr.arrayList}, size{Arr.size} {
	Arr.size = 0;
	Arr.arrayList = nullptr;
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
		for (int i = 0; i < size; i++) resArr[i] = arrayList[i];
	}
	if (size < newSize) {
		for (int i = 0; i < size; i++) resArr[i] = arrayList[i];
		for (int i = 0; i < newSize - size; i++) resArr[i] = 0;
	}

	delete[] arrayList;
	arrayList = resArr;
}

int& ArrayList::operator[] (int index) {
	if ((index >= 0) && (index <= size - 1)) {
		return arrayList[index];
	}
}

int ArrayList::operator[] (int index) const {
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

ArrayList& ArrayList::operator= (ArrayList &&Arr) {
	if (this != &Arr) {
		delete[] arrayList;

		arrayList = Arr.arrayList;
		size = Arr.size;

		Arr.arrayList = nullptr;
		Arr.size = 0;
	}

	return *this;
}

bool ArrayList::operator== (const ArrayList &Arr) const{
	if (this->size != Arr.size) {
		DAIException("Размеры массивов не совпадают!");
	}

	try {
		bool res = true;

		for (int i = 0; i < size; i++) {
			if (Arr.arrayList[i] != this->arrayList[i]) {
				res = false;
				break;
			}
		}

		return res;
	}
	catch(const DAIException& e) {
		std::cerr << e.what() << '\n';
	}
}

bool ArrayList::operator!= (const ArrayList &Arr) const {
	if (this->size != Arr.size) {
		DAIException("Размеры массивов не совпадают!");
	}

	try {
		bool res = false;

		for (int i = 0; i < size; i++) {
			if (Arr.arrayList[i] == this->arrayList[i]) {
				res = true;
				break;
			}
		}

		return res;
	}
	catch(const DAIException& e) {
		std::cerr << e.what() << '\n';
	}
}

ArrayList operator+ (const ArrayList &Arr1, const ArrayList &Arr2) {
	ArrayList res = ArrayList(Arr1.size + Arr2.size);

	for (int i = 0; i < Arr1.size; i++) {
		res.arrayList[i] = Arr1.arrayList[i];
	}
	for (int i = Arr1.size; i < Arr2.size + Arr1.size; i++ ) {
		res.arrayList[i] = Arr2.arrayList[i-Arr1.size];
	}

	return res;
}

bool ArrayList::operator>= (const ArrayList &Arr) const {
	bool res = true;

	for (int i = 0; i < size; i++) {
		if (this->arrayList[i] < Arr.arrayList[i]) {
			res = false;
			break;
		}
	}

	return res;
}

bool ArrayList::operator> (const ArrayList &Arr) const {
	bool res = true;

	for (int i = 0; i < size; i++) {
		if (this->arrayList[i] <= Arr.arrayList[i]) {
			res = false;
			break;
		}
	}

	return res;
}

bool ArrayList::operator<= (const ArrayList &Arr) const {
	bool res = true;

	for (int i = 0; i < size; i++) {
		if (this->arrayList[i] > Arr.arrayList[i]) {
			res = false;
			break;
		}
	}

	return res;
}

bool ArrayList::operator< (const ArrayList &Arr) const {
	bool res = true;

	for (int i = 0; i < size; i++) {
		if (this->arrayList[i] >= Arr.arrayList[i]) {
			res = false;
			break;
		}
	}

	return res;
}

std::istream& operator>> (std::istream& in, const ArrayList& Arr) {
	for (int i = 0; i < Arr.size; i++) {
		in >> Arr.arrayList[i];
	}

	return in;
}

std::ostream& operator<< (std::ostream& os, const ArrayList& Arr) {
	for (int i = 0; i < Arr.size; i++) {
		os << Arr.arrayList[i] << " ";
	}

	return os << "\n";
}
