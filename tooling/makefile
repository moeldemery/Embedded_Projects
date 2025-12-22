#main.o id a dependency for main.exe

SRCFILES = $(wildcard *.c)
OBJFILES = $(patsubst %.c , %.o , $(SRCFILES))

build:$(OBJFILES)
	gcc $(OBJFILES) -o main.exe
	
# replace %< same as 1st element
# replace %@ with the same name as file

%.o: %.c
	gcc -c %< -o %@
	
clear:
	del /f main.o
	del /f main.exe
########################################################3
#used to test pathing parameters to fn
obj = main.c lib.c

main_object.exe:$(obj)
	gcc $(obj) -o main.exe
	main.exe
	
	
#used to how to depend on other referance
main_dependency.exe:main.o
	gcc main.o -o main.exe
	main.exe
	
main_func.o:
	gcc -c main.c -o main.o
	

