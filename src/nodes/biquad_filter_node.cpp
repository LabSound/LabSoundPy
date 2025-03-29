/**
 * Implementation file for BiquadFilterNode bindings.
 */

#include "nodes/biquad_filter_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/map.h>

// Define an enum type for BiquadFilterType
enum class BiquadFilterType {
    LOWPASS = lab::LOWPASS,
    HIGHPASS = lab::HIGHPASS,
    BANDPASS = lab::BANDPASS,
    LOWSHELF = lab::LOWSHELF,
    HIGHSHELF = lab::HIGHSHELF,
    PEAKING = lab::PEAKING,
    NOTCH = lab::NOTCH,
    ALLPASS = lab::ALLPASS
};

void register_biquad_filter_node(nb::module_ &m) {
    // Enum for filter type
    nb::enum_<BiquadFilterType>(m, "BiquadFilterType")
        .value("LOWPASS", BiquadFilterType::LOWPASS)
        .value("HIGHPASS", BiquadFilterType::HIGHPASS)
        .value("BANDPASS", BiquadFilterType::BANDPASS)
        .value("LOWSHELF", BiquadFilterType::LOWSHELF)
        .value("HIGHSHELF", BiquadFilterType::HIGHSHELF)
        .value("PEAKING", BiquadFilterType::PEAKING)
        .value("NOTCH", BiquadFilterType::NOTCH)
        .value("ALLPASS", BiquadFilterType::ALLPASS);

    // Helper function to convert string to filter type
    m.def("biquad_filter_type_from_string", [](const std::string& type) {
        static const std::map<std::string, int> type_map = {
            {"lowpass", lab::LOWPASS},
            {"highpass", lab::HIGHPASS},
            {"bandpass", lab::BANDPASS},
            {"lowshelf", lab::LOWSHELF},
            {"highshelf", lab::HIGHSHELF},
            {"peaking", lab::PEAKING},
            {"notch", lab::NOTCH},
            {"allpass", lab::ALLPASS}
        };

        auto it = type_map.find(type);
        if (it != type_map.end()) {
            return it->second;
        }
        throw std::runtime_error("Invalid filter type: " + type);
    });

    // Bind the BiquadFilterNode class
    nb::class_<lab::BiquadFilterNode, lab::AudioNode>(m, "_BiquadFilterNode")
        .def("frequency", &lab::BiquadFilterNode::frequency)
        .def("gain", &lab::BiquadFilterNode::gain)
        .def("detune", &lab::BiquadFilterNode::detune)
        .def("set_type", &lab::BiquadFilterNode::setType, nb::arg("type"));
}
