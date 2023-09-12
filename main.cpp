#include <iostream>

struct Product {
    std::string name;
    double price;
    int quantity;
    int id;
    Product* next;

    Product() : name(""), price(0), quantity(0), id(0), next(nullptr) {}
};

void AddProduct(Product*& head) {
    Product* newProduct = new Product;
    std::cout << "Enter product name: ";
    std::cin >> newProduct->name;
    std::cout << "Enter product price: ";
    std::cin >> newProduct->price;
    std::cout << "Enter product quantity: ";
    std::cin >> newProduct->quantity;

    if (head == nullptr) {
        newProduct->id = 1;
        head = newProduct;
    } else {
        Product* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        newProduct->id = current->id + 1;
        current->next = newProduct;
    }

    std::cout << "Product added successfully\n";
}

void ListProducts(const Product* head, const std::string& choice) {
    const Product* current = head;
    int i = 1;
    while (current != nullptr) {
        if (choice.empty() || current->name == choice) {
            std::cout << "Product name: " << current->name << "\nProduct price: " << current->price << "\nProduct quantity: " << current->quantity << std::endl;
            i++;
        }
        current = current->next;
    }
    if (i == 1) {
        std::cout << "No products found\n";
    }
}

int main() {
    std::cout << "Welcome to the product management system\n";
    Product* productList = nullptr;

    while (true) {
        std::cout << "1. Add product\n2. List Products\n3. Exit\n";
        int mainChoice;
        std::cin >> mainChoice;
        if (mainChoice == 1) {
            std::cout << "Please enter the product details\n";
            AddProduct(productList);
        } else if (mainChoice == 2) {
            std::cout << "List products\n";
            std::cout << "1. List all products\n2. Search product by name\n";
            int subChoice;
            std::cin >> subChoice;
            if (subChoice == 1) {
                ListProducts(productList, "");
            } else if (subChoice == 2) {
                std::cout << "Enter product name to search: ";
                std::string name;
                std::cin >> name;
                ListProducts(productList, name);
            } else {
                std::cout << "Invalid choice\n";
            }
        } else if (mainChoice == 3) {
            while (productList != nullptr) {
                Product* temp = productList;
                productList = productList->next;
                delete temp;
            }
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
