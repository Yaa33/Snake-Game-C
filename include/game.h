#ifndef GAME_H
#define GAME_H


typedef struct snake snake;
typedef enum {
  MV_UP=1,
 MV_RIGHT,
  MV_DOWN,
  MV_LEFT,
  

}dir;
 

typedef struct Cor{
  int x;
  int y;

}Cor;

typedef struct Queue_cor{
int x;
int y;
int k;
int pk;

}Queue_cor;
#define Max_q 50

extern Queue_cor Queue[Max_q];
extern int front,rear;


snake* game_init(SDL_Renderer* renderer);
void head_movement(SDL_Renderer* renderer,snake* head,int key);

void game_logic(SDL_Renderer* renderer,snake* head, int* p_key);
int return_x(snake* head, int key);
int return_y(snake* head,int  key);

 
 void Queue_init(Queue_cor Queue[Max_q]);
 void enqueue(Queue_cor Queue[Max_q],int val_x, int val_y,int past_key,int key);
 int is_empty(Queue_cor Queue[Max_q]);
 void dequeue(Queue_cor Queue[Max_q]);
 void clear_queue(Queue_cor Queue[Max_q]);
 
void updates_flags(SDL_Renderer* renderer ,snake** curr,Queue_cor Queue[Max_q],int val_x,int val_y,int past_key, int key);

void body_collision(snake* head, int *p_key);
void game_screen(SDL_Renderer* renderer,snake* head,int key);

void score_printed(SDL_Renderer* renderer,snake* head);



#endif // GAME_H