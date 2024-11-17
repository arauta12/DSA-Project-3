//
// Created by andre on 11/16/2024.
// Logo from: https://logos.fandom.com/wiki/United_States_Department_of_Education
//

#include "HomeWindow.h"
#include "DataWindow.h"

HomeWindow::HomeWindow() : sort_button_("Sort!") {
    set_title("Public School Query");
    set_default_size(500, 600);

    set_child(main_grid_);

    picture_ = Gio::File::create_for_path("../Images/usde.svg");
    if (picture_->query_exists()) {
        std::cout << "Adding pic..." << std::endl;
        std::cout << picture_->get_path() << std::endl;
        auto svg_img = Gtk::make_managed<Gtk::Picture>();
        svg_img->set_file(picture_);
        main_grid_.attach(*svg_img, 0, 0);
    } else {
        std::cout << "No picture found" << std::endl;
    }

    setSortSignal();
    setSortButtonProperties();
    setCheckButtonProperties();
    setGridProperties();

    std::cout << std::boolalpha << "Min is initially: " << min_->get_active() << std::endl;
}

void HomeWindow::sortFunction() {
    std::cout << "This button works" << std::endl;
    auto app_data = Gtk::Application::create("data.com");
    int status = app_data->make_window_and_run<DataWindow>(0, NULL);
    if (status != 0) throw std::runtime_error("Error making application window");
}

void HomeWindow::setSortSignal() {
    sort_button_.signal_clicked().connect(sigc::mem_fun(*this, &HomeWindow::sortFunction));
}

void HomeWindow::setGridProperties() {
    main_grid_.set_expand(true);
}

void HomeWindow::setSortButtonProperties() {
    auto label = Gtk::make_managed<Gtk::Label>("Sort!");
    sort_button_.set_child(*label);
    main_grid_.attach(sort_button_, 1, 1, 20, 20);
}

void HomeWindow::setCheckButtonProperties() {
    max_ = Gtk::make_managed<Gtk::CheckButton>("Max");
    min_ = Gtk::make_managed<Gtk::CheckButton>("Min");
    min_->set_group(*max_);
    max_->set_active(true);

    main_grid_.attach(*max_, 21, 0);
    main_grid_.attach(*min_, 21, 20);
}








