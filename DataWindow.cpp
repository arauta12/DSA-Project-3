//
// Created by andre on 11/16/2024.
//

#include "DataWindow.h"
#include "FileIO.h"
#include "Graphing.h"
#include "Sorting.h"

DataWindow::DataWindow(std::vector<School*>& schools_, bool max, std::string level,
                    std::string state, std::string sort_opt) : min_sort_(not max), level_(level),
                    sort_opt_(sort_opt) {

    // Setting basic window properties
    set_title("Query Results");
    set_default_size(500, 600);
    set_child(data_grid_);

    // Filter the data and display
    filterData(schools_, state);
    setTable();

    // Setting window widgets
    setResortButtonProperties();
    setResortSignal();
    setStatsButton();
}

// Link resortFunction to resort button press
void DataWindow::setResortSignal() {
    resort_button_.signal_clicked().connect(sigc::mem_fun(*this, &DataWindow::resortFunction));
}

// Close this window when resort button is clicked
void DataWindow::resortFunction() { close(); }

// Add resort button to Window
void DataWindow::setResortButtonProperties() {
    auto label = Gtk::make_managed<Gtk::Label>("Resort!");
    resort_button_.set_child(*label);
    resort_button_.set_margin(30);
    data_grid_.attach(resort_button_, 0, 12, 3, 1);
}

// Add stats button to Window
void DataWindow::setStatsButton() {
    auto label = Gtk::make_managed<Gtk::Label>("View sort stats");
    statButtonSignal();
    view_stats_.set_child(*label);
    view_stats_.set_margin(30);
    data_grid_.attach(view_stats_, 4, 12, 4, 1);
}

// Action performed when clicking stat button
void DataWindow::getStats() {
    Graph graph;
    graph.graphTimes(filtered_data_, sort_opt_, min_sort_);
}

// Link getStats function to stats button press
void DataWindow::statButtonSignal() {
    view_stats_.signal_clicked().connect(sigc::mem_fun(*this, &DataWindow::getStats));
}

// Add new row to display table in Window
void DataWindow::addRow(School* s, int r) {

    auto label = Gtk::make_managed<Gtk::Label>(s->schname);
    data_grid_.attach(*label, 0, r);

    label = Gtk::make_managed<Gtk::Label>(s->city);
    data_grid_.attach(*label, 1, r);

    label = Gtk::make_managed<Gtk::Label>(s->county);
    data_grid_.attach(*label, 2, r);

    label = Gtk::make_managed<Gtk::Label>(s->gslo + "-" + s->gshi);
    data_grid_.attach(*label, 3, r);

    label = Gtk::make_managed<Gtk::Label>(s->stupop);
    data_grid_.attach(*label, 4, r);

    // Calculate M-F ratio if data exists
    int total = s->population;
    std::string res = "N/A";
    if (total > 0 and not s->totmen.empty() and not s->totfem.empty()) {
        int m_ratio = round(stof(s->totmen)/total * 100);
        int f_ratio = round(stof(s->totfem)/total * 100);
        res = std::to_string(m_ratio) + ":" + std::to_string(f_ratio);
    }

    label = Gtk::make_managed<Gtk::Label>(res);
    data_grid_.attach(*label, 5, r);

    res = std::to_string((int)s->freereducedlunch);
    label = Gtk::make_managed<Gtk::Label>(res);
    data_grid_.attach(*label, 6, r);

    res = std::to_string((int)s->studentfacratio);
    label = Gtk::make_managed<Gtk::Label>(res);
    data_grid_.attach(*label, 7, r);
}

// Sort data and add all school data to Window
void DataWindow::setTable() {
    data_grid_.set_column_spacing(5);

    // Sort a copy of the filtered data (original kept for sort comparison)
    std::vector<School*> cpy_filtered_ = filtered_data_;
    mergeSort(cpy_filtered_, 0, cpy_filtered_.size() - 1, getComparisonFunction(sort_opt_, min_sort_));

    // Add display headers to table
    std::vector<std::string> headers = {"School Name", "City", "County", "Grade Levels", "Students"
                            , "M-F ratio", "Free/reduced lunch number", "Student-to-Faculty ratio"};
    for (int i = 0; i < headers.size(); i++) {
        auto label = Gtk::make_managed<Gtk::Label>("<span weight='bold'>" + headers[i] + "</span>");
        label->set_use_markup(true);
        data_grid_.attach(*label, i, 0);

        auto separator = Gtk::make_managed<Gtk::Separator>(Gtk::Orientation::HORIZONTAL);
        data_grid_.attach(*separator, i, 1);
    }

    // Add all rows to table
    for (int i = 0; i < std::min((int)cpy_filtered_.size(), 10); ++i) addRow(cpy_filtered_[i], i + 2);
}

// Filter raw school data based on user selections
void DataWindow::filterData(std::vector<School*>& schools_, std::string state) {
    if (level_ != "(Select School Grade)") {  // Option selected isn't default
        filtered_data_ = Filereading::filterLevel(schools_, level_);
    } else {
        filtered_data_ = schools_;
    }

    if (not state.empty())  // If a state is selected
        filtered_data_ = Filereading::filterState(filtered_data_, state);
}



