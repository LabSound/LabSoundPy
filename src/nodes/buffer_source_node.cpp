/**
 * Implementation file for AudioBufferSourceNode bindings.
 */

#include "nodes/buffer_source_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_buffer_source_node(nb::module_ &m) {
    nb::class_<lab::SampledAudioNode, lab::AudioNode>(m, "_AudioBufferSourceNode")
        .def("start", static_cast<void (lab::SampledAudioNode::*)(float)>(&lab::SampledAudioNode::start), 
             nb::arg("abs_when"));
}
