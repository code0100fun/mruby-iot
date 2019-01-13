
set(COMPONENT_SRCDIRS "mruby/src")
set(COMPONENT_ADD_INCLUDEDIRS "mruby/include")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-char-subscripts -Wno-pointer-sign")

register_component()
