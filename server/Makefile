CFLAGS := -g
targets=server
src = $(wildcard *.c)
objs = $(patsubst %.c,%.o,$(src))
server_objs = server.o
libs = -L../lib -ldagame

all: $(targets)
.PHONY: all

server: $(server_objs) ../lib/libdagame.a
	gcc $(CFLAGS) -o server $(server_objs) $(libs)

$(objs) : $(src)

clean:
	rm $(objs) $(targets)

