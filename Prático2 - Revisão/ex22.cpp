#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
 
using namespace std;

//! print map in one line
void show_map(const map<string, size_t>& count) {
  cout << "[ ";
  for (const auto& e : count)   {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

void count_words(const string& str, map<string, size_t>& count) {
    istringstream in(str);
    string word;

    while (in >> word) {
        for (char& c : word) {
            c = tolower(c);
        }
        count[word] += 1;
    }

}