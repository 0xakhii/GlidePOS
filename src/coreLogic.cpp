#include "pos.hpp"

/**
 * @brief Adds a new product to the GUI.
 * 
 * This function creates a new Product object and populates its attributes based on the values entered in the text controls of the GUI. 
 * It performs validation checks on the name, price, and quantity inputs to ensure they are valid.
 * If any of the inputs are invalid, an error message is displayed and the new product is deleted.
 * If the inputs are valid, the new product is added to the product list.
 * Finally, the product list is updated and a success message is displayed.
 */
void Gui::AddProduct() {
    Product* newProduct = new Product;

    std::string name = nameCtrl->GetValue().ToStdString();
    if (!name.empty()) {
        newProduct->name = name;
    } else {
        wxMessageBox("Invalid Name.", "Error", wxOK | wxICON_ERROR);
        delete newProduct;
        return;
    }

    std::string priceStr = priceCtrl->GetValue().ToStdString();
    try {
        double price = std::stod(priceStr);
        if (price > 0) {
            newProduct->price = price;
        } else {
            wxMessageBox("Invalid Price.", "Error", wxOK | wxICON_ERROR);
            delete newProduct;
            return;
        }
    } catch (const std::invalid_argument&) {
        wxMessageBox("Invalid Price format.", "Error", wxOK | wxICON_ERROR);
        delete newProduct;
        return;
    }

    std::string quantityStr = quantityCtrl->GetValue().ToStdString();
    try {
        int quantity = std::stoi(quantityStr);
        if (quantity > 0) {
            newProduct->quantity = quantity;
        } else {
            wxMessageBox("Invalid Quantity.", "Error", wxOK | wxICON_ERROR);
            delete newProduct;
            return;
        }
    } catch (const std::invalid_argument&) {
        wxMessageBox("Invalid Quantity format.", "Error", wxOK | wxICON_ERROR);
        delete newProduct;
        return;
    }

    if (productList == nullptr) {
        newProduct->id = 1;
        productList = newProduct;
    } else {
        Product* current = productList;
        while (current->next != nullptr) {
            current = current->next;
        }
        newProduct->id = current->id + 1;
        current->next = newProduct;
    }

    UpdateProductListBox();
    wxMessageBox("Product added successfully", "Success", wxOK | wxICON_INFORMATION);
}

void Gui::ListProducts(const std::string& choice) {
    wxString output;
    const Product* current = productList;
    while (current != nullptr) {
        if (choice.empty() || current->name == choice) {
            output += wxString::Format("Name: %s\nPrice: %.2f\nQuantity: %d\n\n", current->name, current->price, current->quantity);
        }
        current = current->next;
    }

    if (output.IsEmpty()) {
        wxMessageBox("No products found", "Information", wxOK | wxICON_INFORMATION);
    } else {
        wxMessageBox(output, "Product List", wxOK | wxICON_INFORMATION);
    }
}


void Gui::UpdateProductListBox() {
    productListBox->Clear();
    const Product* current = productList;
    while (current != nullptr) {
        productListBox->Append(wxString::Format("ID: %d | Name: %s | Price: %.2f | Qty: %d", current->id, current->name, current->price, current->quantity));
        current = current->next;
    }
}