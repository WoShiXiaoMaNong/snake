#ifndef _MAP_H_
#define _MAP_H_

#define MAP_WALL '☐'
#define MAP_BLANK ' '

typedef struct mapEntry* MapEntry;
struct mapEntry{
	char icon;
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

#endif
