#include <gtk/gtk.h>

static void on_window_closed(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *videoWidget;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);

    // Create the video widget
    videoWidget = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), videoWidget);

    // Load the video file
    GtkWidget *videoPlayer = gtk_video_new("bfile.mp4");
    gtk_container_add(GTK_CONTAINER(videoWidget), videoPlayer);

    // Start playing the video
    gtk_media_file_set_playing(GTK_MEDIA_FILE(videoPlayer), TRUE);

    // Run the GTK main loop
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
