CC = gcc
CFLAG =  -Wall
OBJS = us.o uSonic.o
LDLIBS = -lwiringPi
TARGET = uu

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDLIBS)
	

us.o : us.c
	gcc -c -o us.o us.c 
uSonic.o : uSonic.c
	gcc -c -o uSonic.o uSonic.c

clear : 
	rm -f *.o
