#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    std::string date;
public:
    Date(std::string date) : date(date) { }
    std::string getDate() { return date; }
};

#endif
