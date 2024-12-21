#include"lib.h"








int Key_Event(SDL_Keycode current_key){


  int val=0;
 

   switch (current_key)
   {
  
   case SDLK_UP:val=1;break;
    case SDLK_RIGHT:val=2;break;
     case SDLK_DOWN:val=3;break;
     case SDLK_LEFT:val=4;break;
   
    default: val=0;break; 


   } 


 return val;

} 


int key_past_event(SDL_Keycode past_key){
    int val=0;
    switch (past_key)
   {
   case SDLK_UP:
        val=1;
    break;
    case SDLK_RIGHT:
        val=2;
    break;
     case SDLK_DOWN:
        val=3;
    break;
     case SDLK_LEFT:
        val=4;
    break;
    default: 
        val=0;
        break; 


   }
   return val;   
    
}