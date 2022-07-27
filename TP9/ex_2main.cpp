#include <iostream>
#include <vector>
#include "Date.h"
#include "Person.h"

using namespace std;


void born_before(const vector<Person>& persons, const Date& date) {
    date.show();
    cout << ": ";
    for (Person person: persons) {
        if (person.get_birth_date().is_before(date)) {
            person.show();
            cout << " ";
        }
    }
}

