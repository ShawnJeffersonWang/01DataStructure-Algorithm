src = $(wildcard *.cpp)
obj = $(patsubst %.cpp, %, $(src))

myArgs= -Wall -g

ALL:$(obj)

%:%.c
	g++ $< -o $@ $(myArgs)

clean:
	-rm -rf $(obj)

.PHONY: clean ALL
