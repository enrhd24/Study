#include <gst/gst.h>

int main(int argc, char **argv){
    GstElement *element;
    gchar *name;

    gst_init(&argc, &argv);

    element = gst_element_factory_make("fakesrc", "source");

    // gst name
    g_object_get(G_OBJECT(element), "name", &name, NULL);
    g_print("The name of the element is '%s'.\n", name);
    g_free(name);

    gst_object_unref(GST_OBJECT(element));
}