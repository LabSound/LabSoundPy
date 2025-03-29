/**
 * Implementation file for DynamicsCompressorNode bindings.
 */

#include "nodes/dynamics_compressor_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_dynamics_compressor_node(nb::module_ &m) {
    // Bind the DynamicsCompressorNode class
    nb::class_<lab::DynamicsCompressorNode, lab::AudioNode>(m, "_DynamicsCompressorNode")
        .def("threshold", &lab::DynamicsCompressorNode::threshold)
        .def("knee", &lab::DynamicsCompressorNode::knee)
        .def("ratio", &lab::DynamicsCompressorNode::ratio)
        .def("attack", &lab::DynamicsCompressorNode::attack)
        .def("release", &lab::DynamicsCompressorNode::release)
        .def("reduction", &lab::DynamicsCompressorNode::reduction);
}
