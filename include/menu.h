#ifndef MENU_H
#define MENU_H



typedef enum{
    BUTTON_NORMAL=1,
    BUTTON_HOVERD,
    BUTTON_CLICKED
}Buttonstate;

typedef struct Button{

 SDL_Rect rect;
 const char* label; 
 Buttonstate state;
int num;
}Button;



void main_menu(SDL_Event* event, SDL_Renderer* renderer, int font_size, int *p_key);
int return_pkey(Button* button);
void score_menu(int score);
void present_score(SDL_Renderer* renderer, int *p_key);
#endif //MENU_H