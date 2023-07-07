#include <iostream>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

void get_date(date &d) {
    int x;
    cout << "Enter the day: ";
    cin >> x;
    d.day = x;
    cout << "Enter the month: ";
    cin >> x;
    d.month = x;
    cout << "Enter the year: ";
    cin >> x;
    d.year = x;
}

bool check_date(date &d) {
    if (d.month < 1 || d.month > 12) {
        cout << "Invalid month value. Please enter a value between 1 and 12." << endl;
        return false;
    }

    if (d.day < 1 || d.day > 31) {
        cout << "Invalid day value. Please enter a value between 1 and 31." << endl;
        return false;
    }

    if ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day > 30) {
        cout << "Invalid day value. This month can only have maximum 30 days." << endl;
        return false;
    }

    if (d.month == 2) {
        if (d.day > 29) {
            cout << "Invalid day value. February can only have maximum 29 days in a leap year." << endl;
            return false;
        } else if (d.day == 29 && (d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0))) {
            cout << "Invalid day value. This year is not a leap year." << endl;
            return false;
        }
    }

    return true;
}

void display_date(date &d) {
    cout << "Day: " << d.day << endl;
    cout << "Month: " << d.month << endl;
    cout << "Year: " << d.year << endl;
}

int main() {
    date d;
    bool valid_date = false;

    while (!valid_date) {
        get_date(d);
        valid_date = check_date(d);
    }

    display_date(d);

    return 0;
}
