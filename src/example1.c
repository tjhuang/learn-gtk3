#include <gtk/gtk.h>

/**
 * @brief	Display an empty window with height 300 and width 300
 */
static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window = NULL;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "My First Application");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
	gtk_widget_show_all(window);
}

int main (int argc, char **argv)
{
	GtkApplication *app = NULL;
	int status;

	app = gtk_application_new("net.gtk-study.sample", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

	status = g_application_run(G_APPLICATION(app), argc, argv);
	printf("Program end with status: %d\n", status);

	g_object_unref(app);

	return status;
}
