#include <iostream>
using namespace std;

class Quiz {
private:
    int score = 0;
    char ans;

public:
    void startQuiz() {
        cout << "===== Quiz Application =====\n\n";

        // Question 1
        cout << "1. What is the capital of India?\n";
        cout << "a) Mumbai\nb) Delhi\nc) Kolkata\nd) Chennai\n";
        cout << "Enter your answer: ";
        cin >> ans;
        if (ans == 'b' || ans == 'B')
            score++;

        // Question 2
        cout << "\n2. C++ is a _____ language.\n";
        cout << "a) Programming\nb) Cooking\nc) Gaming\nd) Drawing\n";
        cout << "Enter your answer: ";
        cin >> ans;
        if (ans == 'a' || ans == 'A')
            score++;

        // Question 3
        cout << "\n3. 5 + 7 = ?\n";
        cout << "a) 10\nb) 11\nc) 12\nd) 13\n";
        cout << "Enter your answer: ";
        cin >> ans;
        if (ans == 'c' || ans == 'C')
            score++;
    }

    void result() {
        cout << "\n===== Quiz Result =====\n";
        cout << "Your Score: " << score << " / 3\n";

        if (score == 3)
            cout << "Excellent!";
        else if (score == 2)
            cout << "Good Job!";
        else
            cout << "Keep Practicing!";
    }
};

int main() {
    Quiz q;
    q.startQuiz();
    q.result();

    return 0;
}