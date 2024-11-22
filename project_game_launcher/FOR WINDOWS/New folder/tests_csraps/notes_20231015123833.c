
#include <gtk/gtk.h>

// Callback function to handle button hover event
void on_button_hover(GtkWidget *widget, GdkEvent *event, gpointer data) {
    // Set the button bezel color to green
    GdkRGBA color;
    gdk_rgba_parse(&color, "green");
    gtk_widget_override_background_color(widget, GTK_STATE_FLAG_NORMAL, &color);

g_print("asas");
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Button Hover Example");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 200, 100);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Hover Me!");
    g_signal_connect(button, "enter-notify-event", G_CALLBACK(on_button_hover), NULL);

    // Add the button to the window
    gtk_container_add(GTK_CONTAINER(window), button);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
