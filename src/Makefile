G++ = g++ -Wall -Werror -Werror

all: static_lib_STACK dynamic_lib_STACK static_lib_SLL dynamic_lib_SLL

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

static_lib_SLL:
	$(G++) -c  SLL/SLL.cpp -o SLL.o
	ar rc libs/libSLL.a SLL.o
	rm -rf SLL.o

dynamic_lib_SLL:
	$(G++) -c -fPIC SLL/SLL.cpp -o SLL.o
	g++ -shared -o libs/libSLL.so SLL.o
	rm -rf SLL.o