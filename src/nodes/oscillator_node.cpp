/**
 * Implementation file for OscillatorNode bindings.
 */

#include "nodes/oscillator_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_oscillator_node(nb::module_ &m) {
    // Enum for oscillator type
    nb::enum_<lab::OscillatorType>(m, "OscillatorType")
        .value("SINE", lab::OscillatorType::SINE)
        .value("SQUARE", lab::OscillatorType::SQUARE)
        .value("TRIANGLE", lab::OscillatorType::TRIANGLE)
        .value("SAWTOOTH", lab::OscillatorType::SAWTOOTH)
        .value("CUSTOM", lab::OscillatorType::CUSTOM);

    // Helper function to convert string to OscillatorType
    m.def("oscillator_type_from_string", [](const std::string& type) {
        static const std::map<std::string, lab::OscillatorType> type_map = {
            {"sine", lab::OscillatorType::SINE},
            {"square", lab::OscillatorType::SQUARE},
            {"triangle", lab::OscillatorType::TRIANGLE},
            {"sawtooth", lab::OscillatorType::SAWTOOTH},
            {"custom", lab::OscillatorType::CUSTOM}
        };

        auto it = type_map.find(type);
        if (it != type_map.end()) {
            return it->second;
        }
        throw std::runtime_error("Invalid oscillator type: " + type);
    });

    // Helper function to convert OscillatorType to string
    m.def("oscillator_type_to_string", [](lab::OscillatorType type) {
        switch (type) {
            case lab::OscillatorType::SINE: return "sine";
            case lab::OscillatorType::SQUARE: return "square";
            case lab::OscillatorType::TRIANGLE: return "triangle";
            case lab::OscillatorType::SAWTOOTH: return "sawtooth";
            case lab::OscillatorType::CUSTOM: return "custom";
            default: return "unknown";
        }
    });

    // Bind the OscillatorNode class
    nb::class_<lab::OscillatorNode, lab::AudioNode>(m, "_OscillatorNode")
        .def("start", &lab::OscillatorNode::start, nb::arg("when") = 0.0)
        .def("stop", &lab::OscillatorNode::stop, nb::arg("when") = 0.0)
        .def("set_type", &lab::OscillatorNode::setType, nb::arg("type"))
        .def("type", &lab::OscillatorNode::type)
        .def("frequency", &lab::OscillatorNode::frequency)
        .def("detune", &lab::OscillatorNode::detune);
}
