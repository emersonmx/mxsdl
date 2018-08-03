#include <mxsdl/Renderer.hpp>

namespace mxsdl {

Renderer::Renderer(const Window& window) : window_(window.getContents()) {}

Renderer::Renderer(SDL_Window* window) : window_(window) {}

Renderer::~Renderer() {
    destroy();
}

mxg::Color Renderer::getClearColor() const {
    mxg::Color color;
    SDL_GetRenderDrawColor(
        getContents(),
        &color.red, &color.green, &color.blue, &color.alpha
    );
    return color;
}

void Renderer::setClearColor(const mxg::Color& color) {
    SDL_SetRenderDrawColor(
        getContents(),
        color.red, color.green, color.blue, color.alpha
    );
}

SDL_Renderer* Renderer::getContents() const {
    return renderer_.get();
}


void Renderer::create() {
    Uint32 flags = SDL_RENDERER_ACCELERATED;
    renderer_.reset(
        SDL_CreateRenderer(window_, -1, flags)
    );

    setClearColor({});
}

void Renderer::destroy() {
    renderer_.reset();
}

void Renderer::clear() {
    clear({0, 0, 0, 255});
}

void Renderer::clear(const mxg::Color& color) {
    setClearColor(color);
    SDL_RenderClear(getContents());
}

void Renderer::render(const Texture& texture, const mxg::Vector2& position) {

}

void Renderer::render(const Texture& texture,
                      const mxg::Vector2& position,
                      const float angle,
                      const mxg::Vector2& scale,
                      const mxg::Vector2& center)
{

}

void Renderer::present() {
    SDL_RenderPresent(getContents());
}

} /* namespace mxsdl */
