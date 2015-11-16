all: main 
main: $(patsubst %.cpp,%.o,$(wildcard *.cpp) main.cpp)
	g++ --std=c++11 -Wall -o $@ $^

# a slightly ugly hack to make .o depend on .hpp if it exists
.SECONDEXPANSION:
%.o: %.cpp $$(wildcard $$*.hpp)
	g++ --std=c++11 -Wall -c -o $@ $<

clean:
	rm *.o

