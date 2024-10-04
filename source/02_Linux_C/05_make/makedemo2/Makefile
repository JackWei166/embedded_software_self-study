OBJS = main.o f1.o f2.o
CFLAGS = -c -Wall -g -O

test:$(OBJS)
	gcc $^ -o $@

.PHONY:clean
clean:
	rm *.o test
