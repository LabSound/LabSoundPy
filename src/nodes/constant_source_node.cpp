/**
 * Implementation file for ConstantSourceNode bindings.
 */

#include "nodes/constant_source_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_constant_source_node(nb::module_ &m) {
    // Bind the ConstantSourceNode class
    nb::class_<lab::ConstantSourceNode, lab::AudioNode>(m, "_ConstantSourceNode")
        .def("offset", &lab::ConstantSourceNode::offset)
        .def("start", &lab::ConstantSourceNode::start, nb::arg("when") = 0.0)
        .def("stop", &lab::ConstantSourceNode::stop, nb::arg("when") = 0.0);
}
