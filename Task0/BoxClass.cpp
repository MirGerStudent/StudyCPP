#include "BoxClass.h"
#include <iostream>

namespace MyBoxes {

    Box::Box(int Length, int Width, int Height, double Weight, int Value)
    {
        this->length = Length;
        this->width = Width;
        this->height = Height;
        this->weight = Weight;
        this->value = Value;
    }

    Box::Box()
    {
        this->length = 0;
        this->width = 0;
        this->height = 0;
        this->weight = 0;
        this->value = 0;
    }

    void Box::print() {
        std::cout << length << " " << width << " " << height << " " << weight << " " << value << std::endl;
    }

    int Box::getLength() {
        return this->length;
    }

    int Box::getWidth() {
        return this->width;            
    }

    int Box::getHeight() {
        return this->height;            
    }

    double Box::getWeight() {
        return this->weight;            
    }

    int Box::getValue() {
        return this->value;        
    }

    void Box::setLength(int length) {
        this->length = length;
    }

    void Box::setWidth(int width) {
        this->width = width;
    }

    void Box::setHeight(int height) {
        this->height = height;
    }

    void Box::setWeight(double weight) {
        this->weight = weight;
    }

    void Box::setValue(int value) {
        this->value = value;
    }

    VolumeBox::VolumeBox(Box BOX, int Volume)
    {
        this->box = BOX;
        this->volume = Volume;
    }

    VolumeBox::VolumeBox()
    {
        this->box = Box();
        this->volume = 0;
    }

    int SumWeight(Box Arr[], int size)
    {
        int sum = 0;

        for (int i = 0; i < size; i++) {
            sum += Arr[i].getValue();
        }

        return sum;
    }

    bool IdealBoxs(Box Arr[], int size, int length, int width, int height)
    {
        int sumLength = 0;
        int sumWidth = 0;
        int sumHeight = 0;

        for (int i = 0; i < size; i++) {
            sumLength += Arr[i].getLength();
            sumWidth += Arr[i].getWidth();
            sumHeight += Arr[i].getHeight();
        }

        return ((sumLength <= length) & (sumWidth <= width) & (sumHeight <= height));
    }

    int volumeBox(Box box)
    {
        return box.getLength() * box.getWidth() * box.getHeight();
    }

    int MaxWeight(Box Arr[], int size, int maxV)
    {
        int MaxWeightRes = -1;

        for (int i = 0; i < size; i++) {
            if (volumeBox(Arr[i]) <= maxV) {
                if (Arr[i].getWeight() > MaxWeightRes) {
                    MaxWeightRes = Arr[i].getWeight();
                }
            }
        }

        return MaxWeightRes;
    }

    void BubbleSort(VolumeBox* Arr, int n)
    {
        VolumeBox tmp;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (Arr[j - 1].volume > Arr[j].volume) {
                    tmp = Arr[j - 1];
                    Arr[j - 1] = Arr[j];
                    Arr[j] = tmp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            Arr[i].box.print();
        }
    }

    bool VolumeOneInOne(Box Arr[], int size)
    {
        VolumeBox VolumeArr[size];
        bool res = true;

        for (int i = 0; i < size; i++) {
            VolumeArr[i].box = Arr[i];
            VolumeArr[i].volume = volumeBox(Arr[i]);
        }

        BubbleSort(VolumeArr, size);

        for (int i = 1; i < size; i++) {
            if ((VolumeArr[i-1].box.getHeight() >= VolumeArr[i].box.getHeight()) &
                (VolumeArr[i-1].box.getLength() >= VolumeArr[i].box.getLength()) &
                (VolumeArr[i-1].box.getWidth() >= VolumeArr[i].box.getWidth())) { 
                res = false;
                break;
            }
        }

        return res;
    }

    bool operator == (Box Box1, Box Box2) {
        return ((Box1.getHeight() == Box2.getHeight()) & (Box1.getLength() == Box2.getLength()) & (Box1.getValue() == Box2.getValue()) & (Box1.getWeight() == Box2.getWeight()) & (Box1.getWidth() == Box2.getWidth()));
    }

    std::ostream& operator << (std::ostream &os, Box &box){ 
        return os << box.getLength() << " " << box.getWidth() << " " << box.getHeight() << " " << box.getWeight() << " " << box.getValue();
    }

    std::istream& operator >> (std::istream &in, Box &box) {
        return in >> box.length >> box.width >> box.height >> box.weight >> box.value;
    }
}