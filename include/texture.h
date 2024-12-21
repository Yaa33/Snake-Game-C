#ifndef TEXTURE_H
#define TEXTURE_H



typedef struct snake
{
   int flag;
   int lenght;
   SDL_Texture* snake_texture;
   SDL_Rect snake_rect;
   bool turn;

 struct snake* next;
 struct snake* prev;
}snake;



void load_img();

SDL_Surface* return_Head_Surface(int curr_key);
SDL_Surface* return_body_Surface(int curr_key);
SDL_Surface* return_tail_Surface(int curr_key);
SDL_Surface* return_Turn_Surface(int curr_key,int past_key) ;
SDL_Surface* return_apple_surface();
SDL_Surface* return_grass();

void free_surfaces();
void destroy_snake(snake* head);
#endif //  TEXTURE_H