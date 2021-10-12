#ifndef _MAP_H_
#define _MAP_H_
#include "snake.h"
#define MAP_WALL 'O'
#define MAP_BLANK ' '

typedef struct mapEntry* MapEntry;
struct mapEntry{
    char posX;
    char posY;
    char icon;
    Food food;
    char isBorderLine;
};

typedef struct  map* Map;

struct map{
	int sizeX;
	int sizeY;
	MapEntry *mapEntrys; //用一位数组模拟二维数组
};

Map initMap(int sizeX,int sizeY);

void enrichMap(Map map);

void printMap(Map map);

MapEntry getEntry(Map map,int x, int y);

/*用于随机生成实物，0< x < maxX  , 0 < y < maxY*/
void generateFoodRandom(Map map,int maxX,int maxY);

#endif
