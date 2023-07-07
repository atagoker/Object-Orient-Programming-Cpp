#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <limits>


using namespace std;

class HistoryQuiz {
private:
    vector<string> questions;
    vector<string> answers;

public:
    HistoryQuiz(const string &filename) {
        ifstream quiz_file(filename.c_str());
        if (!quiz_file.is_open()) {
            cerr << "Unable to open file: " << filename << endl;
            exit(1);
        }

        string line;
        while (getline(quiz_file, line)) {
            size_t start_quote = line.find_first_of('"');
            size_t end_quote = line.find_last_of('"');
            if (start_quote != string::npos && end_quote != string::npos && start_quote < end_quote) {
                string question = line.substr(start_quote + 1, end_quote - start_quote - 1);
                string answer = line.substr(end_quote + 1);
                questions.push_back(question);
                answers.push_back(answer);
            }
        }

        quiz_file.close();
    }

    void ask_questions() {
        int num_questions = questions.size();
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
};

int main() {
    string filename;
    cout << "Enter the filename of the quiz: ";
    cin.ignore();
    getline(cin, filename);

    HistoryQuiz quiz(filename);
    quiz.ask_questions();


    cout << "Press ENTER to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
