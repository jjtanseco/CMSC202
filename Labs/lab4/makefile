CXX = g++
CXXFLAGS = -Wall
lab4: Monster.o
	$(CXX) $(CXXFLAGS) Monster.o lab4.cpp -o lab4
Monster.o: Monster.cpp Monster.h
	$(CXX) $(CXXFLAGS) -c Monster.cpp