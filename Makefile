CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -pedantic
LIBS = -lSDL2 -lSDL2_image -lSDL2_net -lcurl
INCLUDE_PATHS = -I/usr/include/SDL2
LIBRARY_PATHS = -L/usr/lib/x86_64-linux-gnu

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = game

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
