#include <stdio.h>
#include "map.h"
#include <stdlib.h>
#include "util.h"

Map initMap(int sizeX,int sizeY){
	Map map = (Map)malloc(sizeof(*map));
	map->sizeX = sizeX;
	map->sizeY = sizeY;
	MapEntry *entrys = (MapEntry*)malloc(sizeof(*entrys) * sizeX * sizeY);
	map->mapEntrys = entrys;

}

char isBorderLine(Map map,int x, int y){
	if ( (x + 1)  == map->sizeX || x == 0) {
		return 1;
	}else if( (y + 1) == map->sizeY || y == 0) {
		return 1;
	}else{
		return 0;
	}

	

}

void enrichMap(Map map){
	int x,y;
	for(y = 0 ; y < map->sizeY; y++){
		int currentLine = y * map->sizeX;
		for(x = 0 ; x < map->sizeX; x++){
			MapEntry entry = (MapEntry)malloc(sizeof(*entry));
			
			if( isBorderLine(map,x,y)){
				entry->icon = MAP_WALL;
			}else{
				entry->icon = MAP_BLANK;
			}
				
			map->mapEntrys[ currentLine + x] = entry;
		}
	}

}

void printMap(Map map){
	int x,y;
	for(y = 0 ; y < map->sizeY; y++){
		int currentLine = y * map->sizeX;
		for(x = 0 ; x < map->sizeX; x++){
			gotoxy(x+1,y+1);
			if(map->mapEntrys[currentLine+x] == NULL ){
				continue;
			}
					
			printf("%c",map->mapEntrys[currentLine + x]->icon);
		}
	}
	fflush(stdout);
}
