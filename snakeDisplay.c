#include "snakeDisplay.h"
#include <stdio.h>
#include "util.h"
#include <unistd.h>
#include "map.h"
#include <pthread.h>



void display(Snake snake){
	
	Body body = snake->head;
	while(1){
        if(body == NULL || body->posX < 0)break;
		gotoxy(body->posX,body->posY);
		printf("%c",body->icon);
		fflush(stdout);
		if(body == snake->tail){
		       	break;
		}
		body = body->next;
				
	}
}


void clean(Snake snake){

        Body body = snake->head;
        while(1){
               if(body==NULL||body->posX < 0)break;
               gotoxy(body->posX,body->posY);
               printf("%c",MAP_BLANK);
	           fflush(stdout);
               if(body == snake->tail) break;
	       body = body->next;
        }
}
