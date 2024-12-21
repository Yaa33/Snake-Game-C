#include"lib.h"



SDL_Rect apple_rect={76,256,CELL_SIZE,CELL_SIZE};
SDL_Texture* apple_tex=NULL;




void render_eve(SDL_Renderer* renderer,snake* head, int key,int past_key,int val_x,int val_y){
    SDL_SetRenderDrawColor(renderer,168,176,52,55);  //168, 176, 52
    snake* curr=head;
    




  
    while(curr!=NULL){
           
   
             updates_flags(renderer ,&curr,Queue,val_x,val_y,past_key, key);           
          
     

       SDL_RenderCopy(renderer,curr->snake_texture,NULL,&curr->snake_rect);
       

      curr=curr->next;
      
    }

    apple_tex=SDL_CreateTextureFromSurface(renderer,return_apple_surface());
  SDL_RenderCopy(renderer,apple_tex,NULL,&apple_rect);
  SDL_DestroyTexture(apple_tex);

}









