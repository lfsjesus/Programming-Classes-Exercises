bool anagrams(const char a[], const char b[], int& n) {
    int abc[26] = {0};
    n = 0;
    int i = 0; 
    while (a[i] != '\0') {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            int position = a[i] - 'A';
            abc[position] += 1;
        }
        if (a[i] >= 'a' && a[i] <= 'z') {
            int position = a[i] - 'a';
            abc[position] += 1;
        }
        i++;

    }

    i = 0;
    while (b[i] != '\0') {
        if (b[i] >= 'A' && b[i] <= 'Z') {
            int position = b[i] - 'A';
            abc[position] -= 1;
        }
        if (b[i] >= 'a' && b[i] <= 'z') {
            int position = b[i] - 'a';
            abc[position] -= 1;
        }
        i++;

    }

    int j = 0; 
    while (j < 26) {
        if (abc[j] != 0) {
            if (abc[j] < 0) {
                abc[j] = abc[j] * (-1);
            }
            n += abc[j];
        }
        j++;
    }

    if (n > 0) {
        return false;
    }
    return true;

}

int main() {
    
}