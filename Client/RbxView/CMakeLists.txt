list(APPEND RBXVIEW_SOURCES "BevelMesh.cpp")
list(APPEND RBXVIEW_SOURCES "BrickMesh.cpp")
list(APPEND RBXVIEW_SOURCES "CylinderMesh.cpp")
list(APPEND RBXVIEW_SOURCES "FileMesh.cpp")
list(APPEND RBXVIEW_SOURCES "HeadMesh.cpp")
list(APPEND RBXVIEW_SOURCES "MaterialFactory.cpp")
list(APPEND RBXVIEW_SOURCES "Part.cpp")
list(APPEND RBXVIEW_SOURCES "PBBMesh.cpp")
list(APPEND RBXVIEW_SOURCES "QuadVolume.cpp")
list(APPEND RBXVIEW_SOURCES "SphereMesh.cpp")
list(APPEND RBXVIEW_SOURCES "TorsoMesh.cpp")
list(APPEND RBXVIEW_SOURCES "View.cpp")
list(APPEND RBXVIEW_SOURCES "WedgeMesh.cpp")

add_library(RbxView ${RBXVIEW_SOURCES})
target_include_directories(RbxView
    PUBLIC
        "include"
        "${CMAKE_CURRENT_SOURCE_DIR}/App/include"
)
target_link_libraries(RbxView PUBLIC Boost GLG3D RenderLib RbxGraphics RbxViewBase AppDraw)
