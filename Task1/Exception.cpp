#include <exception>

class DAIException : public std::exception {
    private:
        const char* message;
    public:
        DAIException(const char* theMessage) : message(theMessage) {}
        const char* what() const noexcept {return message;}
};
