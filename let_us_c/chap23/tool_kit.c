/* GTK library for GUI applications */
/* GTK stand for Gimp's Tool Kit */

#include <gtk/gtk.h>
int main(int argc, char *argv[]) {
    GtkWidget *p;
    /* init the GTK library */
    gtk_init(&argc, &argv);
    /* create a window 
     * this call creates a window in memory and return a pointer */
    p = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(p), "Sample Window");
    /* register a signal handler */
    g_signal_connect(p, "destroy", gtk_main_quit, NULL);
    /* resize */
    gtk_widget_set_size_request(p, 300, 300);
    /* display */
    gtk_widget_show(p);
    /* wait in a loop that receive event */
    gtk_main();
    return 0;
}
