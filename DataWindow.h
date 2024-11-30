//
// Created by andre on 11/16/2024.
//

#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <iostream>
#include <gtkmm-4.0/gtkmm.h>

#include "School.h"

class DataWindow : public Gtk::Window {
    Gtk::Grid data_grid_;
    Gtk::Button resort_button_;
    Gtk::Button view_stats_;
    std::vector<School*> filtered_data_;
protected:
    void setResortSignal();
    void resortFunction();
    void setResortButtonProperties();
    void setStatsButton();
    void statButtonSignal();
    void setTable();
    void addRow(School* s, int r);
    void getStats();
    void filterData(std::vector<School*>& schools_, bool max, std::string level,
                    std::string state, std::string sort_opt);
public:
    DataWindow(std::vector<School*>& schools_, bool max, std::string level,
                    std::string state, std::string sort_opt);
};



#endif //DATAWINDOW_H
