/**
 * Implementation file for AudioContext bindings.
 */

#include "audio_context.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/shared_ptr.h>

void register_audio_context(nb::module_ &m) {
    // Bind the AudioContext class
    nb::class_<lab::AudioContext, std::shared_ptr<lab::AudioContext>>(m, "_AudioContext")
        .def(nb::init<float, unsigned int, unsigned int>(),
             nb::arg("sample_rate") = 44100.0f,
             nb::arg("channels") = 2,
             nb::arg("frames_per_buffer") = 256)
        .def("start", &lab::AudioContext::start)
        .def("stop", &lab::AudioContext::stop)
        .def("current_time", &lab::AudioContext::currentTime)
        .def("destination", &lab::AudioContext::destination)
        .def("connect", [](lab::AudioContext& ctx, 
                          std::shared_ptr<lab::AudioNode> source, 
                          std::shared_ptr<lab::AudioNode> destination,
                          unsigned int output = 0, 
                          unsigned int input = 0) {
            ctx.connect(source, destination, output, input);
        }, nb::arg("source"), nb::arg("destination"), nb::arg("output") = 0, nb::arg("input") = 0)
        .def("disconnect", [](lab::AudioContext& ctx, std::shared_ptr<lab::AudioNode> node) {
            ctx.disconnect(node);
        }, nb::arg("node"))
        .def("create_oscillator", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::OscillatorNode>(ctx);
        })
        .def("create_gain", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::GainNode>(ctx);
        })
        .def("create_biquad_filter", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::BiquadFilterNode>(ctx);
        })
        .def("create_buffer_source", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::SampledAudioNode>(ctx);
        })
        .def("create_analyzer", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::AnalyserNode>(ctx);
        })
        .def("create_function", [](lab::AudioContext& ctx, int channels) {
            return std::make_shared<lab::FunctionNode>(ctx, channels);
        }, nb::arg("channels") = 1)
        .def("create_channel_merger", [](lab::AudioContext& ctx, int inputs) {
            return std::make_shared<lab::ChannelMergerNode>(ctx, inputs);
        }, nb::arg("inputs") = 2)
        .def("create_channel_splitter", [](lab::AudioContext& ctx, int outputs) {
            return std::make_shared<lab::ChannelSplitterNode>(ctx, outputs);
        }, nb::arg("outputs") = 2)
        .def("create_constant_source", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::ConstantSourceNode>(ctx);
        })
        .def("create_convolver", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::ConvolverNode>(ctx);
        })
        .def("create_delay", [](lab::AudioContext& ctx, float maxDelayTime) {
            return std::make_shared<lab::DelayNode>(ctx, maxDelayTime);
        }, nb::arg("max_delay_time") = 2.0f)
        .def("create_dynamics_compressor", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::DynamicsCompressorNode>(ctx);
        })
        .def("create_panner", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::PannerNode>(ctx);
        })
        .def("create_stereo_panner", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::StereoPannerNode>(ctx);
        })
        .def("create_wave_shaper", [](lab::AudioContext& ctx) {
            return std::make_shared<lab::WaveShaperNode>(ctx);
        });
}
