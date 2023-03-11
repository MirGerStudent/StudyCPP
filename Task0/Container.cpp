#include "Container.h"

namespace MyBoxes {

	Container::Container(int length, int width, int height, double maxWeight) {
		this->length = length;
		this->width = width;
		this->height = height;
		this->maxWeight = maxWeight;
		this->container = {};
	}

	Container::~Container() {
		this->length = 0;
		this->width = 0;
		this->height = 0;
		this->maxWeight = 0;
		this->container = {};
	}

	void Container::addBox(Box box) {
		if (maxWeight > (containerWeight() + box.getWeight())) {
			container.push_back(box);
		} else {
			std::cout << "Нет места в контейнере!" << std::endl;
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
			res += container[i].getWeight();
		}

		return res;
	}

	void Container::removeBox(int index) {
		container.erase(container.begin() + index);
	}

	std::ostream& operator << (std::ostream &os, Container &container) { 
		os << "Container " << container.length << " " << container.width << " " << container.height << " " << container.maxWeight << "\n";
		for (long unsigned int i = 0; i < container.container.size(); i++) {
			os << "Box [" << i << "] " << container.container[i] << "\n";
		}
		return os << "\n";
	}

	std::istream& operator >> (std::istream &in, Container &container) {
		return in >> container.length >> container.width >> container.height >> container.maxWeight;
	}

	Box& Container::operator[](int index) {
		return container[index];
	}
}