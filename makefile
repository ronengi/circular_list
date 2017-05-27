a.exe:			main.o  circular_list.o  circular_list_2.o
			cc    -Wall -ansi	main.o  circular_list.o  circular_list_2.o		-o a

circular_list.o:	circular_list.c  circular_list.h
			cc -c -Wall -ansi	circular_list.c			-o circular_list.o

circular_list_2.o:	circular_list_2.c  circular_list.h
			cc -c -Wall -ansi	circular_list_2.c		-o circular_list_2.o

main.o:			main.c  circular_list.h  circular_list_2.h
			cc -c -Wall -ansi	main.c				-o main.o
