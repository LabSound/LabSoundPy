/**
 * Implementation file for DelayNode bindings.
 */

#include "nodes/delay_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_delay_node(nb::module_ &m) {
    // Bind the DelayNode class
    nb::class_<lab::DelayNode, lab::AudioNode>(m, "_DelayNode", nb::is_holder_type<std::shared_ptr<lab::DelayNode>>())
        .def("delay_time", [](lab::DelayNode& node) {
            return node.delayTime();
        });
}
