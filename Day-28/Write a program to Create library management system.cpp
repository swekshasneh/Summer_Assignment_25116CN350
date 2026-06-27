#include <iostream>
using namespace std;

class Library {
private:
    int bookID;
    string title;
    string author;
    bool issued;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
    }

    void issueBook() {
        if (!issued) {
            issued = true;
            cout << "Book Issued Successfully.\n";
        } else {
            cout << "Book is already issued.\n";
        }
    }

    void returnBook() {
        if (issued) {
            issued = false;
            cout << "Book Returned Successfully.\n";
        } else {
            cout << "Book is not issued.\n";
        }
    }

    void displayBook() {
        cout << "\n----- Library Record -----\n";
        cout << "Book ID    : " << bookID << endl;
        cout << "Title      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "Status     : " << (issued ? "Issued" : "Available") << endl;
    }
};

int main() {
    Library book;
    int choice;

    book.addBook();

    do {
        cout << "\n----- Library Management System -----";
        cout << "\n1. Issue Book";
        cout << "\n2. Return Book";
        cout << "\n3. Display Book Details";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                book.issueBook();
                break;
            case 2:
                book.returnBook();
                break;
            case 3:
                book.displayBook();
                break;
            case 4:
                cout << "Thank You!";
                break;
            default:
                cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}