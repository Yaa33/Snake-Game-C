#include"lib.h"


bool out_frame(SDL_Rect screen,SDL_Rect head){

  if(head.x<screen.x ||head.x+head.w>screen.x+screen.w||
     head.y<screen.y || head.y+head.h >screen.y+screen.h){          
    
        
        return true;
  }
  return false;
}


bool collision(SDL_Rect rect1, SDL_Rect rect2){
      
      if(rect1.x+rect1.w >rect2.x && rect1.x<rect2.x+rect2.w 
      && rect1.y+rect1.h>rect2.y && rect1.y<rect2.y+rect2.h ){
        return true;
      }
    

 return false;
}







