#all:

#scr=con_producer_consumer.c
scr=sem_philosopher_eatting.c
para=-Wall -g -lpthread

main:$(scr)
	gcc $(scr)  $(para)
	

clean:
	rm  a.out 
	rm  *.o
	#del  *~
	#gcc -o main $(scr)  $(para)
	#scr=mycp_pthread.c
