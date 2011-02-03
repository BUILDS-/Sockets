CFLAGS := -g
targets=client
src = $(wildcard *.c)
objs = $(patsubst %.c,%.o,$(src))
client_objs = client.o
libs = -L../lib -ldagame

all: $(targets)
.PHONY: all

client: $(client_objs) ../lib/libdagame.a
	gcc $(CFLAGS) -o client $(client_objs) $(libs)

$(objs) : $(src)

clean:
	rm $(objs) $(targets)
