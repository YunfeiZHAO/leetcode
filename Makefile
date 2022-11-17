CXX = g++
CXXFLAGS = -std=c++11 -Wall


file = /Users/yunfei/Desktop/leetcode/linked_list/876_middle_of_the_linked_list.cpp

all: compile run clean

compile: ${file}
	@${CXX} -std=c++11 -o bin/exe ${file}

run: bin/exe
	@./bin/exe

clean:
	@rm bin/exe
