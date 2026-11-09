list(APPEND APP_DRAW_SOURCES "AdornG3D.cpp")
list(APPEND APP_DRAW_SOURCES "CMakeLists.txt")
list(APPEND APP_DRAW_SOURCES "Draw.cpp")
list(APPEND APP_DRAW_SOURCES "DrawAdorn.cpp")
list(APPEND APP_DRAW_SOURCES "Fonts.cpp")
list(APPEND APP_DRAW_SOURCES "DrawPrimitives.cpp")
list(APPEND APP_DRAW_SOURCES "HitTest.cpp")
list(APPEND APP_DRAW_SOURCES "Textures.cpp")

add_library(AppDraw STATIC ${APP_DRAW_SOURCES})

target_include_directories(AppDraw PUBLIC
    "include"
    "${CMAKE_SOURCE_DIR}/App/include"
    "${CMAKE_SOURCE_DIR}/Rendering/RenderLib/include"
)

target_link_libraries(AppDraw PUBLIC Boost RbxGraphics G3D GLG3D SDL)
