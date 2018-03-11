#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>

const int WIDTH = 800, HEIGHT = 600;

/*
    Neste ponto o codigo acompanhou os tutoriais do canal Sonar Systems do youtube até o video 2, que consistem em inicializar a SDL, criar uma janela e terminar o programa quando clicarmos para sair.
    Também faz uso de SDL_image para abrir arquivos .png
 */

/// **************************************************************************************************************************************************************************************************
/// ********************************************************************      IMPORTANTE      ********************************************************************************************************
/// ************************                                                                                                                                                 *************************
/// ************************ os arquivos de imagem a serem carregados deve estar na mesma pasta que o output (Products/SDL_again) no caso, ou deve ter seu caminho completo. *************************
/// ************************                                                                                                                                                 *************************
/// **************************************************************************************************************************************************************************************************

int main (int agrc, char *argv[]){
    
    
    SDL_Surface *imgSurface = NULL;
    SDL_Surface *windowSurface = NULL;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    windowSurface = SDL_GetWindowSurface(window);
    
    if (NULL == window) {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "Could not initialize SDL_image SDL Error: " << IMG_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    
    SDL_Event windowEvent;
    
    imgSurface = IMG_Load("helloworld.png");
    
    if (imgSurface == NULL){
        std::cout << "SDL could not load image! SDL Error: " << SDL_GetError() << std::endl;
    }
    
    while (true){
        if (SDL_PollEvent(&windowEvent)){
            if ( SDL_QUIT == windowEvent.type){
                break;
            }
        }
        
        SDL_BlitSurface(imgSurface, NULL, windowSurface, NULL);
        SDL_UpdateWindowSurface(window);
    }
    
    SDL_FreeSurface(imgSurface);
    SDL_FreeSurface(windowSurface);
    
    imgSurface = NULL;
    windowSurface = NULL;
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
