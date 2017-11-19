Demo:Demo.o
	gcc Demo.o -o Demo -lpthread
Demo.o:
	gcc -c Demo.c -o Demo.o 

	
