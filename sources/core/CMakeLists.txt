add_library(
    core
    
    "core.hpp"
    "core.cpp"
)

target_link_libraries(core PUBLIC sfml-system sfml-window sfml-network sfml-graphics sfml-audio sfml-main)
