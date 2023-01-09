CXX = g++
CXXFLAGS = -Wall -g

proj3: Storage.o Media.o driver.cpp System.o
	$(CXX) $(CXXFLAGS) Storage.o Media.o System.o driver.cpp -o proj3

System.o: System.cpp System.h Storage.o Media.o
	$(CXX) $(CXXFLAGS) -c System.cpp

Storage.o: Storage.cpp Storage.h Media.o
	$(CXX) $(CXXFLAGS) -c Storage.cpp

Media.o: Media.cpp Media.h
	$(CXX) $(CXXFLAGS) -c Media.cpp

clean:
	rm *.o*
	rm *~ 

#Rules to test your projects
run1:
	./proj3 proj3_data1.txt

run2:
	./proj3 proj3_data2.txt

run3:
	./proj3 proj3_data3.txt
