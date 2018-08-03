#ifndef MXSDL_TEXTURE_HPP_
#define MXSDL_TEXTURE_HPP_

#include <memory>

#include <SDL2/SDL_render.h>

#include <mxg/Size.hpp>

namespace mxsdl {

struct SDLTextureDeleter {
    void operator()(SDL_Texture* texture) {
        SDL_DestroyTexture(texture);
    }
};

using SDLTexturePtr = std::unique_ptr<SDL_Texture, SDLTextureDeleter>;

class Texture {
public:
    Texture(SDL_Texture* texture);

    mxg::Size getSize() const;
    SDL_Texture* getContents() const;

private:
    SDLTexturePtr texture_{};
};

} /* namespace mxsdl */
#endif /* MXSDL_TEXTURE_HPP_ */
