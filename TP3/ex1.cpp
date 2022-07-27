
unsigned long hstr_to_integer(const char hstr[]) {
    int i = 0;
    unsigned long result = 0;

    while (hstr[i] != '\0') {
        if ((hstr[i]>= '0') && (hstr[i] <= '9')) {
            result = result *16 + (hstr[i] - '0');

        }

        else if ((hstr[i] >= 'a') && (hstr[i] <= 'f')) {
            result = result * 16 + (10 + hstr[i] - 'a');
        }

        else if ((hstr[i] >= 'A') && (hstr[i] <= 'F')) {
            result = result *16 + (10 + hstr[i] - 'A');
        }
        i++;
    }

    return result;
}

int main () {
    
}