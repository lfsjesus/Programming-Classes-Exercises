#include <iostream>

using namespace std;

void int_to_string(int n, char str[], int& pos) {  // This function is supposed to put the number of characters in the c-string array, considering single digits ('11' -> {1,1})
    int d;   // digit                                          
    char aux[50]; // array to save the number
    int aux_i = 0; // looping variable to store in the previous array
    
    while (n > 0) {
        d = n % 10;
        n /= 10;
        aux[aux_i] = d + '0'; // transforming int into a char
        aux_i++;


    }

    // The number is reversed, so we need to put it back in the correct order
    for (int i = aux_i - 1; i >= 0; i--) {
        str[pos] = aux[i];
        pos++;
    }
}

void rleEncode(const char str[], char rle[]) {
    int i = 0; // Looping variable
    int counter = 1; // Counts number of letters
    int pos = 0; // Last position, null char

    char current = str[i]; // char we are counting now

    while (str[i] != '\0') {
        if (str[i + 1] == current) {
            counter++;
        }
        else { // when we change to a different char...
            int_to_string(counter, rle, pos); // we get the next position to be written, and the number of chars is already in the array
            rle[pos] = current; // position after number of same char is the char we've been counting
            counter = 1; // reset the counter to count a different char
            current = str[i+1]; // the char we are counting now is updated
            pos++; // update the new position we'll be writing 
        }

        i++;
    }
    rle[pos] = '\0';

}



int main() {

    char rle[2 + 1] = { -1, -1, -1 }; 
    rleEncode("a", rle);
    cout << rle << endl;

}