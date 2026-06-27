#include <iostream>
#include <string>
#include <limits>

const int MAX_RECORDS = 100;

struct Item {
    std::string name;
    int id;
    int quantity;
    double price;
    bool used;
};

void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
    std::cout << "Mini Inventory Project\n";
    std::cout << "1. Add item\n";
    std::cout << "2. View items\n";
    std::cout << "3. Search item\n";
    std::cout << "4. Update item\n";
    std::cout << "5. Delete item\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int findItemById(const Item items[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (items[i].used && items[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addItem(Item items[], int &count) {
    if (count >= MAX_RECORDS) {
        std::cout << "Inventory is full.\n";
        return;
    }

    Item item;
    std::cout << "Enter item id: ";
    std::cin >> item.id;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid id.\n";
        return;
    }

    if (findItemById(items, count, item.id) != -1) {
        clearInput();
        std::cout << "Id already exists.\n";
        return;
    }

    clearInput();
    std::cout << "Enter item name: ";
    std::getline(std::cin, item.name);
    std::cout << "Enter quantity: ";
    std::cin >> item.quantity;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid quantity.\n";
        return;
    }

    std::cout << "Enter price: ";
    std::cin >> item.price;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid price.\n";
        return;
    }

    item.used = true;
    items[count++] = item;
    clearInput();
    std::cout << "Item added successfully.\n";
}

void viewItems(const Item items[], int count) {
    std::cout << "\nInventory List:\n";
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (items[i].used) {
            found = true;
            std::cout << "Id: " << items[i].id
                      << " | Name: " << items[i].name
                      << " | Quantity: " << items[i].quantity
                      << " | Price: " << items[i].price << "\n";
        }
    }
    if (!found) {
        std::cout << "No items in inventory.\n";
    }
}

void searchItem(const Item items[], int count) {
    std::cout << "Enter item id to search: ";
    int id;
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid id.\n";
        return;
    }

    int pos = findItemById(items, count, id);
    if (pos == -1) {
        std::cout << "Item not found.\n";
    } else {
        std::cout << "Found item: " << items[pos].name
                  << " | Quantity: " << items[pos].quantity
                  << " | Price: " << items[pos].price << "\n";
    }
}

void updateItem(Item items[], int count) {
    std::cout << "Enter item id to update: ";
    int id;
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid id.\n";
        return;
    }

    int pos = findItemById(items, count, id);
    if (pos == -1) {
        std::cout << "Item not found.\n";
        return;
    }

    clearInput();
    std::cout << "Enter new item name: ";
    std::getline(std::cin, items[pos].name);
    std::cout << "Enter new quantity: ";
    std::cin >> items[pos].quantity;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid quantity.\n";
        return;
    }

    std::cout << "Enter new price: ";
    std::cin >> items[pos].price;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid price.\n";
        return;
    }

    clearInput();
    std::cout << "Item updated successfully.\n";
}

void deleteItem(Item items[], int count) {
    std::cout << "Enter item id to delete: ";
    int id;
    std::cin >> id;
    if (std::cin.fail()) {
        std::cin.clear();
        clearInput();
        std::cout << "Invalid id.\n";
        return;
    }

    int pos = findItemById(items, count, id);
    if (pos == -1) {
        std::cout << "Item not found.\n";
    } else {
        items[pos].used = false;
        std::cout << "Item deleted successfully.\n";
    }
}

int main() {
    Item inventory[MAX_RECORDS]{};
    int count = 0;
    int choice = 0;

    do {
        showMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            clearInput();
            choice = 0;
        }

        switch (choice) {
            case 1:
                addItem(inventory, count);
                break;
            case 2:
                viewItems(inventory, count);
                break;
            case 3:
                searchItem(inventory, count);
                break;
            case 4:
                updateItem(inventory, count);
                break;
            case 5:
                deleteItem(inventory, count);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Please enter a number between 1 and 6.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
