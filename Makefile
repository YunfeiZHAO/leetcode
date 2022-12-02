CXX = g++
CXXFLAGS = -std=c++11 -Wall


file = /Users/yunfei/Desktop/leetcode/queue/215_kth_largest_element_in_an_array.cpp
all: compile run clean

compile: ${file}
	@${CXX} -std=c++11 -o bin/exe ${file}

run: bin/exe
	@./bin/exe

clean:
	@rm bin/exe
