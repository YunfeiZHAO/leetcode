CXX = g++
CXXFLAGS = -std=c++11 -Wall


<<<<<<< HEAD
file = /Users/yunfei/Desktop/leetcode/heap/621_task_scheduler.cpp
=======
file = /home/yunfei/workspace/leetcode/string/8_string_to_integer.cpp
>>>>>>> d4aed3c (ok)
all: compile run clean

compile: ${file}
	@${CXX} -std=c++11 -o bin/exe ${file}

run: bin/exe
	@./bin/exe

clean:
	@rm bin/exe
