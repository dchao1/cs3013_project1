src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lz -lm

mc2: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) mc2

