#include <map>
#include <sstream>
#include <list>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

string cat_keys(list<map<string, unsigned>> lst) {
    int cur_map = 0;
    int count = -1;
    unsigned int min = UINT_MAX;
    for (map<string, unsigned> m : lst) {
        count++;
        for (auto el : m) {
            if (el.second < min) {
                min = el.second;
                cur_map = count;
            }
        }
    }

    list<map<string, unsigned>>::iterator itr = lst.begin();
    advance(itr, cur_map);
    ostringstream out;
    for (auto elem : *itr) {
        out << elem.first;
    }
    return out.str();

}