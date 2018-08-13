
CFLAGS += `pkg-config --cflags gtk+-3.0`
LIBS := `pkg-config --libs gtk+-3.0`

all:
	$(CC) example1.c -o example1 $(CFLAGS) ${LIBS}
	$(CC) example2.c -o example2 $(CFLAGS) ${LIBS}

clean:
	-@rm -f example1 example2
