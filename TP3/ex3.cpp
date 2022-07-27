#include <iostream>
using namespace std;

void print_array(const int a[], int n){
  cout << '[' << a[0];
  for (int i = 1; i < n; i++) {
    cout << ',' << a[i];
  }
  cout << "]\n";
}


void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) {

    int i = 0; // position of array a
    int j = 0; // position of array b
    int k = 0; // position of array c

    while (i < na && j < nb) {      // Merging until the smallest length is reached
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++; // incrementing the pointer of array A
            k++;
        }
        else {
            c[k] = b[j];
            j++; // incrementing the pointer of array B
            k++;                                                       /* Always incrementing k, to go to the next position of the final sorted array */
        }
    }

    while (i < na) {        // Add remaining elements of A when length of B is reached
        c[k] = a[i];
        i++;
        k++; 
    }

    while (j < nb) {        // Add remaining elements of B when length of A is reached
        c[k] = b[j];
        j++;
        k++;
    }

}

int main() {

    	
    const int NA = 6, NB = 4;
    int a[NA] = { 0, 3, 5, 6, 8, 9};
    int b[NB] = { 1, 2, 4, 7};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);

    /*
    const int NA = 6, NB = 4;
    int a[NA] = { 0, 3, 5, 6, 8, 9};
    int b[NB] = { 1, 2, 4, 7};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
    */

}
