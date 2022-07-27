#include <iostream>
#include "Operation.h"
using namespace std;

class Sum : public Operation {
    public:
        Sum(int op1, int op2) : Operation(op1, op2) {};
        int operation() const;

};

int Sum::operation() const {
    return get_op1() + get_op2();
}


class Power : public Operation {
    public:
        Power(int op1, int op2) : Operation(op1, op2) {};
        int operation() const;
};

int Power::operation() const {
    int total = get_op1();
    if (get_op2() == 0) {
        return 1;
    }
    for (int i = 1; i < get_op2(); i++) {
        total *= get_op1();
    }
    return total;
}

