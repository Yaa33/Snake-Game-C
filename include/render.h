
#ifndef RENDER_H
#define RENDER_H
typedef struct snake snake;

extern SDL_Rect apple_rect;
extern SDL_Texture* apple_tex;

void Render_snake(SDL_Renderer* renderer,snake* head,snake* tail,snake* body);
void render_eve(SDL_Renderer* renderer,snake* head,int key,int past_key,int val_x,int val_y);
void update_the_flag(snake* head,int val_x,int val_y,int key,int past_key);

void update_the_flag2(snake* head, int val_x, int val_y, int key, int past_key);


#endif // RENDER_H