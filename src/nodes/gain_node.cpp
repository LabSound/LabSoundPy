/**
 * Implementation file for GainNode bindings.
 */

#include "nodes/gain_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_gain_node(nb::module_ &m) {
    // Bind the GainNode class
    nb::class_<lab::GainNode, lab::AudioNode>(m, "_GainNode", nb::is_holder_type<std::shared_ptr<lab::GainNode>>())
        .def("gain", [](lab::GainNode& node) {
            return node.gain();
        });
}
