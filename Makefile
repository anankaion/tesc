output: main.o split_string.o
	g++ main.o split_string.o -o output

main.o: main.cpp
	g++ -c main.cpp

split_string.o: split_string.cpp split_string.h
	g++ -c split_string.cpp

clean:
	rm *.o output
