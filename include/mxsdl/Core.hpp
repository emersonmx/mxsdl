#ifndef MXSDL_CORE_HPP_
#define MXSDL_CORE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace mxsdl {

void initialize();
void finalize();

} /* namespace mxsdl */
#endif /* MXSDL_CORE_HPP_ */
