src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lz -lm

mc1: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) mc1

