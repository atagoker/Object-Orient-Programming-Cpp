#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <direct.h>

using namespace std;

typedef pair<int, int> Fraction;

Fraction read_fraction(istream &is) {
    int numerator, denominator;
    char ch;
    is >> numerator;
    if (is.get(ch) && ch == '/') {
        is >> denominator;
        return {numerator, denominator};
    } else {
        is.unget();
        return {numerator, 1};
    }
}

Fraction operator+(const Fraction &a, const Fraction &b) {
    return {a.first * b.second + b.first * a.second, a.second * b.second};
}

Fraction operator-(const Fraction &a, const Fraction &b) {
    return {a.first * b.second - b.first * a.second, a.second * b.second};
}

Fraction operator*(const Fraction &a, const Fraction &b) {
    return {a.first * b.first, a.second * b.second};
}

Fraction operator/(const Fraction &a, const Fraction &b) {
    if (b.first == 0)
        throw runtime_error("Division by zero!");
    return {a.first * b.second, a.second * b.first};
}

bool is_zero(const Fraction &a) {
    return a.first == 0;
}

bool is_solution(const vector<vector<Fraction> > &system, const vector<Fraction> &solution) {
    for (size_t i = 0; i < system.size(); ++i) {
        const vector<Fraction>& eq = system[i];
        Fraction left_side = eq[0] * solution[0] + eq[1] * solution[1];
        if (left_side.first * eq[2].second != left_side.second * eq[2].first) {
            return false;
        }
    }
    return true;
}



vector<Fraction> solve_system(const vector<vector<Fraction> > &system) {
    Fraction det = system[0][0] * system[1][1] - system[0][1] * system[1][0];

    if (is_zero(det)) {
        throw runtime_error("The system has no unique solution.");
    }

    vector<Fraction> solution(2);
    solution[0] = (system[0][2] * system[1][1] - system[0][1] * system[1][2]) / det;
    solution[1] = (system[0][0] * system[1][2] - system[0][2] * system[1][0]) / det;

    return solution;
}

int main() {
    char buffer[FILENAME_MAX];
    if (getcwd(buffer, FILENAME_MAX)) {
        cout << "Current working directory: " << buffer << endl;
    } else {
        perror("getcwd error");
    }

    string filename;
    cout << "Enter the filename with the system of linear equations: ";
    cin >> filename;

    ifstream file(filename.c_str());
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<vector<Fraction> > system(2, vector<Fraction>(3));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            system[i][j] = read_fraction(file);
        }
    }

    try {
        vector<Fraction> solution = solve_system(system);

        if (is_solution(system, solution)) {
            cout << "The unique solution is:" << endl;
            cout << "x1 = " << solution[0].first << "/" << solution[0].second << endl;
            cout << "x2 = " << solution[1].first << "/" << solution[1].second << endl;
        }
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    }

    return 0;
}

