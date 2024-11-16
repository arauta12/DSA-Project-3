#include "HomeWindow.h"
#include "DataWindow.h"
// #include <gtkmm-4.0/gtkmm.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("testing.com");
    return app->make_window_and_run<HomeWindow>(argc, argv);
}
