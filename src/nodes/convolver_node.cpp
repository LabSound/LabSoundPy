/**
 * Implementation file for ConvolverNode bindings.
 */

#include "nodes/convolver_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_convolver_node(nb::module_ &m) {
    // Bind the ConvolverNode class
    nb::class_<lab::ConvolverNode, lab::AudioNode>(m, "_ConvolverNode")
        .def("set_buffer", &lab::ConvolverNode::setImpulse, nb::arg("buffer"))
        .def("normalize", &lab::ConvolverNode::normalize)
        .def("set_normalize", &lab::ConvolverNode::setNormalize, nb::arg("normalize"));
}
