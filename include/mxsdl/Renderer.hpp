#ifndef MXSDL_RENDERER_HPP_
#define MXSDL_RENDERER_HPP_

#include <memory>

#include <SDL2/SDL_render.h>

#include <mxg/Vector2.hpp>
#include <mxg/Color.hpp>
#include <mxsdl/Texture.hpp>
#include <mxsdl/Window.hpp>

namespace mxsdl {

struct SDLRendererDeleter {
    void operator()(SDL_Renderer* renderer) {
        SDL_DestroyRenderer(renderer);
    }
};

using SDLRendererPtr = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>;

class Renderer {
public:
    Renderer(const Window& window);
    Renderer(SDL_Window* window);
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    mxg::Color getClearColor() const;
    void setClearColor(const mxg::Color& color);
    SDL_Renderer* getContents() const;

    void create();
    void destroy();

    void clear();
    void clear(const mxg::Color& color);
    void render(const Texture& texture, const mxg::Vector2& position);
    void render(const Texture& texture,
                const mxg::Vector2& position,
                const float angle,
                const mxg::Vector2& scale,
                const mxg::Vector2& center);
    void present();

private:
    SDL_Window* window_{};
    SDLRendererPtr renderer_{};
};

} /* namespace mxsdl */
#endif /* MXSDL_RENDERER_HPP_ */
