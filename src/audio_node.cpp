/**
 * Implementation file for AudioNode bindings.
 */

#include "audio_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_audio_node(nb::module_ &m) {
    // Bind the AudioNode base class
    nb::class_<lab::AudioNode>(m, "_AudioNode")
        .def("number_of_inputs", &lab::AudioNode::numberOfInputs)
        .def("number_of_outputs", &lab::AudioNode::numberOfOutputs)
        .def("channel_count", &lab::AudioNode::channelCount)
        .def("channel_count_mode", &lab::AudioNode::channelCountMode)
        .def("channel_interpretation", &lab::AudioNode::channelInterpretation);
}
