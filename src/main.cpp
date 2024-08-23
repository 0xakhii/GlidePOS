#include "pos.hpp"

/**
 * @brief Constructor for the Gui class.
 * 
 * This constructor initializes the GUI frame with the specified title and size.
 * It creates various GUI elements such as panels, static texts, text controls, buttons, and menus.
 * Event bindings are also set up for the buttons and menus.
 */

bool Pos::OnInit() {
    Gui *gui = new Gui();
    gui->Show(true);
    return true;
}

Gui::Gui() : wxFrame(nullptr, wxID_ANY, "GlidePOS", wxDefaultPosition, wxSize(400, 300)) {
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    wxStaticText* nameLabel = new wxStaticText(panel, wxID_ANY, "Name:", wxPoint(10, 10));
    nameCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 10));

    wxStaticText* priceLabel = new wxStaticText(panel, wxID_ANY, "Price:", wxPoint(10, 40));
    priceCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 40));

    wxStaticText* quantityLabel = new wxStaticText(panel, wxID_ANY, "Quantity:", wxPoint(10, 70));
    quantityCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 70));

    wxButton* addButton = new wxButton(panel, wxID_ANY, "Add Product", wxPoint(10, 100));
    Bind(wxEVT_BUTTON, &Gui::OnAddNewItem, this, addButton->GetId());

    productListBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 140), wxSize(360, 120));

    wxMenu *menu = new wxMenu;
    menu->Append(wxID_EXIT, "E&xit");
    wxMenu *about = new wxMenu;
    about->Append(wxID_ABOUT, "&About");
    wxMenuBar *MenuBar = new wxMenuBar;
    MenuBar->Append(menu, "&File");
    MenuBar->Append(about, "&Help");
    SetMenuBar(MenuBar);

    CreateStatusBar();
    SetStatusText("Welcome to GlidePOS");

    Bind(wxEVT_MENU, &Gui::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &Gui::OnAbout, this, wxID_ABOUT);
}

void Gui::OnAddNewItem(wxCommandEvent& event) {
    AddProduct();
}

void Gui::OnListProducts(wxCommandEvent& event) {
    ListProducts("");
}

wxIMPLEMENT_APP(Pos);
