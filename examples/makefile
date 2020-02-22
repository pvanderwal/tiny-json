
CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

src = $(wildcard *.c)
src += $(wildcard ../*.c)
obj = $(src:.c=.o)
dep = $(obj:.o=.d) 

.PHONY: build all clean

build: example

all: clean build

clean::
	rm -rf $(dep)
	rm -rf $(obj)
	rm example

	
example: example.o ../tiny-jsonPath.o
	gcc $(CFLAGS) -o $@ $^

-include $(dep)

%.d: %.c
	$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@
