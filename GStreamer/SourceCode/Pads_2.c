#include <gst/gst.h>

int main(int argc, char **argv){
    GstElement *bin, *sink;
    GstPad *pad;

    gst_init(&argc, &argv);

    // create element, add to bin
    sink = gst_element_factory_make("fakesink", "sink");
    bin = gst_bin_new("mybin");
    gst_bin_add(GST_BIN(bin), sink);

    // add ghostpad
    pad = gst_element_get_static_pad(sink, "sink");
    gst_element_add_pad(bin, gst_ghost_pad_new("sink", pad));
    gst_object_unref(GST_OBJECT(pad));

    return 0;
}