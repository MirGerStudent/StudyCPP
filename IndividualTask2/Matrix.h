class Matrix{
    private:
        int lines;
        int columns;
        double** matrixarr = nullptr;

    public:
        Matrix(int x, int y);
        Matrix(int n);
        ~Matrix();
        void setvalue(int x, int y, double value);
        void getvalue(int x, int y, double &value) const;
        int getlines();
        int getcolumns();

        void information();
};

int Matrix::getcolumns() {
    return columns;
}

int Matrix::getlines() {
    return lines;
}

void Matrix::setvalue(int x, int y, double value) {
    matrixarr[x][y] = value;
}

void Matrix::getvalue(int x, int y, double &value) const {
    value = matrixarr[x][y];
}

Matrix::~Matrix() {
    for (int i = 0; i < lines; i++) {
       	delete[] matrixarr[i];
    }
    delete[] matrixarr;
    lines = 0;
    columns = 0;
}

Matrix::Matrix(int x, int y) {
    lines = x;
    columns = y;
    matrixarr = new double*[lines];
	for (int i = 0; i < lines; i++) {
       	matrixarr[i] = new double[columns];
    }
}

Matrix::Matrix(int n) {
    lines = columns = n;
    matrixarr = new double*[lines];
	for (int i = 0; i < lines; i++) {
       	matrixarr[i] = new double[columns];
    }
}