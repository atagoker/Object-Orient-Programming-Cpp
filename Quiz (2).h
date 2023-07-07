#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include <string>
#include "Question.h"

class Quiz {
private:
    std::vector<Question> questions;
public:
    Quiz(std::string filename);
    void start();
};

#endif
