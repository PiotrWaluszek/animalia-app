#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include "json.hpp"

using json = nlohmann::json;

struct Question {
    std::string question;
    std::string answer;
};

std::vector<Question> loadQuestions(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Nie można otworzyć pliku z pytaniami.");
    }
    
    json j;
    file >> j;
    
    std::vector<Question> questions;
    for (const auto& item : j) {
        questions.push_back({item["question"], item["answer"]});
    }

    return questions;
}

void saveResult(const std::string& username, int score, int total) {
    std::ofstream file("results.txt", std::ios::app);
    if (file) {
        std::time_t now = std::time(nullptr);
        file << username << " " << score << "/" << total << " " << std::ctime(&now);
    } else {
        std::cerr << "Nie można zapisać wyników.\n";
    }
}

void showResults() {
    std::ifstream file("results.txt");
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
    } else {
        std::cerr << "Nie można otworzyć pliku z wynikami.\n";
    }
}

void startQuiz(const std::vector<Question>& questions) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<Question> quizQuestions = questions;
    std::shuffle(quizQuestions.begin(), quizQuestions.end(), g);
    quizQuestions.resize(10);

    std::cout << "Podaj swoje imię: ";
    std::string username;
    std::getline(std::cin, username);

    std::cout << "Witaj w quizie o zwierzętach, " << username << "!\n\n";

    int score = 0;

    for (const auto& q : quizQuestions) {
        std::cout << q.question << "\n";
        std::string answer;
        std::getline(std::cin, answer);

        if (answer == q.answer) {
            std::cout << "Poprawna odpowiedź!\n\n";
            score++;
        } else {
            std::cout << "Błędna odpowiedź. Poprawna odpowiedź to: " << q.answer << "\n\n";
        }
    }

    std::cout << "Twój wynik: " << score << "/" << quizQuestions.size() << "\n";
    saveResult(username, score, quizQuestions.size());
}

int main() {
    std::vector<Question> questions;
    try {
        questions = loadQuestions("questions.json");
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    while (true) {
        std::cout << "=== MENU ===\n";
        std::cout << "1. Rozpocznij nowy quiz\n";
        std::cout << "2. Wyświetl wyniki\n";
        std::cout << "3. Zakończ\n";
        std::cout << "Wybierz opcję: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        if (choice == 1) {
            startQuiz(questions);
        } else if (choice == 2) {
            showResults();
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Niepoprawna opcja, spróbuj ponownie.\n";
        }
    }

    return 0;
}
