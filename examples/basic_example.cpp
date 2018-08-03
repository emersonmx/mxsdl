#include <memory>

#include <mxsdl/Core.hpp>
#include <mxsdl/Window.hpp>
#include <mxsdl/Renderer.hpp>

int main() {
    mxsdl::initialize();

    {
        mxsdl::Window window;
        window.create("Basic Example", {800, 600});

        mxsdl::Renderer renderer(window.getContents());
        renderer.create();

        bool running = true;
        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }

            renderer.clear();
            renderer.present();
        }
    }

    mxsdl::finalize();

    return 0;
}
