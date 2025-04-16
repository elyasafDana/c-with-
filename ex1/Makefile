
#//elyasafdnana@gmail.com

CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = main

TESTNAME= Test

OBJS = algo.o graph.o ququ.o main.o   


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) algo.o graph.o ququ.o main.o 
	

graph.o: graph.cpp graph.h 
	$(CXX) $(CXXFLAGS) -c graph.cpp -o graph.o

algo.o: algo.cpp algo.h ququ.h graph.h
	$(CXX) $(CXXFLAGS) -c algo.cpp -o algo.o

ququ.o: ququ.cpp ququ.h graph.h
	$(CXX) $(CXXFLAGS) -c ququ.cpp -o ququ.o

main.o: main.cpp graph.h algo.h ququ.h  
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o



Test: Test.o algo.o graph.o ququ.o 
	$(CXX) $(CXXFLAGS) algo.cpp graph.cpp ququ.cpp Test.cpp -o Test 
Main: $(TARGET)
	./main

test: Test
	./Test
valgrind: Main
	valgrind --leak-check=full ./main

clean:
	rm -f $(OBJS) $(TARGET) Test.o Test
.PHONY: all clean main valgrind