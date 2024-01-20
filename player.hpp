#pragma once
#include <SDL2/SDL.h>
#include <iostream>

#include "enemy.hpp"
#include "Engine.hpp"

ba::Engine engine;
SDL_Color color;




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

                TTF_Init();
                TTF_Font* font = TTF_OpenFont("fonts/MulaR-SemiLightItalic.otf",20);
            }

           void processEvents(SDL_Event ev){

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

            void update(){
                x = rect.x;
                y = rect.y;
                if(up == true){
                    rect.y -= 10;
                    
                }
                if(down == true){
                    rect.y += 10;
                }
            }
            
            void render(){
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                SDL_RenderFillRect(renderer,&rect);
            }

            SDL_Rect GetBoundingBox() const{
                return rect;
            }
            
            bool checkCollision(const  SDL_Rect& rect, const SDL_Rect& rect1) const{
                return SDL_HasIntersection(&rect,&rect1) == SDL_TRUE;
            }

            void collisionDetect(const en::Enemy& enemy){
                if(checkCollision(GetBoundingBox(),enemy.GetBoundingBox())){
                    rect.x = x;
                    rect.y = y;
                }
            }
        
        private:
            int x;
            int y;
            SDL_Rect rect;
            bool up;
            bool down;
            bool pe;
            SDL_Renderer* renderer;
            TTF_Font* font = TTF_OpenFont("fonts/MulaR-SemiLightItalic.otf",20);
    };
}