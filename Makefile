CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic
SRC = $(wildcard src/*.cpp)
OBJDIR = bin
OBJ = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRC))

# all: $(OBJ)
	# @echo "Compile all"
	# $(CC) $(CFLAGS) $(OBJ) -o all

$(OBJDIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	@echo "Compile all"
	$(CC) $(CFLAGS) $(OBJ) -o all

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@echo "Cleaning Up"
	rm -rf $(OBJDIR)
	rm -f all
