#include <gtk/gtk.h>

static void hello(GtkWidget *widget, gpointer data)
{
	printf("Hello World\n");
}

/**
 * @brief	Display a button contained by a button-box
 */
static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window = NULL;
	GtkWidget *button = NULL;
	GtkWidget *button_box = NULL;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "My Second Application");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

	button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add(GTK_CONTAINER(window), button_box);

	button = gtk_button_new_with_label("Hello World");
	g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
	gtk_container_add(GTK_CONTAINER(button_box), button);

	gtk_widget_show_all(window);
}

int main (int argc, char **argv)
{
	GtkApplication *app = NULL;
	int status;

	app = gtk_application_new("net.gtk-study.sample", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);

	g_object_unref(app);

	return status;
}
