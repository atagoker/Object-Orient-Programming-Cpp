#include <iostream>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

void get_date(date &d) {
    cout << "Enter the day: ";
    cin >> d.day;
    cout << "Enter the month: ";
    cin >> d.month;
    cout << "Enter the year: ";
    cin >> d.year;
}

void display_date(date &d) {
    cout << "Day: " << d.day << endl;
    cout << "Month: " << d.month << endl;
    cout << "Year: " << d.year << endl;
}

int main() {
    date d;
    get_date(d);
    display_date(d);
    return 0;
}
