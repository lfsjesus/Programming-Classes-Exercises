#include <iostream>
#include "svnode.cpp"
using namespace std;


svnode* sum(const svnode* a, const svnode* b) {
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }

    else if (a == nullptr) {
        svnode* temp = build(b->position, b->value, sum(b->next, nullptr));
        return temp;

    }

    else if (b == nullptr) {
        svnode* temp = build(a->position, a->value, sum(a-> next, nullptr));
        return temp;
    }

    else if (a->position == b->position) {
        if (a->value + b-> value == 0) {
            return sum(a->next, b->next);
        }
        else {
            return build(a->position, a->value + b->value, sum(a->next, b->next));
        }
    }

    else if (a->position < b->position) {
        svnode* temp = build(a->position, a->value, sum(b, a->next));
        return temp;
    }

    else {
        svnode* temp = build(b->position, b->value, sum(a, b->next));
        return temp;
    }


}

int main() {

}