#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
//! Print vector of strings.
void print(const vector<string>& v) {
  cout << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    cout << '\"' << v[i] << "\" ";
  }
  cout << "]\n";
}


void split(const string& s, vector<string>& v) {
    int pos = 0;
    int count = 0;
    while(true) {
        size_t space = s.find(' ', pos);
        if (space == string::npos) {
            count = s.length();
            string sub = s.substr(pos, count);
            if (sub != "") v.push_back(sub);
            break;
        }

        count = space - pos;
        string sub = s.substr(pos, count);
        if (sub != "") v.push_back(sub);
        pos = space + 1;
    }
}
