#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include "Book.h"
#include "Page.h"
 
using namespace std;

Book::Book() { }

//! Imports book contents from text file ‘filename’
bool Book::import(const string& filename) {
  ifstream f(filename);
  if (f.fail()) {
    return false;
  } else {
    string line;
    Page page;
    while (getline(f, line)) {
      if (line == "<PAGE>") {
        this->book_.push_back(page);
        page.clear();
      } else
        page.add_line(line);
    }
    return true;
  }
}

//! Builds ‘index’ for the ‘words’ received as parameter
//void Book::build_index(const set<string>& words) {
//}

//! Shows book
void Book::show_book() const {
  size_t page_num = 0;
  for (const Page& page : book_) {
    cout << "PAGE " << ++page_num << endl;
    page.show();
  }
  cout << endl;
}

//! Builds index

void Book::build_index(const::set<std::string> &words) {
  for (string word : words) {
    for (size_t i = 0; i < book_.size(); i++) { //Iterating through pages (considering the loop starts at 0 state)
      Page page = book_[i]; // Saving page number into a class constructor
      for (size_t j = 0; j < page.get_num_lines(); j++) { // Reads book's page line by line
        string line = page.get_line(j); //
        istringstream iss(line); 
        string word_b; 
        while(iss >> word_b) {
          if (word == word_b) {
            auto find = index_.find(word);
            if (find != index_.end()) {
              find->second.insert(i+1); // Insert page where the word was found into the set
            }
            else {  // Otherwise, create a new set corresponding to the next valid word
              set<size_t> n;
              n.insert(i+1);
              index_[word] = n;
            }
          }
        }
      }
    }
  }
}

//! Shows book index
void Book::show_index() const {
  cout << "/ ";
  for (const auto& i : index_) {
    cout << i.first << ": ";
    for (const auto& p : i.second)
      cout << p << " ";
    cout << "/ ";
  }
  cout << endl;
}
