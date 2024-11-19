//
// Created by andre on 11/16/2024.
//

#include "DataWindow.h"

DataWindow::DataWindow() {

    // Setting basic window properties
    std::cout << "Setting Data Window..." << std::endl;
    set_title("Query Results");
    set_default_size(500, 600);

    set_child(data_grid_);

    // Setting window widgets
    setResortButtonProperties();
    setResortSignal();
    setStatsButton();
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

void DataWindow::setStatsButton() {
    auto label = Gtk::make_managed<Gtk::Label>("View sort stats");
    statButtonSignal();
    view_stats_.set_child(*label);
    data_grid_.attach(view_stats_, 20, 0, 20, 20);
}

// Action performed when clicking stat button
void DataWindow::getStats() {
    std::cout << "Getting stats..." << std::endl;
}


void DataWindow::statButtonSignal() {
    view_stats_.signal_clicked().connect(sigc::mem_fun(*this, &DataWindow::getStats));
}

