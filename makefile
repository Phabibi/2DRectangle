all: Main

Main: Point2D.h 2DRectangles.h main.cpp 
	g++ -std=c++11 main.cpp  -o  main	
clean:
	rm -f main *.o
