#define SDL_MAIN_HANDLED
#define WINUSERAPI

// include SDL2 y windows
#include <SDL2/SDL.h>
#include <iostream>
#include <Windows.h>
#include <SDL2/SDL_ttf.h>

// include del motor
#include "player.hpp"
#include "enemy.hpp"
#include "Engine.hpp"

// creacion de window y renderer
SDL_Window* window = 0;
SDL_Renderer* renderer = 0;

// variables para el main
bool run = true;
TTF_Font* font = TTF_OpenFont("fonts/MulaR-SemiLightItalic.otf",20);

int main(int argc, char* args[]){
    // quitar el keydelay
    SystemParametersInfo(SPI_SETKEYBOARDDELAY,0,0,0);

    // comprobar que sdl y ttf si carga
   if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        window = SDL_CreateWindow("hola",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,740,540,SDL_WINDOW_SHOWN);
    }

    if(TTF_Init() == -1){
        return 0;
    }
    
    
    TTF_Font* font = TTF_OpenFont("fonts/MulaR-SemiLightItalic.otf",20);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    pl::Player player(SDL_Event(),renderer);
    en::Enemy enemy(renderer);
    ba::Engine engine;

    SDL_Color colorT = {255,255,255};

    std::string h = "hola";
    SDL_Event ev;

    while(run){

        while(SDL_PollEvent(&ev) != 0){
            if(ev.type == SDL_QUIT){
                run = false;
            }

            player.processEvents(ev);
        }


        player.update();
        enemy.update();

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        player.render();
        enemy.render();

        engine.TextScreen(colorT,h,renderer,font);

        SDL_RenderPresent(renderer);
        
    }   
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    engine.quit_TextScreen(font);
    return 0;
}