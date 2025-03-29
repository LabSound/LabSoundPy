/**
 * Implementation file for WaveShaperNode bindings.
 */

#include "nodes/wave_shaper_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_wave_shaper_node(nb::module_ &m) {
    // Enum for oversample type
    nb::enum_<lab::WaveShaperNode::OverSampleType>(m, "OverSampleType")
        .value("NONE", lab::WaveShaperNode::OverSampleType::NONE)
        .value("TWO_X", lab::WaveShaperNode::OverSampleType::TWO_X)
        .value("FOUR_X", lab::WaveShaperNode::OverSampleType::FOUR_X);

    // Bind the WaveShaperNode class
    nb::class_<lab::WaveShaperNode, lab::AudioNode>(m, "_WaveShaperNode")
        .def("set_curve", [](lab::WaveShaperNode& node, const std::vector<float>& curve) {
            node.setCurve(curve);
        }, nb::arg("curve"))
        .def("curve", [](lab::WaveShaperNode& node) {
            // We don't have access to the curve directly, so we'll return an empty vector
            return std::vector<float>();
        })
        .def("set_oversample", &lab::WaveShaperNode::setOversample, nb::arg("oversample"))
        .def("oversample", &lab::WaveShaperNode::oversample);
}
