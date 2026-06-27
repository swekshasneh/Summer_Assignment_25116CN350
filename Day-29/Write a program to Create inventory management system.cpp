#include <iostream>
using namespace std;

class Inventory {
private:
    int productID;
    string productName;
    int quantity;
    float price;

public:
    void getData() {
        cout << "Enter Product ID: ";
        cin >> productID;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;
    }

    void displayData() {
        cout << "\n----- Inventory Details -----\n";
        cout << "Product ID   : " << productID << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Quantity     : " << quantity << endl;
        cout << "Price        : ₹" << price << endl;
        cout << "Total Value  : ₹" << quantity * price << endl;
    }
};

int main() {
    Inventory item;

    item.getData();
    item.displayData();

    return 0;
}