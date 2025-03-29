/**
 * Implementation file for PannerNode bindings.
 */

#include "nodes/panner_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/map.h>

void register_panner_node(nb::module_ &m) {
    // First, register the PanningModel enum
    nb::enum_<lab::PanningModel>(m, "PanningModel")
        .value("EQUALPOWER", lab::PanningModel::EQUALPOWER)
        .value("HRTF", lab::PanningModel::HRTF);
    
    // Register the DistanceModel enum
    nb::enum_<lab::PannerNode::DistanceModel>(m, "DistanceModel")
        .value("LINEAR", lab::PannerNode::LINEAR_DISTANCE)
        .value("INVERSE", lab::PannerNode::INVERSE_DISTANCE)
        .value("EXPONENTIAL", lab::PannerNode::EXPONENTIAL_DISTANCE);
    
    // Create a mapping from string to PanningModel for Pythonic interface
    auto panning_model_from_string = [](const std::string& model_str) {
        static const std::map<std::string, lab::PanningModel> model_map = {
            {"equalpower", lab::PanningModel::EQUALPOWER},
            {"HRTF", lab::PanningModel::HRTF}
        };
        
        auto it = model_map.find(model_str);
        if (it != model_map.end()) {
            return it->second;
        }
        throw nb::value_error(("Invalid panning model: " + model_str).c_str());
    };
    
    auto panning_model_to_string = [](lab::PanningModel model) {
        switch (model) {
            case lab::PanningModel::EQUALPOWER: return "equalpower";
            case lab::PanningModel::HRTF: return "HRTF";
            default: return "unknown";
        }
    };
    
    // Create a mapping from string to DistanceModel for Pythonic interface
    auto distance_model_from_string = [](const std::string& model_str) {
        static const std::map<std::string, int> model_map = {
            {"linear", 0},
            {"inverse", 1},
            {"exponential", 2}
        };
        
        auto it = model_map.find(model_str);
        if (it != model_map.end()) {
            return it->second;
        }
        throw nb::value_error(("Invalid distance model: " + model_str).c_str());
    };
    
    auto distance_model_to_string = [](int model) {
        switch (model) {
            case 0: return "linear";
            case 1: return "inverse";
            case 2: return "exponential";
            default: return "unknown";
        }
    };
    
    // Bind the PannerNode class
    nb::class_<lab::PannerNode, lab::AudioNode>(m, "_PannerNode")
        .def("set_position", [](lab::PannerNode &self, float x, float y, float z) {
            self.setPosition(x, y, z);
        }, nb::arg("x"), nb::arg("y"), nb::arg("z"))
        .def("position_x", [](lab::PannerNode& node) { return node.positionX(); })
        .def("position_y", [](lab::PannerNode& node) { return node.positionY(); })
        .def("position_z", [](lab::PannerNode& node) { return node.positionZ(); })
        .def("set_orientation", [](lab::PannerNode &self, float x, float y, float z) {
            lab::FloatPoint3D orientation(x, y, z);
            self.setOrientation(orientation);
        }, nb::arg("x"), nb::arg("y"), nb::arg("z"))
        .def("orientation_x", [](lab::PannerNode& node) { return node.orientationX(); })
        .def("orientation_y", [](lab::PannerNode& node) { return node.orientationY(); })
        .def("orientation_z", [](lab::PannerNode& node) { return node.orientationZ(); })
        .def("set_velocity", [](lab::PannerNode &self, float x, float y, float z) {
            self.setVelocity(x, y, z);
        }, nb::arg("x"), nb::arg("y"), nb::arg("z"))
        .def("velocity_x", [](lab::PannerNode& node) { return node.velocityX(); })
        .def("velocity_y", [](lab::PannerNode& node) { return node.velocityY(); })
        .def("velocity_z", [](lab::PannerNode& node) { return node.velocityZ(); })
        .def("distance_gain", [](lab::PannerNode& node) { return node.distanceGain(); })
        .def("cone_gain", [](lab::PannerNode& node) { return node.coneGain(); })
        .def("set_panning_model", &lab::PannerNode::setPanningModel, nb::arg("model"))
        .def("panning_model", &lab::PannerNode::panningModel)
        .def("set_distance_model", &lab::PannerNode::setDistanceModel, nb::arg("model"))
        .def("distance_model", &lab::PannerNode::distanceModel)
        .def("set_ref_distance", &lab::PannerNode::setRefDistance, nb::arg("distance"))
        .def("ref_distance", &lab::PannerNode::refDistance)
        .def("set_max_distance", &lab::PannerNode::setMaxDistance, nb::arg("distance"))
        .def("max_distance", &lab::PannerNode::maxDistance)
        .def("set_rolloff_factor", &lab::PannerNode::setRolloffFactor, nb::arg("factor"))
        .def("rolloff_factor", &lab::PannerNode::rolloffFactor)
        .def("set_cone_inner_angle", &lab::PannerNode::setConeInnerAngle, nb::arg("angle"))
        .def("cone_inner_angle", &lab::PannerNode::coneInnerAngle)
        .def("set_cone_outer_angle", &lab::PannerNode::setConeOuterAngle, nb::arg("angle"))
        .def("cone_outer_angle", &lab::PannerNode::coneOuterAngle)
        .def("set_cone_outer_gain", &lab::PannerNode::setConeOuterGain, nb::arg("gain"))
        .def("cone_outer_gain", &lab::PannerNode::coneOuterGain)
        // Add Pythonic interface for models
        .def("set_panning_model_string", [panning_model_from_string](lab::PannerNode& node, const std::string& model_str) {
            node.setPanningModel(panning_model_from_string(model_str));
        }, nb::arg("model"))
        .def("panning_model_string", [panning_model_to_string](lab::PannerNode& node) {
            return panning_model_to_string(node.panningModel());
        })
        .def("set_distance_model_string", [distance_model_from_string](lab::PannerNode& node, const std::string& model_str) {
            node.setDistanceModel(static_cast<lab::PannerNode::DistanceModel>(distance_model_from_string(model_str)));
        }, nb::arg("model"))
        .def("distance_model_string", [distance_model_to_string](lab::PannerNode& node) {
            return distance_model_to_string(static_cast<int>(node.distanceModel()));
        });
}
