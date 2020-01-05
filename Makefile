# /*
#  * Makefile
#  *
#  * Max Maleno [mmaleno@hmc.edu]
#  *
#  * Created 12/27/2019
#  * Last Updated 12/27/2019
#  *
#  * This is the Makefile for the timer class.
#  *
#  * Build this software using the shell command "make"
#  *
#  */

# widely-used compiler
CXX = clang++

# flags for debugging, extra warnings, and setting C++ version to 17
CXX_FLAGS = -g -std=c++1z -Wall -Wextra -pedantic

# re-link object files if any of them change
timerTest: testing.o timer.o
	$(CXX) -o timerTest testing.o timer.o

# recompile testing script if its implementation or timer header change
testing.o: testing.cpp timer/timer.hpp
	$(CXX) $(CXX_FLAGS) -g -c testing.cpp

# recompile timer.cpp if any dependencies changes
timer.o: timer/timer.cpp timer/timer.hpp
	$(CXX) $(CXX_FLAGS) -g -c timer/timer.cpp

# delete final binary and object files
clean:
	rm -rf timerTest *.o
