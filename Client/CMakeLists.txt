cmake_minimum_required(VERSION 3.25)

project(RBXGSDecomp)

# add globally
add_compile_definitions(BOOST_SIGNALS_NO_DEPRECATION_WARNING)

# workarounds for submodules/libraries without cmake files
include("cmake/boost.cmake")
include("cmake/SDL.cmake")

set(G3D_BASE_DIR ${CMAKE_SOURCE_DIR}/Rendering/g3d)

include("cmake/G3D.cmake")
include("cmake/GLG3D.cmake")

add_subdirectory(App)
add_subdirectory(Network)

add_subdirectory(Rendering/AppDraw)
add_subdirectory(Rendering/RenderLib)

add_subdirectory(RbxGraphics)
add_subdirectory(RbxViewBase)
add_subdirectory(RbxView)
