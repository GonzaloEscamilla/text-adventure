# Reamember that on windows and with this g++ compiler version to execute the Makefile you use mingw32-make.exe

# Specify the compiler
CC=g++
#LINK=g++

all: adventure clean

adventure: main.o game.o game_settings.o display_tools.o debug.o scene_utils.o tsv_parser.o
	$(CC) main.o game.o game_settings.o display_tools.o debug.o scene_utils.o tsv_parser.o -o adventure

main.o: main.cpp
	$(CC) -c main.cpp

game.o: game.h game.cpp
	$(CC) -c game.h game.cpp

game_settings.o: game_settings.h game_settings.cpp
	$(CC) -c game_settings.h game_settings.cpp

display_tools.o: display_tools.h display_tools.cpp
	$(CC) -c display_tools.h display_tools.cpp

debug.o: debug.h debug.cpp
	$(CC) -c debug.h debug.cpp

scene_utils.o: scene_utils.h scene_utils.cpp
	$(CC) -c scene_utils.h scene_utils.cpp

tsv_parser.o: tsv_parser.h tsv_parser.cpp
	$(CC) -c tsv_parser.h tsv_parser.cpp

clean :
	del *.o