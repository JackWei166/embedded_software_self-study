OBJS = main.o f1.o f2.o
CFLAGS = -c -Wall

test:$(OBJS)
	gcc $^ -o $@
main.o:main.c f1.h f2.h
	gcc $(CFLAGS) $< -o $@
f1.o:f1.c f1.h
	gcc $(CFLAGS) $< -o $@
f2.o:f2.c f2.h
	gcc $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	rm *.o test
