#include <iostream>
#include <map>

using namespace std;

unsigned roman_to_arab(const string& roman) {

    map<char, unsigned> map_roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int len = roman.length();
    unsigned int total = 0; 
    for (int i = 0; i < len; i++) {
        if (map_roman[roman[i]] < map_roman[roman[i+1]]) {
            total += map_roman[roman[i+1]] - map_roman[roman[i]];
            i++;
        }
        else {
            total += map_roman[roman[i]];
        }
    }

    return total;
}

int main(){

}