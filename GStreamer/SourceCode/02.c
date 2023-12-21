#include <gst/gst.h>
#include <stdio.h>

#define cSUCCESS 0 // success
#define cFAIL (-1) // fail

int main(int argc, char *argv[]){
    gst_init(&argc, &argv);

    // Create pipeline
    GstElement *pipeline = gst_pipeline_new("pipeline");
    GstElement *videotestsrc= gst_element_factory_make("videotestsrc", NULL);
    GstElement *videoconvert= gst_element_factory_make("videoconvert", NULL);
    GstElement *fpsdisplaysink = gst_element_factory_make("fpsdisplaysink", NULL);
    
    gst_bin_add_many(GST_BIN(pipeline), videotestsrc, videoconvert, fpsdisplaysink, NULL);
    gst_element_link_many(videotestsrc, videoconvert, fpsdisplaysink, NULL);
    gst_element_set_state(pipeline, GST_STATE_READY);

    if(!videotestsrc) g_printerr("Failed to create videotestsrc element.\n");
    if(!videoconvert) g_printerr("Failed to create videoconvert element.\n");
    if(!fpsdisplaysink) g_printerr("Failed to create fpsdisplaysink element.\n");

    GMainLoop *loop = g_main_loop_new(NULL, FALSE);

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    g_main_loop_run(loop);

    // Clean up
    gst_element_set_state(pipeline, GST_STATE_NULL);

    g_main_loop_unref(loop);

    gst_object_unref(pipeline);

    return 0;
}