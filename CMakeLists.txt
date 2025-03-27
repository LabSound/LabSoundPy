cmake_minimum_required(VERSION 3.14)
project(labsoundpy)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Python
find_package(Python 3.7 REQUIRED COMPONENTS Interpreter Development)

# Option to use git submodules or fetch dependencies
option(USE_SUBMODULES "Use git submodules for dependencies" ON)

# Handle nanobind dependency
if(USE_SUBMODULES)
    # Check if nanobind submodule exists
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/nanobind/CMakeLists.txt")
        message(FATAL_ERROR "Nanobind submodule not found. Please run: git submodule update --init --recursive")
    endif()
else()
    # Fetch nanobind if not present
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/nanobind/CMakeLists.txt")
        message(STATUS "Downloading nanobind...")
        execute_process(
            COMMAND git clone --depth 1 https://github.com/wjakob/nanobind.git third_party/nanobind
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif()
endif()

# Add nanobind
add_subdirectory(third_party/nanobind)

# Handle LabSound dependency
if(USE_SUBMODULES)
    # Check if LabSound submodule exists
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/LabSound/CMakeLists.txt")
        message(FATAL_ERROR "LabSound submodule not found. Please run: git submodule update --init --recursive")
    endif()
    
    # Build LabSound
    set(LABSOUND_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/LabSound")
    set(LABSOUND_BUILD_EXAMPLES OFF CACHE BOOL "Build LabSound examples")
    set(LABSOUND_BUILD_TESTS OFF CACHE BOOL "Build LabSound tests")
    add_subdirectory(${LABSOUND_DIR})
    
    # Use modern CMake target-based approach
    set(LABSOUND_INCLUDES
        ${LABSOUND_DIR}/include
        ${LABSOUND_DIR}/src
    )
else()
    # Try to find installed LabSound
    find_package(LabSound QUIET)
    
    if(LabSound_FOUND)
        message(STATUS "Found installed LabSound")
    else()
        # If not found, use a specific location or fetch it
        if(NOT DEFINED LABSOUND_DIR)
            message(STATUS "LabSound not found. Downloading...")
            execute_process(
                COMMAND git clone --depth 1 https://github.com/LabSound/LabSound.git third_party/LabSound
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            )
            set(LABSOUND_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/LabSound")
            set(LABSOUND_BUILD_EXAMPLES OFF CACHE BOOL "Build LabSound examples")
            set(LABSOUND_BUILD_TESTS OFF CACHE BOOL "Build LabSound tests")
            add_subdirectory(${LABSOUND_DIR})
        else()
            message(STATUS "Using LabSound from: ${LABSOUND_DIR}")
        endif()
        
        set(LABSOUND_INCLUDES
            ${LABSOUND_DIR}/include
            ${LABSOUND_DIR}/src
        )
    endif()
endif()

# Include LabSound headers
include_directories(${LABSOUND_INCLUDES})

# Define the extension module
nanobind_add_module(
    _core                                  # Module name
    src/core.cpp                           # Main binding file
    src/audio_context.cpp                  # AudioContext bindings
    src/audio_node.cpp                     # AudioNode base class bindings
    src/audio_param.cpp                    # AudioParam bindings
    src/nodes/oscillator_node.cpp          # OscillatorNode bindings
    src/nodes/gain_node.cpp                # GainNode bindings
    src/nodes/biquad_filter_node.cpp       # BiquadFilterNode bindings
    src/nodes/buffer_source_node.cpp       # BufferSourceNode bindings
    src/nodes/analyzer_node.cpp            # AnalyzerNode bindings
    src/nodes/function_node.cpp            # FunctionNode bindings
    src/nodes/destination_node.cpp         # DestinationNode bindings
    src/nodes/channel_merger_node.cpp      # ChannelMergerNode bindings
    src/nodes/channel_splitter_node.cpp    # ChannelSplitterNode bindings
    src/nodes/constant_source_node.cpp     # ConstantSourceNode bindings
    src/nodes/convolver_node.cpp           # ConvolverNode bindings
    src/nodes/delay_node.cpp               # DelayNode bindings
    src/nodes/dynamics_compressor_node.cpp # DynamicsCompressorNode bindings
    src/nodes/panner_node.cpp              # PannerNode bindings
    src/nodes/stereo_panner_node.cpp       # StereoPannerNode bindings
    src/nodes/wave_shaper_node.cpp         # WaveShaperNode bindings
)

target_include_directories(_core PRIVATE 
    ${LABSOUND_INCLUDES}
    ${Python_INCLUDE_DIRS}
    src
)

# Link against LabSound
if(LabSound_FOUND)
    # Use modern CMake target
    target_link_libraries(_core PRIVATE LabSound::LabSound)
else()
    # Link against LabSound libraries directly
    if(APPLE)
        target_link_libraries(_core PRIVATE 
            ${LABSOUND_DIR}/build/bin/LabSound.framework/Versions/A/LabSound
            ${LABSOUND_DIR}/build/bin/libLabSoundMiniAudio.a
            ${LABSOUND_DIR}/build/bin/libLabSoundRtAudio.a
            ${LABSOUND_DIR}/build/third_party/libnyquist/lib/liblibnyquist.a
        )
    else()
        # For Linux and Windows, adjust paths as needed
        target_link_libraries(_core PRIVATE LabSound)
    endif()
endif()

# Install the extension module
install(TARGETS _core DESTINATION labsound)
