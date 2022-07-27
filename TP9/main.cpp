#include <iostream>
#include "Color.h"
using namespace std;


int main() {
    Color c(Color::WHITE); 
    cout << (int) c.red() << ' ' 
     << (int) c.green() << ' '  
     << (int) c.blue() << ' '
     << boolalpha << c.equal_to(Color::WHITE) << ' '
     << c.equal_to(Color::BLACK) << '\n';
}