# Variables
TIME =$(LOGPATH)$(shell date)
# Variable objetos
OBJECTS = main.o vertex.o graph.o Framework.o Algorithm.o Chrono.o $(ALGORITHMS)
ALGORITHMS = GreedyAlgorithm.o GraspAlgorithm.o LocalSearchAlgorithm.o
# Flags de compilacion
CFLAGS = -c -std=c++17

max-diversity: $(OBJECTS)
	g++  $(OBJECTS) -o max-diversity
	mv *.o ../objects
	mv max-diversity ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

vertex.o: ../src/vertex.cpp ../include/vertex.hpp
	g++ $(CFLAGS) ../src/vertex.cpp

graph.o: ../src/graph.cpp ../include/graph.hpp
	g++ $(CFLAGS) ../src/graph.cpp

Framework.o: ../src/Framework.cpp ../include/Framework.hpp
	g++ $(CFLAGS) ../src/Framework.cpp

Chrono.o: ../src/Chrono.cpp ../include/Chrono.hpp
	g++ $(CFLAGS) ../src/Chrono.cpp

Algorithm.o: ../src/Algorithm.cpp ../include/Algorithm.hpp
	g++ $(CFLAGS) ../src/Algorithm.cpp

GreedyAlgorithm.o: ../src/GreedyAlgorithm.cpp ../include/GreedyAlgorithm.hpp
	g++ $(CFLAGS) ../src/GreedyAlgorithm.cpp

GraspAlgorithm.o: ../src/GraspAlgorithm.cpp ../include/GraspAlgorithm.hpp
	g++ $(CFLAGS) ../src/GraspAlgorithm.cpp

LocalSearchAlgorithm.o: ../src/LocalSearchAlgorithm.cpp ../include/LocalSearchAlgorithm.hpp
	g++ $(CFLAGS) ../src/LocalSearchAlgorithm.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run1:
	../bin/max-diversity ../inputs/max_div_15_2.txt

run2:
	../bin/max-diversity ../inputs/max_div_15_3.txt

run3:
	../bin/max-diversity ../inputs/max_div_20_2.txt

run4:
	../bin/max-diversity ../inputs/max_div_20_3.txt

run5:
	../bin/max-diversity ../inputs/max_div_30_2.txt

run6:
	../bin/max-diversity ../inputs/max_div_30_3.txt