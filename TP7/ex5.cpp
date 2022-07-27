#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//! Show file name and the contents.
void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream in(input_fname);
    string line;
    string text;
    double number;
    ofstream file(output_fname);
    vector<double> v; 
    int i = 0;

    while(getline(in, line)) {
        istringstream iss(line);
        iss >> text;
        if(text[0] == '#') continue;
        while(iss >> number){
            v.push_back(number); 
            i++;
        }
        
        sort(v.begin(), v.end());

        if (i % 2 == 0) {
            file << text << ' ';
            file << fixed << setprecision(1) << 0.5 * (v[i/2-1] + v[i/2]) << '\n';
        }

        else {
            file << text << ' ';
            file << fixed << setprecision(1) << v[i/2] << '\n';
        }

        i = 0;
        v.clear();
        
    }

}

/*
void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream in(input_fname);
    string line;
    string text;
    double number;
    ofstream file(output_fname);
    vector<double> v; 
    int i = 0;

    while(getline(in, line)) {
        istringstream iss(line);
        iss >> text;
        if(text[0] == '#') continue;
        while(!iss.eof()){
            if (iss >> number) {
                v.push_back(number); 
                i++;
            }
            else {
                in.clear();
                in.ignore(1);
            } 
        }
        
        sort(v.begin(), v.end());

        if (i % 2 == 0) {
            file << text << ' ';
            file << fixed << setprecision(1) << 0.5 * (v[i/2-1] + v[i/2]) << '\n';
        }

        else {
            file << text << ' ';
            file << fixed << setprecision(1) << v[i/2] << '\n';
        }

        i = 0;
        v.clear();
        
    }

}
*/

int main() {
calc_medians("p5_test4.txt", "p5_test4_out.txt");
show_file("p5_test4_out.txt");
}
