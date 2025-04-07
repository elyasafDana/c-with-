
#//elyasafdnana@gmail.com

CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = main

TESTNAME= Test

OBJS = algo.o gragh.o ququ.o main.o Test.o  


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) algo.o gragh.o ququ.o main.o 
	

gragh.o: gragh.cpp graph.h 
	$(CXX) $(CXXFLAGS) -c gragh.cpp -o gragh.o

algo.o: algo.cpp algo.h ququ.h graph.h
	$(CXX) $(CXXFLAGS) -c algo.cpp -o algo.o

ququ.o: ququ.cpp ququ.h graph.h
	$(CXX) $(CXXFLAGS) -c ququ.cpp -o ququ.o

main.o: main.cpp graph.h algo.h ququ.h  
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Test.o: Test.cpp algo.h graph.h ququ.h 
	$(CXX) $(CXXFLAGS) -c Test.cpp -o Test.o

Test: Test.o algo.o gragh.o ququ.o main.o algo.h graph.h ququ.h
	$(CXX) $(CXXFLAGS) -o Test Test.o 
Main: $(TARGET)
	./main

test: Test
	./Test
valgrind: Main
	valgrind --leak-check=full ./main

clean:
	rm -f $(OBJS) $(TARGET) test.o
.PHONY: all clean main valgrind