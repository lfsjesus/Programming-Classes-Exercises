#include <iostream>
#include "node.cpp"
using namespace std;

node* remove(int x, node* n) {

    node* curr = n;
    node* prev = n;


    if (n == nullptr) { // Caso a lista seja vazia
        return nullptr;
    }

    else if (n->next == nullptr) { // Caso só tenha 1 elemento
        if (n->value == x) { // Caso o 1º seja o valor que procuramos
            delete n;
            return nullptr;
        }

        else {
            return n;
        }
    }

    else { // Listas com mais de 1 elemento
        while(curr != nullptr) {
            if (curr->value == x) {
                prev->next = curr->next;
                delete curr;
                return n;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return n;
    }



}


int main() {
    node* n = build(1, build(2, nullptr));
    n = remove(0, n);
    print(n);
    destroy(n);
}