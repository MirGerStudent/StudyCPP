#include <exception>

class RingBuffException : public std::exception {
    private:
        const char* message;
    public:
        RingBuffException(const char* theMessage) : message(theMessage) {}
        const char* what() const noexcept {return message;}
};