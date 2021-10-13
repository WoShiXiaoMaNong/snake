
GCC:=gcc
I:=-I ./header/
MAKE:=make
RM:=rm
MULTI_THREAD:= -lpthread
default:
	${MAKE} image
run:
	${MAKE} image
	./snake
image: snake.o util.o map.o snakeDisplay.o myPool.o
	${GCC} -g -o snake snake.o util.o map.o snakeDisplay.o myPool.o ${MULTI_THREAD}

%.o:%.c makefile
	${GCC} -g -o $*.o -c $*.c ${I} ${MULTI_THREAD}

clean:
	${RM} *.o
