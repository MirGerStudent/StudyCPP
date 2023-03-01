#include "Container.h"

Container::Container(int length, int width, int height, double maxWeight) {
	this->length = length;
	this->width = width;
	this->height = height;
	this->maxWeight = maxWeight;
}

Container::~Container() {
	this->length = 0;
	this->width = 0;
	this->height = 0;
	this->maxWeight = 0;
}

void Container::addBox(Box box) {
	if (containerWeight() < maxWeight) {
		container.push_back(box);
	}
}

Box Container::getBox(int index) {
	return container.at(index);
}

int Container::size() {
	return container.size();
}

int Container::containerValue() {
	int res = 0;

	for (size_t i = 0; i < container.size(); i++) {
		res += container.at(i).getValue();
	}

	return res;
}

double Container::containerWeight() {
	double res = 0;

	for (size_t i = 0; i < container.size(); i++) {
		res += container.at(i).getWeight();
	}

	return res;
}

void Container::removeBox(int index) {
	container.erase(container.begin() + index);
}

