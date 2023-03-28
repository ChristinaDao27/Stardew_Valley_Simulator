CXX = g++
CXXFLAGS = -Wall

proj4: Farm.o AgItem.o Animal.o Vegetable.o Tree.o Fruit.o proj4.cpp
	$(CXX) $(CXXFLAGS) Farm.o AgItem.o Animal.o Vegetable.o Tree.o Fruit.o proj4.cpp -o proj4

AgItem.o: Farm.o Animal.o Vegetable.o Tree.o Fruit.o AgItem.cpp AgItem.h
	$(CXX) $(CXXFLAGS) -c AgItem.cpp

Farm.o: Farm.cpp Farm.h
	$(CXX) $(CXXFLAGS) -c Farm.cpp

Animal.o: Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Vegetable.o: Vegetable.cpp Vegetable.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Tree.o: Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Fruit.o: Fruit.cpp Fruit.h
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

clean:
	rm *.o*
	rm *~

run:
	./proj4

val1:
	valgrind ./proj4
