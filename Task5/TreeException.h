#ifndef TASK4_HASHEXCEPTION_H
#define TASK4_HASHEXCEPTION_H

#include <exception>

class TreeException : public std::exception {
    private:
        const char* message;
    public:
        TreeException(const char* theMessage) : message(theMessage) {}
        const char* what() const noexcept {return message;}
};

#endif //TASK4_HASHEXCEPTION_H