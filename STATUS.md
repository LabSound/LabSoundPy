# LabSoundPy Project Status

This document tracks the status of the LabSoundPy project, which aims to create Python bindings for the LabSound library using nanobind.

## Setup Status

- [x] Initialize git submodules for nanobind
- [x] Initialize git submodules for LabSound
- [x] Configure CMake to use submodules

## Binding Issues

### Core Classes

- [ ] Fix `AudioContext` class binding
  - [x] Update factory methods to use LabSound API instead of Web Audio API
  - [x] Fix nanobind template parameter syntax
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `AudioNode` class binding
  - [x] Fix nanobind template parameter syntax
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `AudioParam` class binding
  - [x] Fix nanobind template parameter syntax
  - [ ] Fix method bindings to match LabSound API

### Node Classes

- [ ] Fix `OscillatorNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API
  - [x] Fix enum binding for `OscillatorType`

- [ ] Fix `GainNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `BiquadFilterNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [x] Fix enum binding for filter types
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `SampledAudioNode` (BufferSourceNode) class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `AnalyserNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API
  - [x] Fix ndarray template parameter syntax

- [ ] Fix `FunctionNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API
  - [x] Fix function callback binding

- [ ] Fix `AudioDestinationNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `ChannelMergerNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `ChannelSplitterNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `ConstantSourceNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `ConvolverNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `DelayNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `DynamicsCompressorNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `PannerNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `StereoPannerNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [ ] Fix method bindings to match LabSound API

- [ ] Fix `WaveShaperNode` class binding
  - [x] Fix nanobind template parameter syntax for inheritance
  - [x] Fix method bindings to match LabSound API

## Testing

- [ ] Build and install the package
- [ ] Run basic tests to verify functionality
- [ ] Test with example scripts

## Documentation

- [ ] Update README.md with installation instructions
- [ ] Document Python API
- [ ] Add examples
