#include <iostream>

struct box {
    int length;
    int width;
    int height;
    double weight;
    int value;

    box(int Length, int Width, int Height, double Weight, int Value);
    box();
    void print();
    // bool operator == (box Box1, box Box2);

};

bool operator == (box Box1, box Box2);
std::ostream& operator << (std::ostream &os, const box &Box);
std::istream& operator >> (std::istream &in, box &Box);

struct VolumeBox {
    box Box;
    int volume;

    VolumeBox(box BOX, int Volume);
    VolumeBox();
};


int SumWeight(box Arr[], int size);
bool IdealBoxs(box Arr[], int size, int length, int width, int height);
int volume(box Box);
int MaxWeight(box Arr[], int size, int maxV);
bool VolumeOneInOne(box Arr[], int size);