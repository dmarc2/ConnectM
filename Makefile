CXX = g++
CXXFLAGS = -Wall -g -std=c++11
SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.hpp=%.o)
TESTS = test-
CATCH = test/catch/catch.o

connectM: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm connectM *.o

test-all: $(TESTS)

test-:

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success
