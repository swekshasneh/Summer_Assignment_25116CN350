#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secret, guess, attempts = 0;

    srand(time(0));
    secret = rand() % 100 + 1;   // Random number between 1 and 100

    cout << "===== Number Guessing Game =====\n";
    cout << "Guess a number between 1 and 100\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secret)
            cout << "Too High! Try Again.\n";
        else if (guess < secret)
            cout << "Too Low! Try Again.\n";
        else
            cout << "Congratulations! You guessed the number in "
                 << attempts << " attempts.\n";

    } while (guess != secret);

    return 0;
}