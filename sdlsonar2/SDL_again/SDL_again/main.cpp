#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>

const int WIDTH = 800, HEIGHT = 600;

int main (int agrc, char *argv[]){
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }
    
    SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    
    if (NULL == window) {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    
    SDL_Event windowEvent;
    
    while (true){
        if (SDL_PollEvent(&windowEvent)){
            if ( SDL_QUIT == windowEvent.type){
                break;
            }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
