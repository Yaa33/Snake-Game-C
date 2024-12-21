#include"lib.h"   

snake* game_init(SDL_Renderer* renderer){
 load_img();
SDL_Rect init_size = {165,225,30,30}; 
snake*head=malloc(sizeof(snake));
 if(head==NULL){
    printf("failed head llocation memory\n");
    exit(EXIT_FAILURE);
 }
 head->snake_rect=init_size;
 head->flag=1;
 head->lenght=0;

 head->snake_texture=SDL_CreateTextureFromSurface(renderer,return_Head_Surface(head->flag));
        if(head->snake_texture==NULL){
        printf("game_init :head texture is NULL\n");
        exit(1);
      
     }
     

 snake* body=malloc(sizeof(snake));
  if(body==NULL){
    printf("failed body allocation in main\n");
    exit(EXIT_FAILURE);
  }
  body->snake_rect=(SDL_Rect){init_size.x, init_size.y+30, 30, 30};
  body->flag=1;
 body->lenght=2;
 body->snake_texture=SDL_CreateTextureFromSurface(renderer,return_body_Surface(body->flag));
     if(body->snake_texture==NULL){
        printf("game_init :body texture is NULL\n");
        exit(1);
      
     }

  snake* tail=malloc(sizeof(snake));
  if(tail==NULL){
    printf("failed tailallocation in main\n");
    exit(EXIT_FAILURE);
  }

  tail->snake_rect=(SDL_Rect){init_size.x, init_size.y+60, 30, 30};
  tail->flag=1;
  tail->lenght=3;
  tail->snake_texture=SDL_CreateTextureFromSurface(renderer,return_tail_Surface(tail->flag));
     
      if(tail->snake_texture==NULL){
        printf("game_init :tail texture is NULL\n");
        exit(1);
      }


  head->next=body;
  head->prev=NULL;
  body->next=tail;
  body->prev=head;
  tail->next=NULL;
  tail->prev=body;


   body->flag=body->prev->flag;
   tail->flag=tail->prev->flag;




return head;

}


void head_movement(SDL_Renderer* renderer,snake* head,int key){
    
    int prev_x = head->snake_rect.x;
    int prev_y = head->snake_rect.y;
   
   





    
    
    switch (key) {
        case 1: // Up
            head->snake_rect.y-=head->snake_rect.h;
            head->snake_rect.x=head->snake_rect.x;
            head->flag=1;
           
            break;
        case 2: // Right
            head->snake_rect.x+=head->snake_rect.w;
            head->snake_rect.y=head->snake_rect.y;
            head->flag=2;
           
            break;
        case 3: // Down
            head->snake_rect.y+=head->snake_rect.h;
            head->snake_rect.x=head->snake_rect.x;
            head->flag=3;
            
            break;
        case 4: // Left
            head->snake_rect.x-=head->snake_rect.w;
            head->snake_rect.y=head->snake_rect.y;
            head->flag=4;
            
            break;
        default:
            return;
    
    }
 head->snake_texture=SDL_CreateTextureFromSurface(renderer,return_Head_Surface(head->flag));
    
    snake* current = head->next; 
        
    while (current != NULL) {
       
         int temp_x = current->snake_rect.x;
        int temp_y = current->snake_rect.y;

 
         
       current->snake_rect.x = prev_x;
       current->snake_rect.y = prev_y;
        
      
       prev_x = temp_x;
       prev_y = temp_y;
        
       
        current = current->next;
        
        
    }



   
}


void add_body(SDL_Renderer* renderer,snake* head){
         snake* temp=head->prev;
        snake* new_body=malloc(sizeof(snake));
         if(new_body==NULL){
            printf("failed allocation for new_body\n");
            exit(1);
         }

         new_body->snake_rect.h=head->snake_rect.h;
         new_body->snake_rect.w=head->snake_rect.w;

  
       
         snake* tail=head;
         while(tail->next!=NULL){
            tail=tail->next;
         }
          
    new_body->snake_rect.x = tail->snake_rect.x;
    new_body->snake_rect.y = tail->snake_rect.y; 
         tail->next=new_body;
         new_body->prev=tail;

         new_body->next=NULL;

        new_body->flag=new_body->prev->flag;
         new_body->snake_texture=SDL_CreateTextureFromSurface(renderer,return_body_Surface(new_body->flag));


}


void game_logic(SDL_Renderer* renderer,snake* head, int* p_key){
          
      if(collision(head->snake_rect,apple_rect)){
        apple_rect.x=rand()% ((SCREEN_WIDTH / CELL_SIZE)) * CELL_SIZE + (WIN_WIDTH-SCREEN_WIDTH)/2;
        apple_rect.y=rand()% ((SCREEN_HEIGHT / CELL_SIZE))* CELL_SIZE + (WIN_HEIGHT - SCREEN_HEIGHT)/2; 
        head->lenght++;
     
        add_body(renderer,head);
         
      } 
    body_collision(head,p_key);
      
  

}

 



int return_x(snake* head, int key){

     if (key == MV_LEFT || key == MV_RIGHT ||key==MV_UP||key==MV_DOWN) {
        return head->snake_rect.x; 
    }
    
return -1;
   
}



int return_y(snake* head, int key){

      if (key == MV_LEFT || key == MV_RIGHT ||key==MV_UP||key==MV_DOWN) {
        return head->snake_rect.y; 
    }
    
return -1;
   
}





//#define Max_q 5

Queue_cor Queue[Max_q];

int front,rear;



void Queue_init(Queue_cor Queue[Max_q]){
    for(int i=0; i<Max_q; i++){
        Queue[i].x=0;
        Queue[i].y=0;
         Queue[i].pk=0;
        Queue[i].k=0;
    }

   front=rear=0;
}

