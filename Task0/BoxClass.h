#include <iostream>

namespace MyBoxes {
class Box {
        private:
            int length;
            int width;
            int height;
            double weight;
            int value;
        public:
            Box(int Length, int Width, int Height, double Weight, int Value);
            Box();
            void print();
            int getLength();
            int getWidth();
            int getHeight();
            double getWeight();
            int getValue();
            void setLength(int length);
            void setWidth(int width);
            void setHeight(int height);
            void setWeight(double weight);
            void setValue(int value);
        friend bool operator == (Box Box1, Box Box2); 
        friend std::istream& operator >> (std::istream &in, Box &box);
        friend std::ostream& operator << (std::ostream &os, Box &box);
    };


    struct VolumeBox {
        Box box;
        int volume;

        VolumeBox(Box BOX, int Volume);
        VolumeBox();
    };


    int SumWeight(Box Arr[], int size);
    bool IdealBoxs(Box Arr[], int size, int length, int width, int height);
    int volume(Box box);
    int MaxWeight(Box Arr[], int size, int maxV);
    bool VolumeOneInOne(Box Arr[], int size);

}