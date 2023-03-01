#include <vector>
#include "Box.h"

class Container {
	private:
		std::vector<Box> container;
		int length;
        int width;
        int height;
		double maxWeight;

	public:
		Container(int length, int width, int height, double maxWeight);
		~Container();
		double containerWeight();
		int size();
		int containerValue();
		void addBox(Box box);
		Box getBox(int index);
		void removeBox(int index);
		friend std::istream& operator >> (std::istream &in, Container &container);
    	friend std::ostream& operator << (std::ostream &os, Container &container);
};