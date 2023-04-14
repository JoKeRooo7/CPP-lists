G++ = g++ -Wall -Werror -Werror

all: static_lib_STACK dynamic_lib_STACK

libclean:
	rm -rf libs/*

static_lib_STACK: 
	$(G++) -c  STACK/stack.cpp -o stack.o
	ar rc libs/libstack.a stack.o
	rm -rf stack.o

dynamic_lib_STACK:
	$(G++) -c -fPIC STACK/stack.cpp -o stack.o
	g++ -shared -o libs/libstack.so stack.o
	rm -rf stack.o
