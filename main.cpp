#include "HomeWindow.h"
#include "DataWindow.h"
#include <gtkmm-4.0/gtkmm.h>

int main(int argc, char* argv[]) {
    gtk_disable_setlocale(); // used to disable GTK from overriding our locale settings
    auto app = Gtk::Application::create("testing.com");
    return app->make_window_and_run<HomeWindow>(argc, argv);
}