template <typename T> struct node {
    int *next;
    // int *prev;
    T Data;

    node(const T& value) : Data(value) {}
};