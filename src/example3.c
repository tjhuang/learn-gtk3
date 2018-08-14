#include <gtk/gtk.h>

static void hello(GtkWidget *widget, gpointer data)
{
	printf("Hello %s\n", (char *) data);
}

/**
 * @brief	Widgets can be packed by grid format
 */
static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window = NULL;
	GtkWidget *button = NULL;
	GtkWidget *grid = NULL;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "My Third Application");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

	/* Prepare the pack container */
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	button = gtk_button_new_with_label("Button 1");
	g_signal_connect(button, "clicked", G_CALLBACK(hello), "button 1");
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);	// put on row 0 column 0 with width 1 and height 1

	button = gtk_button_new_with_label("Button 2");
	g_signal_connect(button, "clicked", G_CALLBACK(hello), "button 2");
	gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);	// put on row 0 column 1 with width 1 and height 1

	button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);	// put on row 1 column 0 with width 2 and height 1

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
