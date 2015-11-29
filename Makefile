CC = g++

all:
	$(CC) main.cpp Load/*.cpp CoordinateClasses/*.cpp Common/*.cpp -lglut -lGL -lGLU -I. -lassimp -o main 

clean:
	rm main