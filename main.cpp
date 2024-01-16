#define SDL_MAIN_HANDLED
#define WINUSERAPI

#include <SDL2/SDL.h>
#include <iostream>
#include <Windows.h>
#include "player.hpp"

SDL_Window* window = 0;
SDL_Renderer* renderer = 0;

bool pe = true;
bool run = true;


int main(int argc, char* args[]){
    SystemParametersInfo(SPI_SETKEYBOARDDELAY,0,0,0);

   if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        window = SDL_CreateWindow("hola",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,540,SDL_WINDOW_SHOWN);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
  
    pl::Player player(SDL_Event(),renderer);
    pl::Player player1(SDL_Event(),renderer);
    SDL_Event ev;
    while(run){

        while(SDL_PollEvent(&ev) != 0){
            if(ev.type == SDL_QUIT){
                run = false;
            }

        player.processEvents(ev, pe);
        }

        player1.update();
        player.update();

        SDL_RenderClear(renderer);
        
        player.render();
        player1.render();

        SDL_RenderPresent(renderer);

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        
    }
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;

}

