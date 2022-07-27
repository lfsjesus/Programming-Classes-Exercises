#include <iostream>
using namespace std;

//! Print array.
void print(int a[], int size) {
  cout << "[ ";
  for (int i = 0; i < size; i++)
    cout << a[i] << " ";
  cout << "]";
  cout << endl;
}

void remove_duplicates(int a[], int& size) {
    int j = 1;
    int count = 0;
    int prev = a[0];

    for (int i = 0; i < size; i++) {
        if (a[i] == prev) {
            continue;
        }

        else {
            a[j] = a[i];
            j += 1;
            count += 1;
            prev = a[i];
        }
    }

    size = count + 1;
}

int main() {
    
}