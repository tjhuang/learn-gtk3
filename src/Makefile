
CFLAGS += `pkg-config --cflags gtk+-3.0`
LIBS := `pkg-config --libs gtk+-3.0`

TARGET := example1 example2 example3 example4

.PHONY: all

all: $(TARGET)

$(TARGET): %: %.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)

clean:
	-@rm -f example1 example2 example3 example4
