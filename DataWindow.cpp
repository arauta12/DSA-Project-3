//
// Created by andre on 11/16/2024.
//

#include "DataWindow.h"

DataWindow::DataWindow() {
    set_title("Query Results");
    set_default_size(500, 600);

    set_child(data_grid_);

    setResortButtonProperties();
    setResortSignal();
}

void DataWindow::setResortSignal() {
    resort_button_.signal_clicked().connect(sigc::mem_fun(*this, &DataWindow::resortFunction));
}

void DataWindow::resortFunction() {
    std::cout << "Close window..." << std::endl;
    close();
}


void DataWindow::setResortButtonProperties() {
    auto label = Gtk::make_managed<Gtk::Label>("Resort!");
    resort_button_.set_child(*label);
    data_grid_.attach(resort_button_, 0 , 0, 20, 20);
}
