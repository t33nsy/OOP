CC = g++ 
OBJS = ./objs/main.o ./objs/ship.o ./objs/shipmanager.o ./objs/gamefield.o ./objs/game.o ./objs/outoffield.o ./objs/collision.o
MAIN_FILES = ./main.cc
MAIN_HEADERS = ./headers/Ship.h ./headers/ShipManager.h ./headers/GameField.h
SHIP_FILES = ./sources/Ship.cc
SHIP_HEADERS = ./headers/Ship.h
SHIPMANAGER_FILES = ./sources/ShipManager.cc
SHIPMANAGER_HEADERS = ./headers/ShipManager.h ./headers/Ship.h ./headers/GameField.h
GAMEFIELD_FILES = ./sources/GameField.cc
GAMEFIELD_HEADERS = ./headers/Ship.h ./headers/GameField.h ./headers/CollisionException.h ./headers/OutOfFieldException.h
GAME_FILES = ./sources/Game.cc
GAME_HEADERS = ./headers/ShipManager.h ./headers/Ship.h ./headers/GameField.h ./headers/Game.h
OUT_OF_FIELD_FILES = ./sources/OutOfFieldException.cc
OUT_OF_FIELD_HEADERS = ./headers/OutOfFieldException.h
COLLISION_FILES = ./sources/CollisionException.cc
COLLISION_HEADERS = ./headers/CollisionException.h

all: main

main: $(OBJS)
	$(CC) $(OBJS) -o main.exe

./objs/main.o: $(MAIN_FILES) $(MAIN_HEADERS)
	$(CC) -c -g $(MAIN_FILES) -o ./objs/main.o

./objs/ship.o: $(SHIP_FILES) $(SHIP_HEADERS)
	$(CC) -c -g $(SHIP_FILES) -o ./objs/ship.o

./objs/shipmanager.o: $(SHIPMANAGER_FILES) $(SHIPMANAGER_HEADERS)
	$(CC) -c -g $(SHIPMANAGER_FILES) -o ./objs/shipmanager.o

./objs/gamefield.o: $(GAMEFIELD_FILES) $(GAMEFIELD_HEADERS)
	$(CC) -c -g $(GAMEFIELD_FILES) -o ./objs/gamefield.o

./objs/game.o : $(GAME_FILES) $(GAME_HEADERS)
	$(CC) -c -g $(GAME_FILES) -o ./objs/game.o

./objs/outoffield.o : $(OUT_OF_FIELD_FILES) $(OUT_OF_FIELD_HEADERS)
	$(CC) -c -g $(OUT_OF_FIELD_FILES) -o ./objs/outoffield.o
	
./objs/collision.o : $(COLLISION_FILES) $(COLLISION_HEADERS)
	$(CC) -c -g $(COLLISION_FILES) -o ./objs/collision.o

clean:
	-del /f /q objs