#ifndef TURKISH_HISTORY_QUIZ_H
#define TURKISH_HISTORY_QUIZ_H

#include <iostream>
#include <string>

using namespace std;

class TurkishHistoryQuiz {
private:
    int num_questions;
    string *questions;
    string *answers;

public:
    TurkishHistoryQuiz();
    ~TurkishHistoryQuiz();
    void ask_questions();
};

#endif // TURKISH_HISTORY_QUIZ_H
