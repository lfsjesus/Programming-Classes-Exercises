#include <iostream>
#include "etree.cpp"
using namespace std;


int eval(const etree* t){

    if (t->left == nullptr && t->right == nullptr){

        return t->value;
    } 

    else {

        if (t->value == ADD){

            return eval(t->left) + eval(t->right);
        }


        else if (t->value == SUB){

            return eval(t->left) - eval(t->right);
        }
        
        else if (t->value == MUL){

            return eval(t->left) * eval(t->right);
        }

        else{

            return eval(t->left) / eval(t->right);
        }
    }

}
int main() {

}