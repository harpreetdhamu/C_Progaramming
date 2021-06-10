OBJ := $(patsubst %.c, %.o, $(wildcard *.c))

bit_wise.exe : $(OBJ)
	gcc -o $@ $^
clean :
	rm *.o *.exe
