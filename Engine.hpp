#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace ba{
    class Engine{
        public:
            void TextScreen(SDL_Color colorT,const std::string& Text,SDL_Renderer* render,TTF_Font* font){
                if(TTF_Init() == -1){
                    return;
                }   
                colorT = {255,255,255};
                SDL_Surface* textS = TTF_RenderText_Solid(font,Text.c_str(),colorT);
                SDL_Texture* textT =    SDL_CreateTextureFromSurface(render,textS);

                SDL_FreeSurface(textS);

                SDL_Rect destRect = {10,10,textS->w,textS->h};
                SDL_RenderCopy(render,textT,nullptr,&destRect);

                SDL_RenderPresent(render);
            
            }
            void quit_TextScreen(TTF_Font* font){
                TTF_CloseFont(font);
                TTF_Quit();
                SDL_Quit();
            }
        private:
            
            

    };
}