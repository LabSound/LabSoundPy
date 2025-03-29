/**
 * Implementation file for FunctionNode bindings.
 */

#include "nodes/function_node.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/function.h>

void register_function_node(nb::module_ &m) {
    // Bind the FunctionNode class
    nb::class_<lab::FunctionNode, lab::AudioNode>(m, "_FunctionNode")
        .def("set_process_function", [](lab::FunctionNode& node, std::function<void(lab::ContextRenderLock&, lab::FunctionNode*, int, float*, int)> process_function) {
            node.setFunction(process_function);
        }, nb::arg("process_function"))
        .def("start", &lab::FunctionNode::start, nb::arg("when") = 0.0)
        .def("stop", &lab::FunctionNode::stop, nb::arg("when") = 0.0);
}
