#include "BoxStruct.h"
#include <iostream>

box::box(int Length, int Width, int Height, double Weight, int Value)
{
    this->length = Length;
    this->width = Width;
    this->height = Height;
    this->weight = Weight;
    this->value = Value;
}

box::box()
{
    this->length = 0;
    this->width = 0;
    this->height = 0;
    this->weight = 0;
    this->value = 0;
}

void box::print() {
    std::cout << length << " " << width << " " << height << " " << weight << " " << value << std::endl;
}

VolumeBox::VolumeBox(box BOX, int Volume)
{
    this->Box = BOX;
    this->volume = Volume;
}

VolumeBox::VolumeBox()
{
    this->Box = box();
    this->volume = 0;
}

int SumWeight(box Arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += Arr[i].value;
    }

    return sum;
}

bool IdealBoxs(box Arr[], int size, int length, int width, int height)
{
    int sumLength = 0;
    int sumWidth = 0;
    int sumHeight = 0;

    for (int i = 0; i < size; i++) {
        sumLength += Arr[i].length;
        sumWidth += Arr[i].width;
        sumHeight += Arr[i].height;
    }

    return ((sumLength <= length) & (sumWidth <= width) & (sumHeight <= height));
}

int volumeBox(box Box)
{
    return Box.length * Box.width * Box.height;
}

int MaxWeight(box Arr[], int size, int maxV)
{
    int MaxWeightRes = -1;

    for (int i = 0; i < size; i++) {
        if (volumeBox(Arr[i]) <= maxV) {
            if (Arr[i].weight > MaxWeightRes) {
                MaxWeightRes = Arr[i].weight;
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
        Arr[i].Box.print();
    }
}

bool VolumeOneInOne(box Arr[], int size)
{
    VolumeBox VolumeArr[size];
    bool res = true;

    for (int i = 0; i < size; i++) {
        VolumeArr[i].Box = Arr[i];
        VolumeArr[i].volume = volumeBox(Arr[i]);
    }

    BubbleSort(VolumeArr, size);

    for (int i = 1; i < size; i++) {
        if ((VolumeArr[i-1].Box.height >= VolumeArr[i].Box.height) &
            (VolumeArr[i-1].Box.length >= VolumeArr[i].Box.length) &
            (VolumeArr[i-1].Box.width >= VolumeArr[i].Box.width)) { 
            res = false;
            break;
        }
    }

    return res;
}

bool operator == (box Box1, box Box2) {
    return ((Box1.height == Box2.height) & (Box1.length == Box2.length) & (Box1.value == Box2.value) & (Box1.weight == Box2.weight) & (Box1.width == Box2.width));
}

std::ostream& operator << (std::ostream &os, const box &Box){ 
    return os << Box.length << " " << Box.width << " " << Box.height << " " << Box.weight << " " << Box.value;
}

std::istream& operator >> (std::istream &in, box &Box) {
    return in >> Box.length >> Box.width >> Box.height >> Box.weight >> Box.value;
}