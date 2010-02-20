#include "config.h"

#ifdef HAVE_HILDON
#include <hildon/hildon.h>
#endif  /* HAVE_HILDON */

#include <gtk/gtk.h>

#ifdef HAVE_HILDON
static GtkWidget *
create_scroll_widget (void)
{
  GtkWidget *scroll;

  scroll = hildon_pannable_area_new ();

  return scroll;
}

static GtkWidget *
create_main_window (void)
{
  GtkWidget *window;

  window = hildon_window_new ();

  return window;
}
#else
static GtkWidget *
create_scroll_widget (void)
{
  GtkWidget *scroll;

  scroll = gtk_scrolled_window_new (NULL, NULL);

  return scroll;
}

static GtkWidget *
create_main_window (void)
{
  GtkWidget *window;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  return window;
}
#endif

int
main (int argc, char *argv[])
{
  GtkWidget *window, *scroll, *image;

  gtk_init (&argc, &argv);

  window = create_main_window ();
  scroll = create_scroll_widget ();
  image = gtk_image_new_from_file ("./img.jpg");

  gtk_container_add (GTK_CONTAINER (window), scroll);
  
#ifdef HAVE_HILDON
  hildon_pannable_area_add_with_viewport (HILDON_PANNABLE_AREA (scroll), image);
#else
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (scroll), image);
#endif

  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}
