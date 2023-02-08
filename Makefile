CXX = g++
CXXFLAGS = -std=c++11 -Wall


file = /Users/yunfei/Desktop/leetcode/heap/621_task_scheduler.cpp
all: compile run clean

compile: ${file}
	@${CXX} -std=c++11 -o bin/exe ${file}

run: bin/exe
	@./bin/exe

clean:
	@rm bin/exe
