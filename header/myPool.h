#ifndef _BODY_POOL_
#define _BODY_POOL_


typedef struct myPoolEntry *MyPoolEntry;

struct myPoolEntry{

	void *entry;
};
typedef struct myPool *MyPool;

struct myPool{
	int size;
	int currentIndex;
	MyPoolEntry *pool;
};



void initBodyPool(MyPool pool, int size);
void initFoodPool(MyPool pool, int size);

void* getPoolEntry(MyPool myPool);

#endif
