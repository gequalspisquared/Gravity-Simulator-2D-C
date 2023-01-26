# To build:
# 	$ make
#
# To compile and run:
# 	$ make run

# define compiler and output name
CXX    := gcc
OUTPUT := game

# manually specify SFML directory
SFML_DIR := .

# compiler and linker flags
CXX_FLAGS := -O3 -std=c89
INCLUDES  := -I./inc
LDFLAGS   := -O3 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm

# the source files for the ecs game engine
SRC_FILES := $(wildcard src/*.c src/**/*.c)
OBJ_FILES := $(SRC_FILES:.c=.o)

# all of these targets will be made if you just type make
all:$(OUTPUT)

# define the main executable requirements / command
$(OUTPUT): $(OBJ_FILES) Makefile
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./bin/$@

# specifies how the object files are compiled from cpp files
.c.o:
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) $< -o $@

# typing 'make clean' will remove all intermediate build files
clean:
	rm -f $(OBJ_FILES) ./bin/$(OUTPUT)

# typing 'make run' will compile and run the program
run: $(OUTPUT)
	cd bin && ./$(OUTPUT) && cd ..