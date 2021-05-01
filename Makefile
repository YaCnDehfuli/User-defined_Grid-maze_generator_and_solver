CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/mid-project.o ./obj/main.o 
# GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) 
./obj/mid-project.o: ./cpp/mid-project.cpp
	$(CXX) $(CXXFLAGS) ./cpp/mid-project.cpp -o ./obj/mid-project.o 
# ./obj/aphw3_unittest.o: ./cpp/aphw3_unittest.cpp
# 	$(CXX) $(CXXFLAGS) ./cpp/aphw3_unittest.cpp -o ./obj/aphw3_unittest.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
