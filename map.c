#include <stdio.h>
#include "map.h"
#include <stdlib.h>
#include "util.h"
#include "snake.h"

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

MapEntry getEntry(Map map,int x,int y){
    return map->mapEntrys[y*map->sizeX + x];    
}

void enrichMap(Map map){
	int x,y;
	for(y = 0 ; y < map->sizeY; y++){
		int currentLine = y * map->sizeX;
		for(x = 0 ; x < map->sizeX; x++){
			MapEntry entry = (MapEntry)malloc(sizeof(*entry));
            entry->posX = x;
            entry->posY = y;
            entry->food = NULL;
			if( isBorderLine(map,x,y)){
				entry->icon = MAP_WALL;
			}else{
				entry->icon = MAP_BLANK;
			}
				
			map->mapEntrys[ currentLine + x] = entry;
		}
	}

}

void generateFoodRandom(Map map, int maxX, int maxY){
    int foodX = random(maxX - 3) + 4;
    int foodY = random(maxY - 3) + 4;
    Food newFood = (Food)malloc(sizeof(*newFood));
    newFood->icon = FOOD_ICON;
    MapEntry entry = getEntry(map,foodX,foodY);
    entry->food = newFood;
    gotoxy(foodX,foodY);
    printf("%c",newFood->icon);
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

            /*获取当前位置的Entry，如果当前Entry有Food，则显示Food的图标，否则，显示Entry的图标*/
		    MapEntry entry = getEntry(map,x,y);
            char icon = entry->icon;
            if(entry->food !=NULL){
                icon = entry->food->icon;
            }
			printf("%c",icon);
		}
	}
	fflush(stdout);
}
