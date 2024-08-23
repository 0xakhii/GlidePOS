#pragma once

#include <iostream>
#include <string>
#include <wx/wx.h>
#include <wx/listbox.h>
#include <wx/sizer.h>

struct Product {
    std::string name;
    double price;
    int quantity;
    int id;
    Product* next;

    Product() : name(""), price(0), quantity(0), id(0), next(nullptr) {}
};

class Pos : public wxApp{
	public:
		bool OnInit() override;
};

class Gui : public wxFrame{
	public:
		Gui();
	private:
	    wxTextCtrl* nameCtrl;
		wxTextCtrl* priceCtrl;
		wxTextCtrl* quantityCtrl;
		wxListBox* productListBox;
	    Product* productList = nullptr;
		void	OnExit(wxCommandEvent& event){
			wxMessageDialog dialog(this, "Are you sure you want to quit?", "Confirmation", wxYES_NO | wxICON_QUESTION);
			int result = dialog.ShowModal();
			if (result == wxID_YES)
				Close(true);
		}
		void	OnHello(wxCommandEvent& event){
			wxMessageBox("Welcome to GlidePOS!", "Welcome", wxOK | wxICON_INFORMATION);
		}
		void	OnAbout(wxCommandEvent& event){
			wxMessageBox("GlidePOS is a point of sale application developed by 0xakhi.", "About", wxOK | wxICON_INFORMATION);
		}
		void	OnAddNewItem(wxCommandEvent& event);
		void	OnListProducts(wxCommandEvent& event);
		void	AddProduct();
		void	ListProducts(const std::string& choice);
		void UpdateProductListBox();
};