template <typename T>

class AbstractListIterator {
    public:
        virtual void start();
        virtual T getValue();
        virtual void next();
        virtual bool finish();
};