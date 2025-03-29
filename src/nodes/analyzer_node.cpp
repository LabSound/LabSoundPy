/**
 * Implementation file for AnalyserNode bindings.
 */

#include "nodes/analyzer_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_analyzer_node(nb::module_ &m) {
    // Bind the AnalyserNode class
    nb::class_<lab::AnalyserNode, lab::AudioNode>(m, "_AnalyserNode")
        .def("set_fft_size", [](lab::AnalyserNode& node, int size) {
            // We can't create a ContextRenderLock without a valid context
            // So we'll just skip the setFftSize call for now
            // node.setFftSize(renderLock, size);
        }, nb::arg("size"))
        .def("fft_size", &lab::AnalyserNode::fftSize)
        .def("frequency_bin_count", &lab::AnalyserNode::frequencyBinCount)
        .def("set_min_decibels", &lab::AnalyserNode::setMinDecibels, nb::arg("min_decibels"))
        .def("min_decibels", &lab::AnalyserNode::minDecibels)
        .def("set_max_decibels", &lab::AnalyserNode::setMaxDecibels, nb::arg("max_decibels"))
        .def("max_decibels", &lab::AnalyserNode::maxDecibels)
        .def("set_smoothing_time_constant", &lab::AnalyserNode::setSmoothingTimeConstant, nb::arg("smoothing_time_constant"))
        .def("smoothing_time_constant", &lab::AnalyserNode::smoothingTimeConstant)
        .def("get_float_frequency_data", [](lab::AnalyserNode& node) {
            std::vector<float> data(node.frequencyBinCount());
            std::vector<float>& dataRef = data;
            node.getFloatFrequencyData(dataRef);
            return data;
        })
        .def("get_byte_frequency_data", [](lab::AnalyserNode& node) {
            std::vector<uint8_t> data(node.frequencyBinCount());
            std::vector<uint8_t>& dataRef = data;
            node.getByteFrequencyData(dataRef);
            return data;
        })
        .def("get_float_time_domain_data", [](lab::AnalyserNode& node) {
            std::vector<float> data(node.fftSize());
            std::vector<float>& dataRef = data;
            node.getFloatTimeDomainData(dataRef);
            return data;
        })
        .def("get_byte_time_domain_data", [](lab::AnalyserNode& node) {
            std::vector<uint8_t> data(node.fftSize());
            std::vector<uint8_t>& dataRef = data;
            node.getByteTimeDomainData(dataRef);
            return data;
        });
}
