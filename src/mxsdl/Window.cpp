#include <mxsdl/Window.hpp>

namespace mxsdl {

Window::Window(SDL_Window* window) : window_(window) {}

bool Window::isOpen() const {
    return static_cast<bool>(window_);
}

std::string Window::getTitle() const {
    return SDL_GetWindowTitle(getContents());
}

mxg::Size Window::getSize() const {
    int width{}, height{};
    SDL_GetWindowSize(getContents(), &width, &height);
    return mxg::Size{static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
}

SDL_Window* Window::getContents() const {
    return window_.get();
}

void Window::create(const std::string& title, const mxg::Size& size) {
    window_.reset(
        SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            size.width, size.height,
            SDL_WINDOW_SHOWN
        )
    );
}

void Window::destroy() {
    window_.reset();
}

} /* namespace mxsdl */
