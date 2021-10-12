#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "map.h"
#include "snake.h"
#include "snakeDisplay.h"
#include "util.h"
#include <pthread.h>

#define HIDE_CURSOR() printf("\033[?25l")
#define SHOW_CURSOR() printf("\033[?25h")

void *displaySubThread(void* snake);


int main(int argc, char* argv[]){
	
	
	HIDE_CURSOR();
	int sizeX = 100;
	int sizeY = 60;
	Map map = initMap(sizeX,sizeY);
	enrichMap(map);
	printMap( map);
	Snake snake = initSnake(1);
	pthread_t displayTread;
	pthread_create(&displayTread,NULL, (void*)displaySubThread,snake);
	fflush(stdout);
	char c;
	while(1){
		if(!kbhit()) continue;		
		c = getchar();
		fflush(stdout);
		if(c =='w'){
			snake->direction = SNAKE_DIRECTION_UP;
		}
		if(c =='s'){
			snake->direction = SNAKE_DIRECTION_DOWN;
		}

		if(c =='a'){
			snake->direction = SNAKE_DIRECTION_LEFT;
		}

		if(c =='d'){
			snake->direction = SNAKE_DIRECTION_RIGHT;
		}
	}

	SHOW_CURSOR();
	return 0;
}



void *displaySubThread(void* snake){

	while(1){
		clean(snake);
		move(snake);
		display(snake);
		usleep(150 * 1000);
	}

}


Snake initSnake(int size){
	Snake snake = (Snake) malloc(sizeof(*snake));
	Body head = (Body) malloc(sizeof(*head));
	head->posX = SNAKE_INIT_POS_X;
	head->posY = SNAKE_INIT_POS_Y;
	snake->head = head;
	snake->tail = head;
	
	head->next = head;
	head->previous = head;

	snake->direction = SNAKE_DIRECTION_RIGHT;
	return snake;
}

void eat(Snake snake, Food food){
	Body body = (Body) malloc(sizeof(*body));
	body->posX = -1;
	body->posY = -1;
	snake->tail->next = body;
	body->previous = snake->tail;
	snake->tail = body;

}

void move(Snake snake){
	Body newHead = popTail(snake);
	if(snake->direction == SNAKE_DIRECTION_LEFT){
		newHead->posX = snake->head->posX - 1;
		newHead->posY = snake->head->posY;		
	}else if(snake->direction == SNAKE_DIRECTION_RIGHT){
		newHead->posX = snake->head->posX + 1;
		newHead->posY = snake->head->posY;		
	}else if(snake->direction == SNAKE_DIRECTION_UP){
		newHead->posX = snake->head->posX;
		newHead->posY = snake->head->posY - 1;		
	}else if(snake->direction == SNAKE_DIRECTION_DOWN){
		newHead->posX = snake->head->posX;
		newHead->posY = snake->head->posY + 1;		
	}
	addToHead(snake,newHead);
}



Body popTail(Snake snake){
	
	if(snake->tail == snake->head){
		return snake->tail;
	}

	Body tail = snake->tail;
	Body newTail = tail->previous;
	newTail->next = NULL;
	tail->next = NULL;
	tail->previous = NULL;

	snake->tail = newTail;
	return tail;
}

void addToHead(Snake snake,Body head){
	head->next = snake->head;
	snake->head->previous = head;
	snake->head->icon = SNAKE_BODY;
	head->icon = SNAKE_HEAD;
	snake->head = head;
}

