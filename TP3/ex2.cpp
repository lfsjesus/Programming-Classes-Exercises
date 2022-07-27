#include <iostream>
using namespace std;


struct fraction {
    int num;
    int den;
};

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

fraction sum(const fraction fa[], int n) {
    
    fraction result {0,1};
    for (int i = 0; i < n; i++)   {
        result.num = result.num * fa[i].den + fa[i].num * result.den;
        result.den *= fa[i].den;

    }
    
    // reduction
    int g = gcd(result.num, result.den);
    result.num /= g;
    result.den /= g;
    
    if (result.den < 0) {
        result.den *= (-1);
        result.num *= (-1);
    }

    return result;
}
 int main () {
     
 }