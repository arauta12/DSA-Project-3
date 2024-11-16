//
// Created by andre on 11/16/2024.
//

#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <iostream>
#include <gtkmm-4.0/gtkmm.h>

class DataWindow : public Gtk::Window {
    Gtk::Grid data_grid_;
    Gtk::Button resort_button_;
protected:
    void setResortSignal();
    void resortFunction();
    void setResortButtonProperties();
public:
    DataWindow();
};



#endif //DATAWINDOW_H
