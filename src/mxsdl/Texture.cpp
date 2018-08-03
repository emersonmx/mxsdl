#include <mxsdl/Texture.hpp>

namespace mxsdl {

Texture::Texture(SDL_Texture* texture) : texture_(texture) {}

mxg::Size Texture::getSize() const {
    int width, height;

    SDL_QueryTexture(
        getContents(),
        nullptr, nullptr,
        &width, &height
    );

    return mxg::Size{static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
}

SDL_Texture* Texture::getContents() const {
    return texture_.get();
}

} /* namespace mxsdl */
