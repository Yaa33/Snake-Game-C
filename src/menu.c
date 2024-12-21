#include"lib.h"


#define BUTTON_NORMAL 1
#define BUTTON_HOVER 2
#define BUTTON_CLICKED 3






void main_menu(SDL_Event* event, SDL_Renderer* renderer, int font_size, int* p_key) {
    if (TTF_Init() < 0) {
        printf("TTF init failed: %s", SDL_GetError());
        exit(1);
    }

    TTF_Font* arcade_font = TTF_OpenFont("assets/FONTS/ARCADE.TTF", font_size);
    if (arcade_font == NULL) {
        printf("Failed to open font: %s", SDL_GetError());
        exit(1);
    }


    Button arr[3] = {
        {{100, 100, 520, 50}, "START GAME", BUTTON_NORMAL,1},
        {{100, 250, 520, 50}, "BEST SCORE", BUTTON_NORMAL,2},
        {{100, 400, 208, 50}, "QUIT", BUTTON_NORMAL,3},
    };
     
      SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_Surface* text_surface[3];
    SDL_Texture* text_texture[3];
    SDL_Color text_color = {255, 255, 255, 255};  

    int text_width[3], text_height[3];
    SDL_Rect rect;

    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);  
    SDL_Rect mouse_rect = {mouse_x, mouse_y, 1, 1}; 

  
    for (int i = 0; i < 3; i++) {
        Button* button = &arr[i];

    if (collision(mouse_rect,button->rect)) {
            button->state = BUTTON_HOVER;  
        } else {
            if (button->state != BUTTON_CLICKED) {
                button->state = BUTTON_NORMAL; 
            }
        }


    
        if (button->state == BUTTON_NORMAL) {
            text_color = (SDL_Color){255, 255, 255, 255};  
        } else if (button->state == BUTTON_HOVER) {
            text_color = (SDL_Color){0, 255, 0, 255};  
        } 

        
        text_surface[i] = TTF_RenderText_Solid(arcade_font, button->label, text_color);
        text_texture[i] = SDL_CreateTextureFromSurface(renderer, text_surface[i]);
        SDL_QueryTexture(text_texture[i], NULL, NULL, &text_width[i], &text_height[i]);

    
            
        rect.x = button->rect.x + (button->rect.w - text_width[i]) / 2;
        rect.y = button->rect.y + (button->rect.h - text_height[i]) / 2;
        rect.w = text_width[i];
        rect.h = text_height[i];

        SDL_FreeSurface(text_surface[i]);

             SDL_RenderCopy(renderer, text_texture[i], NULL, &rect);



         if (event->type == SDL_MOUSEBUTTONDOWN ) {
     
            if (collision(mouse_rect, button->rect)) {
                button->state = BUTTON_CLICKED; 
                
                   *p_key=(int)return_pkey(button);
         
            }
        } 
       
     
     


     


     
        if (event->type == SDL_MOUSEBUTTONUP && event->button.button == SDL_BUTTON_LEFT) {
           
            if (collision(mouse_rect, button->rect)) {
                button->state = BUTTON_NORMAL; 
            }
        }
    }

 TTF_CloseFont(arcade_font);    
}

int return_pkey(Button* button){
  return button->num;
}



void score_menu(int score){
    FILE* fp=fopen("scores.txt","r+");

    if(fp==NULL){
        printf("failed to open the file\n");

    }
    int curr_score=0;

    if(fscanf(fp,"%d",&curr_score)!=1){
        fseek(fp,0,SEEK_SET);
         fprintf(fp, "%d", curr_score);
    }else if(score>curr_score){
        fseek(fp, 0, SEEK_SET);
        fprintf(fp, "%d", score);
    }

      fclose(fp);
}


void present_score(SDL_Renderer* renderer,int *p_key){
    
    FILE* fp=fopen("scores.txt", "r");
     if(fp==NULL){
        printf("failde open file score\n");
        exit(1);
     }
     TTF_Font* arcade_font=TTF_OpenFont("assets/FONTS/ARCADE.TTF",400);


     if(arcade_font==NULL){
         printf("failde opent font\n");
         exit(1);
     }

   int score=0;
   if(fscanf(fp,"%d",&score)!=1){
        printf("empty txt score\n");
        fclose(fp); 
        TTF_CloseFont(arcade_font);

    }
         
      char str[500];
      snprintf(str,sizeof(str),"%d",score); 
    SDL_Color score_color={255,255,255,255};
     SDL_Surface* score_surface=TTF_RenderText_Solid(arcade_font,str,score_color);

     if(score_surface==NULL){
        printf("faile score surface\n");
        exit(1);
     }

     SDL_Texture* score_texture=SDL_CreateTextureFromSurface(renderer,score_surface);
      if(score_texture==NULL){
        printf("score texture is null\n");
        exit(1);
      }
      int score_w,score_h;
      SDL_QueryTexture(score_texture,NULL,NULL,&score_w,&score_h);
     SDL_Rect score_rect;

     score_rect.w=score_w;
     score_rect.h=score_h;
     score_rect.x=(WIN_WIDTH-score_rect.w)/2;
     score_rect.y=(WIN_HEIGHT-score_rect.h)/2;




     SDL_RenderCopy(renderer,score_texture,NULL,&score_rect);


     fclose(fp);
     
    
 TTF_CloseFont(arcade_font);

  
}