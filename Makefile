CC = g++
UNAME_S := $(shell uname -s)

all:

ifeq ($(UNAME_S),Darwin)
	$(CC) -framework OpenGL -framework GLUT -Wno-deprecated -I main.cpp Load/*.cpp CoordinateClasses/*.cpp Common/*.cpp -o main 	
endif
ifeq ($(UNAME_S),Linux)
	$(CC) main.cpp Load/*.cpp CoordinateClasses/*.cpp Common/*.cpp -lglut -lGL -lGLU -I. -lassimp -o main
endif	

clean:
	rm main