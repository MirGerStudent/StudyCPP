#include <iostream>

class Matrix{
    private:
        int lines;
        int columns;
    public:
        Matrix(int x, int y) {
            lines = x;
            columns = y;
        }
        Matrix(int x) {
            lines = x;
            columns = x;
        }
        Matrix() {
            lines = 10;
            columns = 10;
        }
};

int main() {
    

    return 0;
}