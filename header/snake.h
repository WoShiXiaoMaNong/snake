#ifndef _SNAKE_H_
#define _SNAKE_H_

#define SNAKE_HEAD '@'
#define SNAKE_BODY '*'

#define SNAKE_DIRECTION_UP  1
#define SNAKE_DIRECTION_DOWN  2
#define SNAKE_DIRECTION_LEFT  3
#define SNAKE_DIRECTION_RIGHT  4

#define SNAKE_INIT_POS_X  5
#define SNAKE_INIT_POS_Y  5


typedef struct body *Body;

struct body{
	char posX;
	char posY;
	char icon;
	Body next;
	Body previous;

};

typedef struct snake *Snake;

struct snake{
	Body head;
	Body tail;
	char direction;
};


typedef struct food *Food;
struct food{
	char f;
};


Snake initSnake(int size);

void eat(Snake snake, Food food);

void move(Snake snake);

Body popTail(Snake snake);

void addToHead(Snake snake,Body head);

#endif
