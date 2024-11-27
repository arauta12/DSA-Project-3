//
// Created by andre on 11/16/2024.
//

#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <iostream>
#include "FileIO.h"
#include <gtkmm-4.0/gtkmm.h>

class HomeWindow : public Gtk::Window {
    Gtk::Grid main_grid_;
    Gtk::Button sort_button_;
    Gtk::ComboBoxText filters_;
    Gtk::ComboBoxText sort_options_;
    Gtk::CheckButton* max_;
    Gtk::CheckButton* min_;

    void setHomeImage();
    void setSearchIcon(Gtk::Grid& g);
protected:
    void setSortSignal();
    void sortFunction();
    void setGridProperties();
    void setSortButtonProperties();
    void setCheckButtonProperties();
    void setFiltersDropdown();
    void setSortOptions();
public:
    HomeWindow();
};



#endif //HOMEWINDOW_H
