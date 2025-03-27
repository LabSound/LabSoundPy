/**
 * Implementation file for StereoPannerNode bindings.
 */

#include "nodes/stereo_panner_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_stereo_panner_node(nb::module_ &m) {
    // Bind the StereoPannerNode class
    nb::class_<lab::StereoPannerNode, lab::AudioNode>(m, "_StereoPannerNode", nb::is_holder_type<std::shared_ptr<lab::StereoPannerNode>>())
        .def("pan", [](lab::StereoPannerNode& node) {
            return node.pan();
        });
}
