#include <iostream>
#include "dlnode.cpp"
using namespace std;
dlnode* insert(dlnode* dln, int k, int v){

 //caso seja vazio 
    if (dln == nullptr){
        dlnode* aux = build(v, nullptr);
        return aux;
    }

    if (k == 0){
            dlnode* novo = build(v,dln);
            return novo;
    }

    int count = 0;
    for(dlnode* curr = dln; curr != nullptr; curr = curr->next){


        if(count == k-1 && curr->next != nullptr){ //chegamos e nao tamos na ultima
            dlnode* temp = curr->next;
            dlnode* novo = build(v, temp);
            temp->prev = novo;
            curr->next = novo;
            novo->prev = curr;
            return dln;
        }

        else if (count == k-1 && curr->next == nullptr){

            dlnode* novo = build(v, nullptr);
            curr->next = novo;
            novo->prev = curr;
            return dln;

        }
        

        count++;
    }

    return dln;
}

int main() {
    	
    dlnode* dln = build(1);
    print(dln);
    dln = insert(dln, 0, 0);
    print(dln); destroy(dln);
}