#include"lib.h"



int main(){


if(SDL_Init(SDL_INIT_EVERYTHING)<0){
    printf("sdl init failed %s:", SDL_GetError());
    return -1;
}


SDL_Window* win=SDL_CreateWindow("snake", 0,0,WIN_WIDTH,WIN_HEIGHT,SDL_WINDOW_SHOWN);


if(!win){
    printf("window creation failed%s:", SDL_GetError());
    return -1;
    SDL_Quit();
}

   SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return -1;
    }


SDL_Event event;
bool runnig=true;
SDL_Keycode current_key=0;
SDL_Keycode past_key=0;
 


 int p_key=0;
 int key=0;
 int pre_key=-1;
 int speed=1;
 int val_x,val_y;
 val_x=val_y=0;
 
 Queue_init(Queue);
snake* head=game_init(renderer);
 if(head==NULL){
  printf("main head is NULL\n");
  exit(1);
 }
while(runnig){

      if(SDL_PollEvent(&event)){
            
           if(event.type==SDL_QUIT){
            runnig=false;
           } 
           if(event.type==SDL_KEYDOWN){

               
           if(p_key==1) {  
            if(event.key.repeat==0){   
                   
               pre_key=key;               
               key=Key_Event(event.key.keysym.sym);
           
                val_x=return_x(head,key);
                val_y=return_y(head, key);
                    
                 enqueue(Queue,val_x,val_y,pre_key,key);
            } 

           
               
            
          }

                if(event.key.keysym.sym==SDLK_p){
                
                p_key=4;
              }
            
           }
       
         
      }
     
            
     switch (p_key)
     {
     case 0:
        SDL_RenderClear(renderer);
        main_menu(&event,renderer, 100,&p_key);
        SDL_RenderPresent(renderer);
          Queue_init(Queue);
         head=game_init(renderer);
         key=0;
      break;
     case 1:
      SDL_RenderClear(renderer);
      head_movement(renderer,head,key);
      //game_logic(renderer,head,&p_key);    
      game_screen(renderer,head,key);   
      game_logic(renderer,head,&p_key);   
      render_eve(renderer,head,key,pre_key,val_x,val_y);
      SDL_RenderPresent(renderer);
      SDL_Delay(120);
      break;
      case 2:
      SDL_RenderClear(renderer);
      present_score(renderer,&p_key);
      SDL_RenderPresent(renderer);
      SDL_Delay(1000);
      p_key=0;
      break;

      case 3:
      runnig=false;
      
      break;

     default:
      break;
     }    

   

} 
   
  

free_surfaces();
destroy_snake(head);
clear_queue(Queue);
TTF_Quit();
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(win);
SDL_Quit();
    return 0;
}


