//
// Created by andre on 11/16/2024.
//

#include "DataWindow.h"
#include "FileIO.h"
#include "Graphing.h"

DataWindow::DataWindow(std::vector<School*>& schools_, bool max, std::string level,
                    std::string state, std::string sort_opt) {

    // Setting basic window properties
    set_title("Query Results");
    set_default_size(500, 600);

    filterData(schools_, max, level, state, sort_opt);
    setTable();

    set_child(main_grid_);

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
    main_grid_.attach(resort_button_, 0 , 20, 20, 20);
}

void DataWindow::setStatsButton() {
    auto label = Gtk::make_managed<Gtk::Label>("View sort stats");
    statButtonSignal();
    view_stats_.set_child(*label);
    main_grid_.attach(view_stats_, 20, 20, 20, 20);
}

// Action performed when clicking stat button
//FIXME: Add sorting data
void DataWindow::getStats() {
    std::cout << "Getting stats..." << std::endl;
    std::vector<float> v1 = {1, 2, 3, 4, 5}, v2 = {0, 2, 6, 7, 8};
    Graph graph;
    graph.graphTimes(v1, v2);
}

void DataWindow::statButtonSignal() {
    view_stats_.signal_clicked().connect(sigc::mem_fun(*this, &DataWindow::getStats));
}

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

    int total = s->population;
    std::string res = "N/A";
    if (total > 0) {
        int m_ratio = round(stof(s->totmen)/total * 100);
        int f_ratio = round(stof(s->totfem)/total * 100);
        res = std::to_string(m_ratio) + ":" + std::to_string(f_ratio);
    }
    label = Gtk::make_managed<Gtk::Label>(res);
    data_grid_.attach(*label, 5, r);

    res = "N/A";
    if ((int)s->freereducedlunch > 0) res = std::to_string((int)s->freereducedlunch);
    label = Gtk::make_managed<Gtk::Label>(res);
    data_grid_.attach(*label, 6, r);

    res = "N/A";
    if ((int)s->studentfacratio > 0) res = std::to_string((int)s->studentfacratio);
    label = Gtk::make_managed<Gtk::Label>(res);
    data_grid_.attach(*label, 7, r);
}

//FIXME: Move to Home?
void DataWindow::setTable() {
    data_grid_.set_column_spacing(5);

    std::vector<std::string> headers = {"School Name", "City", "County", "Grade Levels", "Students"
                            , "M-F ratio", "Lunch Type", "Student-to-Faculty ratio"};

    for (int i = 0; i < headers.size(); i++) {
        auto label = Gtk::make_managed<Gtk::Label>(headers[i]);
        label->set_use_underline(true);
        data_grid_.attach(*label, i, 0);

        auto separator = Gtk::make_managed<Gtk::Separator>(Gtk::Orientation::HORIZONTAL);
        data_grid_.attach(*separator, i, 1);
    }

    for (int i = 0; i < std::min((int)filtered_data_.size(), 10); ++i) addRow(filtered_data_[i], i + 2);
    main_grid_.attach(data_grid_, 0, 0, 1, 1);
}

void DataWindow::filterData(std::vector<School*>& schools_, bool max, std::string level,
                    std::string state, std::string sort_opt) {
    filtered_data_ = Filereading::filterLevel(schools_, level);
    filtered_data_ = Filereading::filterState(filtered_data_, state);
    std::cout << "filtered data has size: " << filtered_data_.size() << std::endl;
}



