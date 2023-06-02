#ifndef TASK3_RBLEXEPTION_CPP
#define TASK3_RBLEXEPTION_CPP

#include <exception>

class RingBuffException : public std::exception {
    private:
        const char* message;
    public:
        RingBuffException(const char* theMessage) : message(theMessage) {}
        const char* what() const noexcept {return message;}
};

#endif //TASK3_RBLEXEPTION_CPP