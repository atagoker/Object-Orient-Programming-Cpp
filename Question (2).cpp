#include "Question.h"

Question::Question(std::string qt, std::string ca, Date d)
: questionText(qt), correctAnswer(ca), date(d) {}

std::string Question::getQuestion() {
    return questionText;
}

std::string Question::getCorrectAnswer() {
    return correctAnswer;
}

Date Question::getDate() {
    return date;
}
