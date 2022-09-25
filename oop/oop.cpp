#include <iostream>

using std::cout;
using std::endl;

class objCounter {
    int objCounterCurrent_;
public:
    explicit objCounter(int objCounterCurrent = 0) : objCounterCurrent_{ objCounterCurrent } {}
    objCounter& const operator++() {
        objCounterCurrent_++;
        return *this;
    }
    objCounter& const operator++(int) {
        objCounterCurrent_++;
        return *this;
    }
    int show() { return objCounterCurrent_; }
};
class obj : public objCounter {
    int data_;
    objCounter& const objCounterCurrent_;
public:
    obj(int data, objCounter& const objCounterCurrent) : data_{ data }, objCounterCurrent_{ objCounterCurrent++ } { }
    void show() { 
        cout << "data = " << data_ << endl;
        cout << "objCounterCurrent = " << objCounterCurrent_.show() << endl;
    }
};
int main()
{
    objCounter objCounter1(0);
    obj obj1(0, objCounter1);
    obj obj2(0, objCounter1);
    obj1.show();
    obj2.show();
    cout << objCounter1.show() << endl;
}