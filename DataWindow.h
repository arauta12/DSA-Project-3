//
// Created by andre on 11/16/2024.
//

#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <iostream>
#include <gtkmm-4.0/gtkmm.h>

#include "School.h"

class DataWindow : public Gtk::Window {
    Gtk::Grid main_grid_;
    Gtk::Grid data_grid_;
    Gtk::Button resort_button_;
    Gtk::Button view_stats_;
    std::vector<School*> schools_;
protected:
    void setResortSignal();
    void resortFunction();
    void setResortButtonProperties();
    void setStatsButton();
    void statButtonSignal();

    void addRow(School* s, int r);
    void setTable();
    void getStats();
public:
    DataWindow();
};



#endif //DATAWINDOW_H
