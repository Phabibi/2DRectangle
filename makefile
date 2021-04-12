all: Main Multiples

Main: Point2D.h 2DRectangles.h main.cpp 
	g++ -std=c++11 main.cpp  -o  main	
Multiples:
	g++ -std=c++11 multiples.cpp  -o  multiples
clean:
	rm -f main multiples *.o
