#include "IteratorRingBuff.h"

IteratorRingBuff::IteratorRingBuff(RingBuffer &cop) : _RingBuffer{cop}, begin{0} {}

void IteratorRingBuff::start() {
    begin = _RingBuffer.get_head() % (_RingBuffer.length()+1);
}

void IteratorRingBuff::next() {
    begin++ % (_RingBuffer.length()+1);
}

bool IteratorRingBuff::finish() {
    return begin % _RingBuffer.length() == _RingBuffer.get_tail() % _RingBuffer.length();
}

int IteratorRingBuff::getValue() {
    return _RingBuffer.Array[begin % (_RingBuffer.length())];
}