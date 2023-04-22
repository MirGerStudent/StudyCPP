class RingBuffer {
    private:
        int size;
        int head;
        int tail;
        int *Array;
    public:
        RingBuffer();
        RingBuffer(int size);
        RingBuffer(const RingBuffer &cop);
        RingBuffer(RingBuffer &&cop);
        ~RingBuffer();

        int length();
        void clear();
        bool isEmpty();
        void push(int value);
        int front();
        int get_front();
};