#all:
	#gcc -Wall -g linked_sort.c 
	#./a.out
#clean:
	#rm a.out
src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))
target = main

$(target):$(obj)
	gcc -o $@ -g $^
%.o:%.c
	gcc -o $@ -g -Wall -c $<
clean:
	rm -f $(obj)
	rm -f $(target)
test:
	@echo $(obj)
