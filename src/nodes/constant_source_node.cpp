/**
 * Implementation file for ConstantSourceNode bindings.
 */

#include "nodes/constant_source_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_constant_source_node(nb::module_ &m) {
    // Bind the ConstantSourceNode class
    nb::class_<lab::ConstantSourceNode, lab::AudioScheduledSourceNode>(m, "_ConstantSourceNode", nb::is_holder_type<std::shared_ptr<lab::ConstantSourceNode>>())
        .def("offset", [](lab::ConstantSourceNode& node) {
            return node.offset();
        });
}
