
#include <gtk/gtk.h>

void func(){

g_printf("\nHELLO!");


}

static void
app_activate (GtkApplication *app, gpointer *user_data) {

GtkWidget *window;
GtkWidget *but;
GtkWidget *fix;


window = gtk_application_window_new(app);
gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
//gtk_window_present(GTK_WINDOW(window));

fix=gtk_fixed_new();


gtk_window_set_child(GTK_WINDOW(window),fix);

but=gtk_button_new_with_label("HELOOO");

g_signal_connect (but, "clicked", G_CALLBACK (func),NULL);


gtk_fixed_put(GTK_FIXED(fix),but,200,100);

gtk_widget_show(window);

g_print ("GtkApplication is activated.\n");

}

int
main (int argc, char **argv) {
   GtkApplication *app;
   int stat;

   app = gtk_application_new ("com.github.ToshioCP.pr2", G_APPLICATION_FLAGS_NONE);
   g_signal_connect (app, "activate", G_CALLBACK (app_activate),NULL);
   stat =g_application_run (G_APPLICATION (app), argc, argv);
   g_object_unref (app);
   return stat;
 }

