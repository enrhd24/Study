#include <gst/gst.h>

int main(int argc, char **argv){
    GstElement *pipeline;
    GstElement *source, *filter, *sink;

    gst_init(&argc, &argv);

    // create pipeline
    pipeline = gst_pipeline_new("my-pipeline");

    // create elements
    source = gst_element_factory_make("fakesrc", "source");
    filter = gst_element_factory_make("idenriry", "filter");
    sink = gst_element_factory_make("fakesink", "sink");

    // must add elements to pipeline before linking them
    gst_bin_add_many(GST_BIN(pipeline), source, filter, sink, NULL);

    // link
    if(!gst_element_link_many(source, filter, sink, NULL)) g_warning("Failed to link elements!");

    gst_object_unref(GST_OBJECT(pipeline));

    return 0;
}