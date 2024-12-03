//
// Created by andre on 11/16/2024.
// Logo from: https://logos.fandom.com/wiki/United_States_Department_of_Education
// Search icon from: https://icon-library.com/icon/magnifying-glass-icon-transparent-29.html
//

#include "HomeWindow.h"
#include "DataWindow.h"

HomeWindow::HomeWindow() : sort_button_("Sort!") {
    // Window basic properties
    set_title("Public School Query");
    set_default_size(800, 700);
    set_resizable(false);

    // Add image to window
    setHomeImage();

    // Set window widgets
    setData();
    setSortSignal();
    setSortButtonProperties();
    setCheckButtonProperties();
    setGridProperties();
    setFiltersDropdown();
    setSortOptions();
    setStateInput();

    set_child(main_grid_);
}

void HomeWindow::setHomeImage() {
    auto picture_ = Gio::File::create_for_path("../Images/usde.svg");
    if (picture_->query_exists()) {
        auto svg_img = Gtk::make_managed<Gtk::Picture>();
        svg_img->set_file(picture_);
        svg_img->set_margin(10);
        // svg_img->set_halign(Gtk::Align::CENTER);

        main_grid_.attach(*svg_img, 4, 0, 10, 10);
    } else {
        std::cout << "No picture found" << std::endl;
    }
}

void HomeWindow::setGridProperties() {
    main_grid_.set_halign(Gtk::Align::CENTER);
    main_grid_.set_expand(true);
}

void HomeWindow::setFiltersDropdown() {

    // Section Title for Filters
    Gtk::Label label;
    label.set_text("<span font='24' weight='bold' underline='single'>Filter Options</span>");
    label.set_use_markup(true);
    label.set_margin_top(10);
    label.set_margin_bottom(10);
    main_grid_.attach(label, 4, 10, 4, 4);

    // Add filter options
    filters_.append("(Select School Grade)");
    filters_.append("Prekindergarten");
    filters_.append("Elementary");
    filters_.append("Middle");
    filters_.append("High");
    filters_.append("Other");
    filters_.set_active_text("(Select School Grade)");
    filters_.set_margin(5);

    main_grid_.attach(filters_, 4, 15, 4, 4);
}

void HomeWindow::setStateInput() {
    state_entry_ = Gtk::EntryBuffer::create();
    state_filter_field_.set_placeholder_text("Enter State abbreviation: ");
    state_filter_field_.set_buffer(state_entry_);

    state_filter_field_.set_margin(5);
    main_grid_.attach(state_filter_field_, 4, 20, 4, 4);
}

void HomeWindow::setSortOptions() {

    // Section Title for Filters
    Gtk::Label label;
    label.set_text("<span font='24' weight='bold' underline='single'>Sorting Options</span>");
    label.set_use_markup(true);
    label.set_margin_top(10);
    label.set_margin_bottom(10);
    main_grid_.attach(label, 8, 10, 4, 4);

    // Sort Options
    sort_options_.append("Population");
    sort_options_.append("Free/reduced lunch");
    sort_options_.append("Student-to-Faculty");
    sort_options_.set_active_text("Population");
    filters_.set_margin(5);

    main_grid_.attach(sort_options_, 8, 15, 4, 4);
}

void HomeWindow::setCheckButtonProperties() {
    max_ = Gtk::make_managed<Gtk::CheckButton>("Max");
    min_ = Gtk::make_managed<Gtk::CheckButton>("Min");
    min_->set_group(*max_);
    max_->set_active(true);

    main_grid_.attach(*max_, 8, 20, 4, 4);
    main_grid_.attach(*min_, 8, 25, 4, 4);
}

void HomeWindow::setSearchIcon(Gtk::Grid& g) {
    auto picture_ = Gio::File::create_for_path("../Images/mag_glass.jpg");
    if (picture_->query_exists()) {
        auto jpg_img = Gtk::make_managed<Gtk::Picture>();
        jpg_img->set_file(picture_);
        g.attach(*jpg_img, 0, 0);
    } else {
        std::cout << "No picture found" << std::endl;
    }
}


void HomeWindow::setSortButtonProperties() {
    Gtk::Grid pic_g;
    auto label = Gtk::make_managed<Gtk::Label>("Sort!");
    setSearchIcon(pic_g);
    pic_g.attach(*label, 0, 1);
    sort_button_.set_child(pic_g);

    sort_button_.set_margin(20);
    main_grid_.attach(sort_button_, 6, 30, 5, 5);
}

void HomeWindow::setData() {
    Filereading::readFile(schools_);
}

//FIXME: Include school data
void HomeWindow::sortFunction() {
    auto app_data = Gtk::Application::create("data.com");
    int status = app_data->make_window_and_run<DataWindow>(0, NULL, schools_, max_->get_active(),
                                                            static_cast<std::string>(filters_.get_active_text()),
                                                            static_cast<std::string>(state_entry_->get_text()),
                                                            static_cast<std::string>(sort_options_.get_active_text()));
    if (status != 0) throw std::runtime_error("Error making application window");
}

void HomeWindow::setSortSignal() {
    sort_button_.signal_clicked().connect(sigc::mem_fun(*this, &HomeWindow::sortFunction));
}










