#ifndef TASK4_HASHEXCEPTION_H
#define TASK4_HASHEXCEPTION_H

#include <exception>

class HashException : public std::exception {
    private:
        const char* message;
    public:
        HashException(const char* theMessage) : message(theMessage) {}
        const char* what() const noexcept {return message;}
};

#endif //TASK4_HASHEXCEPTION_H