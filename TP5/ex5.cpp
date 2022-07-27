#include <iostream>
#include "node.cpp"

using namespace std;

node* reverse (const node* n) {


    // Ideia geral: criar um novo node, percorrer os nodes de n e colocá-los todos atrás do novo node. 
    // Atualizar o novo node para o node que é adicionado

    if (n==nullptr) {
        return nullptr;
    }

    node* novo = build(n->value); 
    n = n->next;

    while (n != nullptr) {
        node* add = build(n->value);
        novo->prev = add;
        add->next = novo;
        n = n-> next;
        novo = novo->prev;
    }
    delete n;
    return novo;
}

int main() {
    node* a = build(1, build(2, nullptr));
    node* b = reverse(a);
    print(b);
    destroy(a); destroy(b);
}