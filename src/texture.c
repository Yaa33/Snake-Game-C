#include"lib.h"



SDL_Surface* head_surface[4];
SDL_Surface* body_surface[2];
SDL_Surface* Tail_surface[4];
SDL_Surface* Turn_surface[4];
SDL_Surface* apple_surface;
SDL_Surface* grass_surface;
 SDL_Surface* return_apple_surface(){
    return apple_surface;
 }



void load_img(){

if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0){
    printf("faile img init\n");
    exit(EXIT_FAILURE);
}
const char* head[]={"assets/head_up.png",
"assets/head_right.png",
 "assets/head_down.png",
   "assets/head_left.png" };
const char* tail[]={"assets/tail_down.png",
"assets/tail_left.png",
"assets/tail_up.png",
"assets/tail_right.png"};  

const char* body[]={"assets/body_vertical.png",         
"assets/body_horizontal.png"};
const char* turn[]={"assets/body_bottomright.png",
"assets/body_bottomleft.png","assets/body_topleft.png",       
"assets/body_topright.png"};
apple_surface=IMG_Load("assets/apple.png");

grass_surface=IMG_Load("assets/Grass 12  .png");

for(int i=0; i<4; i++){
 head_surface[i]=IMG_Load(head[i]);
 Tail_surface[i]=IMG_Load(tail[i]);
 Turn_surface[i]=IMG_Load(turn[i]);
 if( head_surface[i]==NULL ||Tail_surface[i]==NULL || Turn_surface[i]==NULL){
    printf("loading image failed%s:",SDL_GetError() );
   exit(EXIT_FAILURE);
 }
}


for(int i=0; i<2; i++){
    body_surface[i]=IMG_Load(body[i]);
    if(body_surface[i]==NULL){
    printf("loading image failed%s:",SDL_GetError() );
    exit(EXIT_FAILURE);
    }
}


}


SDL_Surface* return_Head_Surface(int curr_key){
       switch (curr_key)
{
case 1:
 return head_surface[0];
 
    break;
    case 2:
return head_surface[1];
    break;
    case 3:
return head_surface[2];
     break;
      case 4:
return head_surface[3];
   
     break;
default:
return NULL;
    break;
}

}
SDL_Surface* return_body_Surface(int curr_key){
       switch (curr_key)
{
case 1:
 return body_surface[0];
 
    break;
    case 2:
return body_surface[1];
    break;
    case 3:
return body_surface[0];
     break;
      case 4:
return body_surface[1];
   
     break;
default:
return NULL;
    break;
}

}


SDL_Surface* return_tail_Surface(int curr_key){
       switch (curr_key)
{
case 1:
 return Tail_surface[0];
 
    break;
    case 2:
return Tail_surface[1];
    break;
    case 3:
return Tail_surface[2];
     break;
      case 4:
return Tail_surface[3];
   
     break;
default:
return NULL;
    break;
}
};


SDL_Surface* return_Turn_Surface(int curr_key,int past_key) {
    
    if((curr_key==3 &&past_key==4)||(curr_key==2 && past_key==1)){
   return Turn_surface[0];
}else if((curr_key==4 &&past_key==1)||(curr_key==3 && past_key==2)){
 return Turn_surface[1];
}else if((curr_key==4 &&past_key==3)||(curr_key==1 && past_key==2)){
    return Turn_surface[2];
}else if((curr_key==1 &&past_key==4)||(curr_key==2 && past_key==3)){
    return Turn_surface[3];
}

return NULL;

};

SDL_Surface* return_grass(){
    return grass_surface;
}




void free_surfaces(){
    
    for (int j=0; j<4; j++)
{
      
      
         
    SDL_FreeSurface(head_surface[j]);
    SDL_FreeSurface(Turn_surface[j]);
    SDL_FreeSurface(Tail_surface[j]);
}
  for(int i=0; i<2; i++){
      SDL_FreeSurface(body_surface[i]);
   
  }

  SDL_FreeSurface(apple_surface);
 SDL_FreeSurface(grass_surface);


}



void destroy_snake(snake* head){

   snake* curr=head;

   while(curr!=NULL){
    
   SDL_DestroyTexture(curr->snake_texture);
     snake* next=curr->next;
     free(curr);
    curr=next;
   }


}