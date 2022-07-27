#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;
 
struct wcresult {
  unsigned int lines;
  unsigned int words; 
  unsigned int bytes; 
};

wcresult wc(const string& filename) {
    ifstream in(filename);
    string line;

    wcresult conta {0};


    while(getline(in, line)) {
        conta.lines ++;
        conta.bytes += line.length() + 1;
        istringstream  iss(line);
        string word;
        while(iss >> line) conta.words++;
    }
    return conta;
}

int main() {
    wcresult r = wc("p2_test2.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
}