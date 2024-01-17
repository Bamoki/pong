#pragma once
#include <SDL2/SDL.h>
#include <iostream>

namespace en{
    class Enemy{
        public:
            Enemy(SDL_Renderer* renderer) : renderer(renderer) {
                up = false;
                down = false;
                rect.h = 50;
                rect.w = 30;
                rect.x = 150;
                rect.y = 150;
            }

           void processEvents(){
                
               }
           
            void update(){
                
            }
            
            void render(){
                SDL_SetRenderDrawColor(renderer,255,0,0,255);
                SDL_RenderFillRect(renderer,&rect);
            }
        
        private:
            SDL_Rect rect;
            bool up;
            bool down;
            bool x;
            SDL_Renderer* renderer;
    };
}