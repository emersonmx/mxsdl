#ifndef MXSDL_WINDOW_HPP_
#define MXSDL_WINDOW_HPP_

#include <memory>

#include <SDL2/SDL_video.h>

#include <mxg/Size.hpp>

namespace mxsdl {

struct SDLWindowDeleter {
    void operator()(SDL_Window* window) {
        SDL_DestroyWindow(window);
    }
};

using SDLWindowPtr = std::unique_ptr<SDL_Window, SDLWindowDeleter>;

class Window {
public:
    Window() = default;
    Window(SDL_Window* window);

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool isOpen() const;
    std::string getTitle() const;
    mxg::Size getSize() const;
    SDL_Window* getContents() const;

    void create(const std::string& title, const mxg::Size& size);
    void destroy();

private:
    SDLWindowPtr window_{};
};

} /* namespace mxsdl */
#endif /* MXSDL_WINDOW_HPP_ */
