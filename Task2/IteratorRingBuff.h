#include "RingBuffer.h"

class IteratorRingBuff {
    private:
        RingBuffer &_RingBuffer;
        int begin;
    public:
        explicit IteratorRingBuff(RingBuffer &cop);
        void start();
        void next();
        bool finish();
        int getValue();
};