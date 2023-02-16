CXX = g++
CXXFLAGS = -Wall -g -std=c++11
SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.hpp=%.o)
TESTS = test-
CATCH = test/catch/catch.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm *.o

test-all: $(TESTS)

test-:

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
