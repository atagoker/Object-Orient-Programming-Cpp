#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include "Date.h"

class Question {
private:
    std::string question;
    std::string correctAnswer;
    Date date;
public:
    Question(std::string question, std::string correctAnswer, Date date)
    : question(question), correctAnswer(correctAnswer), date(date) { }

    std::string getQuestion() { return question; }
    std::string getCorrectAnswer() { return correctAnswer; }
    Date getDate() { return date; }
};

#endif
