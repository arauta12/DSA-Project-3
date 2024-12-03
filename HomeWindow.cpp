//
// Created by andre on 11/16/2024.
// Logo from: https://logos.fandom.com/wiki/United_States_Department_of_Education
// Search icon from: https://icon-library.com/icon/magnifying-glass-icon-transparent-29.html
//

#undef ERROR  // To avoid namespace conflict errors
#include "HomeWindow.h"
#include "DataWindow.h"

HomeWindow::HomeWindow() : sort_button_("Sort!") {
    // Window basic properties
    set_title("Public School Query");  // Window Title
    set_default_size(800, 700);  // Window size
    set_child(main_grid_);  // Add grid to the Window

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
}

// Place USDE image on Window
void HomeWindow::setHomeImage() {
    auto picture_ = Gio::File::create_for_path("../Images/usde.svg");
    if (picture_->query_exists()) {  // Able to find Image
        auto svg_img = Gtk::make_managed<Gtk::Picture>();
        svg_img->set_file(picture_);
        svg_img->set_margin(20);

        main_grid_.attach(*svg_img, 0, 0, 10, 10);
    } else {  // Unable to find Image
        std::cout << "No picture found" << std::endl;
    }
}

// Set global, default properties of grid
void HomeWindow::setGridProperties() {
    main_grid_.set_valign(Gtk::Align::CENTER);
    main_grid_.set_column_homogeneous(true);
}

// Place filter options dropdown on Window
void HomeWindow::setFiltersDropdown() {

    // Section Title for Filters
    Gtk::Label label;
    label.set_text("<span font='24' weight='bold' underline='single'>Filter Options</span>");
    label.set_use_markup(true);
    label.set_margin_top(10);
    main_grid_.attach(label, 0, 10, 5, 1);

    // Add filter options
    filters_.append("(Select School Grade)");
    filters_.append("Prekindergarten");
    filters_.append("Elementary");
    filters_.append("Middle");
    filters_.append("High");
    filters_.append("Other");
    filters_.set_active_text("(Select School Grade)");
    filters_.set_margin(10);

    main_grid_.attach(filters_, 0, 11, 5, 1);
}

// Place state text entry on Window
void HomeWindow::setStateInput() {

    // Create text user input
    state_entry_ = Gtk::EntryBuffer::create();
    state_entry_->set_max_length(12);

    // Set text field properties
    state_filter_field_.set_placeholder_text("(enter here)");
    auto label = Gtk::make_managed<Gtk::Label>("<span underline='single'>Enter State abbreviation</span>: ");
    label->set_margin_start(10);
    label->set_use_markup(true);
    main_grid_.attach(*label, 0, 12, 2, 1);

    state_filter_field_.set_buffer(state_entry_);
    main_grid_.attach(state_filter_field_, 2, 12, 2, 1);
}

// Add sorting options to Window
void HomeWindow::setSortOptions() {

    // Section Title for Filters
    Gtk::Label label;
    label.set_text("<span font='24' weight='bold' underline='single'>Sort Options</span>");
    label.set_use_markup(true);
    label.set_margin_top(10);
    main_grid_.attach(label, 5, 10, 5, 1);

    // Sort Options
    sort_options_.append("Population");
    sort_options_.append("Free/reduced lunch");
    sort_options_.append("Student-to-Faculty");
    sort_options_.set_active_text("Population");
    sort_options_.set_margin(10);
    main_grid_.attach(sort_options_, 5, 11, 5, 1);
}

// Add max/min radio buttons to Window
void HomeWindow::setCheckButtonProperties() {

    // Create radio buttons
    max_ = Gtk::make_managed<Gtk::CheckButton>("Max");
    min_ = Gtk::make_managed<Gtk::CheckButton>("Min");
    min_->set_group(*max_);
    max_->set_active(true);

    main_grid_.attach(*max_, 5, 12, 2, 1);
    main_grid_.attach(*min_, 5, 13, 2, 1);
}

// Add search icon to search button
void HomeWindow::setSearchIcon(Gtk::Grid& g) {
    auto picture_ = Gio::File::create_for_path("../Images/mag_glass.jpg");
    if (picture_->query_exists()) {  // Found image in path
        auto jpg_img = Gtk::make_managed<Gtk::Picture>();
        jpg_img->set_file(picture_);
        g.attach(*jpg_img, 0, 0);
    } else {  // Unable to find image
        std::cout << "No picture found" << std::endl;
    }
}

// Add sort button to Window
void HomeWindow::setSortButtonProperties() {

    // Creating the button
    Gtk::Grid pic_g;
    auto label = Gtk::make_managed<Gtk::Label>("Sort!");
    setSearchIcon(pic_g);
    pic_g.attach(*label, 0, 1);
    sort_button_.set_child(pic_g);

    sort_button_.set_margin(20);
    main_grid_.attach(sort_button_, 3, 30, 4, 4);
}

// Get data from file
void HomeWindow::setData() {
    Filereading::readFile(schools_);
}

// Creates and runs DataWindow when sort button is clicked
void HomeWindow::sortFunction() {
    auto app_data = Gtk::Application::create("data.com");
    int status = app_data->make_window_and_run<DataWindow>(0, NULL, schools_, max_->get_active(),
                                                            static_cast<std::string>(filters_.get_active_text()),
                                                            static_cast<std::string>(state_entry_->get_text()),
                                                            static_cast<std::string>(sort_options_.get_active_text()));
    if (status != 0) throw std::runtime_error("Error running application window");
}

// Links sortFunction to sort button press
void HomeWindow::setSortSignal() {
    sort_button_.signal_clicked().connect(sigc::mem_fun(*this, &HomeWindow::sortFunction));
}










