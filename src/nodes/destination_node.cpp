/**
 * Implementation file for AudioDestinationNode bindings.
 */

#include "nodes/destination_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_destination_node(nb::module_ &m) {
    // Bind the AudioDestinationNode class
    nb::class_<lab::AudioDestinationNode, lab::AudioNode>(m, "_AudioDestinationNode", nb::is_holder_type<std::shared_ptr<lab::AudioDestinationNode>>())
        .def("max_channel_count", &lab::AudioDestinationNode::maxChannelCount)
        .def("set_channel_count", &lab::AudioDestinationNode::setChannelCount, nb::arg("count"));
}
