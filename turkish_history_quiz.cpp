#include "turkish_history_quiz.h"

TurkishHistoryQuiz::TurkishHistoryQuiz() {
    num_questions = 5;
    questions = new string[num_questions];
    questions[0] = "In what year was the Turkish Republic established?";
    questions[1] = "What was the date of the Battle of Gallipoli?";
    questions[2] = "When did Turkey join NATO?";
    questions[3] = "What was the date of the failed coup attempt in Turkey?";
    questions[4] = "When did Turkey launch its military operation in Afrin, Syria?";
    answers = new string[num_questions];
    answers[0] = "1923";
    answers[1] = "18.03.1915";
    answers[2] = "1952";
    answers[3] = "15.07.2016";
    answers[4] = "20.01.2018";
}

TurkishHistoryQuiz::~TurkishHistoryQuiz() {
    delete[] questions;
    delete[] answers;
}

void TurkishHistoryQuiz::ask_questions() {
    int num_correct = 0;
    for (int i = 0; i < num_questions; i++) {
        cout << questions[i] << endl;
        string user_answer;
        cin >> user_answer;
        if (user_answer == answers[i]) {
            cout << "V" << endl;
            num_correct++;
        } else {
            cout << "X" << endl;
        }
    }
    cout << "You answered " << num_correct << " out of " << num_questions << " questions correctly." << endl;
}
