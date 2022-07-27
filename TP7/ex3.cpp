#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//! Show file contents with line number information and 
//! the '|' character indicating the begining and end of lines.
void print(const std::string& file) {
  ifstream in(file);
  size_t line_nr = 1;
  for (string line; getline(in, line);) {
     cout << line_nr << "|" << line << "|\n";
     line_nr++;
  }
}

void normalise(const string& input_fname, const string& output_fname) {
    ifstream in(input_fname);
    ofstream file(output_fname);
    string line;
    string new_line;
    while (getline(in,line)) {
      size_t start = line.find_first_not_of(" ");
      size_t end = line.find_last_not_of(" ");
      if (start == string::npos) continue;
      else {
        new_line = line.substr(start, end-start + 1);
        for (char& ch: new_line) {
          ch = toupper(ch);
        }
        file << new_line << "\n";

      }
    }
}

int main() {
  normalise("p3_test1.txt", "p3_test1_out.txt"); 
  print("p3_test1_out.txt");
}