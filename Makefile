all: cube

WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
LIBS = -lm -lGL -lGLU `sdl-config --libs`

cube: Makefile cube.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) $(LIBS) cube.c

clean:
	rm -f cube

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	./cube

