#include <iostream>
using namespace std;

struct complex {
    int real;
    int img;
};

//! Print array of complex numbers.
void print(const complex z[], int n) {
  cout << "[ ";
  for (int i = 0; i < n; i++) {
    if (z[i].real == 0 && z[i].img == 0) 
      cout << 0;
    else {
      if (z[i].real != 0)
        cout << z[i].real;
      if (z[i].img > 0) 
        cout  << '+' << z[i].img << 'i';
      else if (z[i].img < 0) 
        cout  << z[i].img << 'i';
    }
    cout << ' ';
  }
  cout << "]\n";
}

complex sum(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;
    return result;
}

complex mul(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.img * b.img;
    result.img = a.real * b.img + b.real * a.img;
    return result;
}

void mandel(complex c, int n, complex z[]) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            z[i] = {0, 0};
        }
        else {
            z[i] = sum(mul(z[i-1], z[i-1]), c);
        }

    }
}

int main() {
    complex c = { 0, 0 };
    const int n = 1;
    complex z[n];
    mandel(c, n, z);
    print(z, n);






































}