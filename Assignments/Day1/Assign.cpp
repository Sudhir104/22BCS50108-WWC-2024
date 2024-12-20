#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Item class
class Item {
public:
    int id;
    string name;
    string category;
    int quantity;
    int reorderLevel;

    Item(int id, string name, string category, int quantity, int reorderLevel) {
        this->id = id;
        this->name = name;
        this->category = category;
        this->quantity = quantity;
        this->reorderLevel = reorderLevel;
    }

    void display() const { // Marking display as const
        cout << "ID: " << id << ", Name: " << name
             << ", Category: " << category << ", Quantity: " << quantity
             << ", Reorder Level: " << reorderLevel << endl;
    }
};

// Inventory class
class Inventory {
public:
    vector<Item> items;
    int nextId = 1;

    void addItem(string name, string category, int quantity, int reorderLevel) {
        items.push_back(Item(nextId++, name, category, quantity, reorderLevel));
        cout << "Item added successfully!\n";
    }

    void updateStock(int id, int quantity) {
        for (auto &item : items) {
            if (item.id == id) {
                item.quantity += quantity;
                cout << "Stock updated successfully!\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    void viewInventory() {
        for (const auto &item : items) { // Using const reference
            item.display();
            if (item.quantity < item.reorderLevel) {
                cout << "ALERT: Stock for " << item.name << " is below reorder level!\n";
            }
        }
    }

    void searchItem(string name) {
        for (const auto &item : items) { // Using const reference
            if (item.name == name) {
                item.display();
                return;
            }
        }
        cout << "Item not found!\n";
    }

    void exportToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto &item : items) {
                file << item.id << "," << item.name << "," << item.category << ","
                     << item.quantity << "," << item.reorderLevel << "\n";
            }
            cout << "Inventory exported to " << filename << endl;
        } else {
            cout << "Error opening file!\n";
        }
    }
};

// Display menu
void displayMenu() {
    cout << "\nWarehouse Inventory Management System\n";
    cout << "1. Add Item\n";
    cout << "2. Update Stock\n";
    cout << "3. View Inventory\n";
    cout << "4. Search Item\n";
    cout << "5. Export Inventory to File\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            string name, category;
            int quantity, reorderLevel;
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter reorder level: ";
            cin >> reorderLevel;
            inventory.addItem(name, category, quantity, reorderLevel);
        } else if (choice == 2) {
            int id, quantity;
            cout << "Enter item ID: ";
            cin >> id;
            cout << "Enter quantity to add/subtract: ";
            cin >> quantity;
            inventory.updateStock(id, quantity);
        } else if (choice == 3) {
            inventory.viewInventory();
        } else if (choice == 4) {
            string name;
            cout << "Enter item name to search: ";
            cin >> name;
            inventory.searchItem(name);
        } else if (choice == 5) {
            string filename;
            cout << "Enter filename to save inventory: ";
            cin >> filename;
            inventory.exportToFile(filename);
        } else if (choice == 6) {
            cout << "Exiting program. Goodbye!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
