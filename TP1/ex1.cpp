#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string final = "";
    for (int i=1; i <= n; i++ ) {
        if (i % 3 == 0 && i % 5 == 0) {
            continue;
        }
        else if (i % 3 == 0 && i % 5 != 0){
            final = final + "Fizz" + " ";
        }
        else if (i % 5 == 0 && i % 3 != 0){
            final = final + "Buzz" + " ";
        }
        else {
            final = final + to_string(i) + " ";
        }
            
    }
    cout << final;
}