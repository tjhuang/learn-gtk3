#include <gtk/gtk.h>

static void hello(GtkWidget *widget, gpointer data)
{
	printf("Hello %s\n", (char *) data);
}

int main (int argc, char **argv)
{
	GtkBuilder *builder = NULL;
	GObject *window = NULL;
	GObject *button = NULL;
	GError *error = NULL;
	int status;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	if (gtk_builder_add_from_file(builder, "builder.ui", &error) == 0)
	{
		fprintf(stderr, "Failed to load file: %s\n", error->message);
		g_clear_error (&error);
		return -1;
	}

	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	button = gtk_builder_get_object(builder, "button1");
	g_signal_connect(button, "clicked", G_CALLBACK(hello), "button 1");

	button = gtk_builder_get_object(builder, "button2");
	g_signal_connect(button, "clicked", G_CALLBACK(hello), "button 2");

	button = gtk_builder_get_object(builder, "quit");
	g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);

	gtk_main();

	return 0;
}
