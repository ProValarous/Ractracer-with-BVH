output: main.o 
	g++ main.o -o output

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2 -lSDL2_image

clean:
	rm *.o output
