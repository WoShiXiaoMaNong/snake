#include <stdlib.h>
#include "myPool.h"
#include <stdio.h>

void initBodyPool(MyPool pool, int size){
	printf("111");
 	pool->size = size;
	pool->currentIndex = 0;
	//pool->pool = (MyPoolEntry*)malloc(sizeof(MyPoolEntry)*size);

	printf("22");
	
}


void* getPoolEntry(MyPool pool){
	if(pool->currentIndex < pool->size){
		void * entry = (pool->pool)[pool->currentIndex];
		pool->currentIndex ++;
		return entry;
	}

	return NULL;

}


