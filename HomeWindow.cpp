//
// Created by andre on 11/16/2024.
// Logo from: https://logos.fandom.com/wiki/United_States_Department_of_Education
// Search icon from: https://icon-library.com/icon/magnifying-glass-icon-transparent-29.html
//

#include "HomeWindow.h"
#include "DataWindow.h"

HomeWindow::HomeWindow() : sort_button_("Sort!") {
    std::cout << "Making home window..." << std::endl;

    // Window basic properties
    set_title("Public School Query");
    set_default_size(500, 600);

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
        std::cout << "Adding USDE pic..." << std::endl;
        auto svg_img = Gtk::make_managed<Gtk::Picture>();
        svg_img->set_file(picture_);
        main_grid_.attach(*svg_img, 0, 0);
    } else {
        std::cout << "No picture found" << std::endl;
    }
}

void HomeWindow::setSearchIcon(Gtk::Grid& g) {
    auto picture_ = Gio::File::create_for_path("../Images/mag_glass.jpg");
    if (picture_->query_exists()) {
        std::cout << "Adding Search icon..." << std::endl;
        auto jpg_img = Gtk::make_managed<Gtk::Picture>();
        jpg_img->set_file(picture_);
        g.attach(*jpg_img, 0, 0);
    } else {
        std::cout << "No picture found" << std::endl;
    }
}

//FIXME: Include school data
void HomeWindow::sortFunction() {
    std::cout << "Sorting..." << std::endl;
    auto app_data = Gtk::Application::create("data.com");
    std::cout << "Data parameters: max?)" << max_->get_active() << ", state: "
                << static_cast<std::string>(state_entry_->get_text()) << ", filter:"
                << static_cast<std::string>(filters_.get_active_text()) << std::endl;
    int status = app_data->make_window_and_run<DataWindow>(0, NULL, &schools_, max_->get_active(),
                                                            static_cast<std::string>(filters_.get_active_text()),
                                                            static_cast<std::string>(state_entry_->get_text()),
                                                            static_cast<std::string>(sort_options_.get_active_text()));
    if (status != 0) throw std::runtime_error("Error making application window");
    std::cout << "Returning to Home..." << std::endl;
}

void HomeWindow::setSortSignal() {
    sort_button_.signal_clicked().connect(sigc::mem_fun(*this, &HomeWindow::sortFunction));
}

void HomeWindow::setGridProperties() {
    main_grid_.set_expand(true);
}

void HomeWindow::setSortButtonProperties() {
    std::cout << "Setting sort button..." << std::endl;
    Gtk::Grid pic_g;
    auto label = Gtk::make_managed<Gtk::Label>("Sort!");
    setSearchIcon(pic_g);
    pic_g.attach(*label, 0, 1);
    sort_button_.set_child(pic_g);

    sort_button_.set_margin(5);
    main_grid_.attach(sort_button_, 1, 1, 5, 5);
}

void HomeWindow::setCheckButtonProperties() {
    std::cout << "Setting radio buttons..." << std::endl;
    max_ = Gtk::make_managed<Gtk::CheckButton>("Max");
    min_ = Gtk::make_managed<Gtk::CheckButton>("Min");
    min_->set_group(*max_);
    max_->set_active(true);

    main_grid_.attach(*max_, 21, 0);
    main_grid_.attach(*min_, 21, 20);
}

void HomeWindow::setFiltersDropdown() {
    std::cout << "Setting filter options..." << std::endl;
    filters_.append("(Select School Grade)");
    filters_.append("Prekindergarten");
    filters_.append("Elementary");
    filters_.append("Middle");
    filters_.append("High");
    filters_.append("Other");
    filters_.set_active_text("(Select School Grade)");

    filters_.set_margin(5);

    main_grid_.attach(filters_, 0, 1, 2, 2);
}

void HomeWindow::setSortOptions() {
    std::cout << "Setting sort options..." << std::endl;
    sort_options_.append("(Select Sort Category)");
    sort_options_.append("Population");
    sort_options_.append("Free/reduced lunch");
    sort_options_.append("Student-to-Faculty");
    sort_options_.set_active_text("(Select Sort Category)");

    filters_.set_margin(5);

    main_grid_.attach(sort_options_, 0, 3, 2, 2);
}

void HomeWindow::setData() {
    Filereading::readFile(schools_);
}

void HomeWindow::setStateInput() {
    state_entry_ = Gtk::EntryBuffer::create();
    state_filter_field_.set_placeholder_text("Enter State abbreviation: ");
    state_filter_field_.set_buffer(state_entry_);
    state_filter_field_.set_margin(5);
    main_grid_.attach(state_filter_field_, 0, 10, 2, 2);
}










