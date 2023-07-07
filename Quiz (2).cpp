#include <fstream>
#include <iostream>
#include "Quiz.h"

Quiz::Quiz(std::string filename) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    std::string question, answer, date;
    while (std::getline(inputFile, question) && std::getline(inputFile, answer) && std::getline(inputFile, date)) {
        Date dateObj(date);
        Question newQuestion(question, answer, dateObj);
        questions.push_back(newQuestion);
    }
}

void Quiz::start() {
    for (auto &question : questions) {
        std::cout << question.getQuestion() << "\n";
        std::string userAnswer;
        std::cin >> userAnswer;
        if (userAnswer == question.getCorrectAnswer()) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Incorrect. The correct answer was " << question.getCorrectAnswer() << "\n";
        }
    }
}
