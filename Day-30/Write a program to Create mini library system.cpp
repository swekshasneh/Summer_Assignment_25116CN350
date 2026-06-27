#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool available;
};

vector<Book> library;
int nextId = 1;

void addBook() {
    Book b;
    b.id = nextId++;
    cout << "Enter title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, b.title);
    cout << "Enter author: ";
    getline(cin, b.author);
    b.available = true;
    library.push_back(b);
    cout << "Book added with ID " << b.id << "\n";
}

void listBooks() {
    if (library.empty()) { cout << "No books in library.\n"; return; }
    cout << left << setw(6) << "ID" << setw(30) << "Title" << setw(20) << "Author" << "Status\n";
    cout << string(70, '-') << "\n";
    for (auto &b : library) {
        cout << setw(6) << b.id << setw(30) << b.title.substr(0,29) << setw(20) << b.author.substr(0,19)
             << (b.available ? "Available" : "Borrowed") << '\n';
    }
}

Book* findBookById(int id) {
    for (auto &b : library) if (b.id == id) return &b;
    return nullptr;
}

void searchBooks() {
    cout << "Search by (1) ID or (2) Title keyword: ";
    int opt; if (!(cin >> opt)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }
    if (opt == 1) {
        cout << "Enter ID: "; int id; cin >> id;
        Book* b = findBookById(id);
        if (!b) cout << "Not found.\n"; else cout << "ID:"<<b->id<<" Title:"<<b->title<<" Author:"<<b->author<<" Status:"<<(b->available?"Available":"Borrowed")<<"\n";
    } else if (opt == 2) {
        cout << "Enter keyword: "; string kw; cin >> ws; getline(cin, kw);
        bool found=false;
        for (auto &b : library) if (b.title.find(kw)!=string::npos) {
            cout << b.id<<" - "<<b.title<<" by "<<b.author<<" ("<<(b.available?"Available":"Borrowed")<<")\n"; found=true; }
        if(!found) cout<<"No matches.\n";
    }
}

void borrowBook() {
    cout << "Enter book ID to borrow: "; int id; if(!(cin>>id)) { cin.clear(); cin.ignore(); return; }
    Book* b = findBookById(id);
    if (!b) cout << "Book not found.\n";
    else if (!b->available) cout << "Book already borrowed.\n";
    else { b->available = false; cout << "You borrowed '"<<b->title<<"'.\n"; }
}

void returnBook() {
    cout << "Enter book ID to return: "; int id; if(!(cin>>id)) { cin.clear(); cin.ignore(); return; }
    Book* b = findBookById(id);
    if (!b) cout << "Book not found.\n";
    else if (b->available) cout << "Book was not borrowed.\n";
    else { b->available = true; cout << "You returned '"<<b->title<<"'.\n"; }
}

void showMenu() {
    cout << "\nMini Library System\n";
    cout << "1. Add book\n2. List books\n3. Search books\n4. Borrow book\n5. Return book\n6. Exit\n";
    cout << "Choose option: ";
}

int main(){
    // sample data
    library.push_back({nextId++, "The C++ Programming Language", "Bjarne Stroustrup", true});
    library.push_back({nextId++, "Clean Code", "Robert C. Martin", true});

    while (true) {
        showMenu();
        int choice; if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
        switch (choice) {
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: searchBooks(); break;
            case 4: borrowBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Goodbye.\n"; return 0;
            default: cout << "Invalid option.\n";
        }
    }
    return 0;
}
