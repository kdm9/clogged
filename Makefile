CFLAGS += -std=c99 -O3

.PHONY: all clean
all: example

clean:
	rm -f *.o example

example: example.o clogged.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o $@ $^

