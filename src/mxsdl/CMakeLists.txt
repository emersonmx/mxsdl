add_library(mxsdl STATIC
    Core.cpp
    Renderer.cpp
    Texture.cpp
    Window.cpp
)

add_dependencies(mxsdl
    mxg
)