void enqueue(Queue_cor Queue[Max_q],int val_x, int val_y, int past_key,int key){
       
       if((rear+1)%Max_q==front){     
       printf("queue is overflow\n");
       //exit(1);

       }else{
        Queue[rear].x=val_x;
        Queue[rear].y=val_y;
        Queue[rear].pk=past_key;
        Queue[rear].k=key;
        rear=(rear+1)%Max_q; 
    }

}

int is_empty(Queue_cor Queue[Max_q]){
    return rear==front;
}

void dequeue(Queue_cor Queue[Max_q]){

       if(is_empty(Queue)){
         printf("queue is empty\n");
             }

   front=(front+1)%Max_q;
}

void clear_queue(Queue_cor Queue[Max_q]){
    front=rear=0;

}







void updates_flags(SDL_Renderer* renderer ,snake** curr,Queue_cor Queue[Max_q],int val_x,int val_y,int past_key, int key){
     
  
    int turn_found = 0; 

   
   

       
        for (int i = front; i != rear; i = (i + 1) % Max_q) {
            if ((*curr)->snake_rect.x == Queue[i].x && (*curr)->snake_rect.y == Queue[i].y) {
                 
                  
                (*curr)->snake_texture = SDL_CreateTextureFromSurface(renderer, return_Turn_Surface(Queue[i].k, Queue[i].pk));
                (*curr)->flag = (*curr)->prev->flag; 
               turn_found = 1;
                 

               // printf("Turn applied to segment: x=%d, y=%d, k=%d, pk=%d, i=%d\n", Queue[i].x, Queue[i].y, Queue[i].k, Queue[i].pk, i);
                break; 
            }
        }

        if ( !turn_found && (*curr)->prev != NULL) {
                      
            (*curr)->snake_texture = SDL_CreateTextureFromSurface(renderer, return_body_Surface((*curr)->flag));
        }

        if ((*curr)->next == NULL) {
           
            (*curr)->snake_texture = SDL_CreateTextureFromSurface(renderer, return_tail_Surface((*curr)->flag));
            (*curr)->flag=(*curr)->prev->flag;
         
            if ((*curr)->snake_rect.x == Queue[front].x && (*curr)->snake_rect.y == Queue[front].y) {
             dequeue(Queue); 
            }
        }

        
  

}



void body_collision(snake* head,int* p_key){
     
     snake* curr=head->next;

     while(curr!=NULL){
       if(collision(head->snake_rect,curr->snake_rect)){
        score_menu(head->lenght);
      
        *p_key=0;
       }
       
        curr=curr->next;
     }

}


 void game_screen(SDL_Renderer* renderer,snake* head,int key){
      
      
    SDL_Rect rect;
     rect.w=810;
     rect.h=510;
     rect.x=(WIN_WIDTH-rect.w)/2;
     rect.y=(WIN_HEIGHT-rect.h)/2; 
 
          
     SDL_SetRenderDrawColor(renderer,130, 150, 60, 255);   //rgb(172,213,67)   gpt 168, 176, 52, 255
     SDL_RenderFillRect(renderer,&rect); 


     SDL_Surface* grass_surface=return_grass();
            if(grass_surface==NULL){
                printf("failse surface grass %s", SDL_GetError());
               exit(1); 
            }
            

        SDL_Texture* grass_texture=SDL_CreateTextureFromSurface(renderer,grass_surface); 
       
        if(grass_texture==NULL){
            printf("the grass texture is null\n");
             SDL_FreeSurface(grass_surface);
            exit(1);
        }
       
       
       SDL_Rect grass_rect={0,0,30,30};

        int i=0;
     for(int y=rect.y; y<rect.y+rect.h;y+=grass_rect.h ){
        for(int x=rect.x; x<rect.x+rect.w; x+=grass_rect.w){
           i= !i;
           if(i){
            SDL_Rect dest_rect = { x, y, grass_rect.w, grass_rect.h };
            SDL_RenderCopy(renderer,grass_texture,NULL,&dest_rect);
           }
        }
     } 
       
        
       if(out_frame(rect,head->snake_rect)){
        
          switch (key)
          {
          case 1: head->snake_rect.y=rect.y + rect.h - head->snake_rect.h; break;
          case 2:head->snake_rect.x = rect.x; break;
          case 3:head->snake_rect.y=rect.y;break;
          case 4:head->snake_rect.x=rect.x+rect.w- head->snake_rect.w ;break;
        
          default:
            break;
          }

       }

            
        SDL_DestroyTexture(grass_texture); 
                   
 
   score_printed(renderer,head);
 } 


 void score_printed(SDL_Renderer* renderer,snake* head){

    TTF_Font * arcade_font=TTF_OpenFont("assets/FONTS/ARCADE.TTF",40);
          
           if(arcade_font==NULL){
            printf("failde to open font\n");
            exit(1);
           }
         
  char scoretext[50];

  sprintf(scoretext,"Score %d",head->lenght);


 SDL_Color Score_col={255,255,255,255};

  SDL_Surface* score_surface=TTF_RenderText_Solid(arcade_font,scoretext,Score_col);

  SDL_Texture* score_texture=SDL_CreateTextureFromSurface(renderer,score_surface);   

 SDL_FreeSurface(score_surface);
  int score_w,score_h;
  SDL_QueryTexture(score_texture,NULL,NULL,&score_w,&score_h);
         SDL_Rect score_rect;
          score_rect.w=score_w;
          score_rect.h=score_h; 
          score_rect.x=(WIN_WIDTH-score_rect.w)/2;
          score_rect.y=(WIN_HEIGHT-score_rect.h);


        SDL_RenderCopy(renderer,score_texture,NULL,&score_rect); 

SDL_DestroyTexture(score_texture);

          
   
 }





