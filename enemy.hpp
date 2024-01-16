#pragma once
#include <SDL2/SDL.h>
#include <iostream>

namespace pl{
    class Player{
        public:
            Player(SDL_Event ev,SDL_Renderer* renderer) : renderer(renderer) {
                up = false;
                down = false; 
                processEvents(ev);
                rect.h = 50;
                rect.w = 30;
                rect.x = 100;
                rect.y = 100;
            }

           void processEvents(SDL_Event ev){
                
                  
                  
               }
           
            void update(){
                if(up == true){
                    rect.y -= 10;
                }
                if(down == true){
                    rect.y += 10;
                }
            }
            
            void render(){
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                SDL_RenderFillRect(renderer,&rect);

                SDL_RenderPresent(renderer);
            }
        
        private:
            
            SDL_Rect rect;
            bool up;
            bool down;
            bool x;
            SDL_Renderer* renderer;
    };
}