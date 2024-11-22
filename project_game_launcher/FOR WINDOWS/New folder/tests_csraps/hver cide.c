#include <gtk/gtk.h>

// Callback function to handle button hover event
void on_button_enter(GtkWidget *widget, gpointer data) {
    // Set the button's relief style to GTK_RELIEF_HALF
    gtk_button_set_relief(GTK_BUTTON(widget), GTK_RELIEF_HALF);

g_print("\nenter");
}

// Callback function to handle button leave event
void on_button_leave(GtkWidget *widget, gpointer data) {
    // Set the button's relief style back to GTK_RELIEF_NORMAL
    gtk_button_set_relief(GTK_BUTTON(widget), GTK_RELIEF_NORMAL);
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Button Hover");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Hover Me!");

    // Connect the enter and leave signals to their respective callback functions
    g_signal_connect(G_OBJECT(button), "enter-notify-event", G_CALLBACK(on_button_enter), NULL);
    g_signal_connect(G_OBJECT(button), "leave-notify-event", G_CALLBACK(on_button_leave), NULL);

    // Add the button to the window
    gtk_container_add(GTK_CONTAINER(window), button);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the main loop
    gtk_main();

    return 0;
}
