//
// Created by andre on 11/16/2024.
//

#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <iostream>
#include <gtkmm-4.0/gtkmm.h>

class HomeWindow : public Gtk::Window {
    Gtk::Grid main_grid_;
    Glib::RefPtr<Gio::File> picture_;
    Gtk::Button sort_button_;
    Gtk::CheckButton* max_;
    Gtk::CheckButton* min_;
    bool max_selected_;
protected:
    void setSortSignal();
    void sortFunction();
    void setGridProperties();
    void setSortButtonProperties();
    void setCheckButtonProperties();
public:
    HomeWindow();
};



#endif //HOMEWINDOW_H
