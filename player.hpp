#pragma once
#include <SDL2/SDL.h>
#include <iostream>

namespace pl{
    class Player{
        public:
            Player(SDL_Event ev,SDL_Renderer* renderer) : renderer(renderer) {
                up = false;
                down = false; 
                rect.h = 50;
                rect.w = 30;
                rect.x = 100;
                rect.y = 100;
                processEvents(ev);
            }

           void processEvents(SDL_Event ev,bool pe){
                if(pe == true){
                    if(ev.type == SDL_KEYDOWN){
                        
                        if(ev.key.keysym.sym == SDLK_w){
                            up = true;
                            down = false;
                        }
                        else if (ev.key.keysym.sym == SDLK_s){
                            down = true;
                            up = false;
                            }
                        else if (ev.key.keysym.sym != SDLK_s && ev.key.keysym.sym != SDLK_w){
                                down = false;
                                up = false;
                            }       
                        }
                        else if(ev.type == SDL_KEYUP){
                            up = false;
                            down = false;
                        }
                   }
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

            void collisionDetect(SDL_Rect col){

            }
        
        private:
            
            SDL_Rect rect;
            bool up;
            bool down;
            bool x;
            SDL_Renderer* renderer;
    };
}