MAKEFLAGS += -j8
CC = g++ 
OBJS = ./objs/main.o ./objs/ship.o ./objs/shipmanager.o ./objs/gamefield.o ./objs/game.o ./objs/skill.o ./objs/doubledamage.o ./objs/scanner.o ./objs/randomshot.o ./objs/skillmanager.o ./objs/outoffield.o ./objs/collision.o ./objs/empty.o ./objs/shipkilled.o
MAIN_FILES = ./main.cc
MAIN_HEADERS = ./headers/TempGame.h
SHIP_FILES = ./sources/Ship.cc
SHIP_HEADERS = ./headers/Ship.h ./headers/ShipKilled.h
SHIPMANAGER_FILES = ./sources/ShipManager.cc
SHIPMANAGER_HEADERS = ./headers/ShipManager.h ./headers/Ship.h ./headers/GameField.h
GAMEFIELD_FILES = ./sources/GameField.cc
GAMEFIELD_HEADERS = ./headers/Ship.h ./headers/GameField.h ./headers/CollisionException.h ./headers/OutOfFieldException.h
GAME_FILES = ./sources/TempGame.cc
GAME_HEADERS = ./headers/ShipManager.h ./headers/Ship.h ./headers/GameField.h ./headers/Game.h ./headers/SkillManager.h
OUT_OF_FIELD_FILES = ./sources/OutOfFieldException.cc
OUT_OF_FIELD_HEADERS = ./headers/OutOfFieldException.h
COLLISION_FILES = ./sources/CollisionException.cc
COLLISION_HEADERS = ./headers/CollisionException.h
EMPTY_SKILLS_FILES = ./sources/NoSkillsException.cc
EMPTY_SKILLS_HEADERS = ./headers/NoSkillsException.h
SHIP_KILLED_FILES = ./sources/ShipKilled.cc
SHIP_KILLED_HEADERS = ./headers/ShipKilled.h
SKILL_FILES = ./sources/Skill.cc
SKILL_HEADERS = ./headers/Skill.h
DOUBLE_DAMAGE_FILES = ./sources/DoubleDamage.cc
DOUBLE_DAMAGE_HEADERS = ./headers/DoubleDamage.h
SCANNER_FILES = ./sources/Scanner.cc
SCANNER_HEADERS = ./headers/Scanner.h
RANDOM_SHOT_FILES = ./sources/RandomShot.cc
RANDOM_SHOT_HEADERS = ./headers/RandomShot.h
SKILL_MANAGER_FILES = ./sources/SkillManager.cc
SKILL_MANAGER_HEADERS = ./headers/SkillManager.h ./headers/RandomShot.h ./headers/Scanner.h ./headers/DoubleDamage.h ./headers/NoSkillsException.h


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

./objs/skill.o : $(SKILL_FILES) $(SKILL_HEADERS)
	$(CC) -c -g $(SKILL_FILES) -o ./objs/skill.o

./objs/doubledamage.o : $(DOUBLE_DAMAGE_FILES) $(DOUBLE_DAMAGE_HEADERS)
	$(CC) -c -g $(DOUBLE_DAMAGE_FILES) -o ./objs/doubledamage.o

./objs/randomshot.o : $(RANDOM_SHOT_FILES) $(RANDOM_SHOT_HEADERS)
	$(CC) -c -g $(RANDOM_SHOT_FILES) -o ./objs/randomshot.o

./objs/scanner.o : $(SCANNER_FILES) $(SCANNER_HEADERS)
	$(CC) -c -g $(SCANNER_FILES) -o ./objs/scanner.o

./objs/skillmanager.o : $(SKILL_MANAGER_FILES) $(SKILL_MANAGER_HEADERS)
	$(CC) -c -g $(SKILL_MANAGER_FILES) -o ./objs/skillmanager.o

./objs/outoffield.o : $(OUT_OF_FIELD_FILES) $(OUT_OF_FIELD_HEADERS)
	$(CC) -c -g $(OUT_OF_FIELD_FILES) -o ./objs/outoffield.o
	
./objs/collision.o : $(COLLISION_FILES) $(COLLISION_HEADERS)
	$(CC) -c -g $(COLLISION_FILES) -o ./objs/collision.o

./objs/empty.o : $(EMPTY_SKILLS_FILES) $(EMPTY_SKILLS_HEADERS)
	$(CC) -c -g $(EMPTY_SKILLS_FILES) -o ./objs/empty.o

./objs/shipkilled.o: $(SHIP_KILLED_FILES) $(SHIP_KILLED_HEADERS)
	$(CC) -c -g $(SHIP_KILLED_FILES) -o ./objs/shipkilled.o

clean:
	-del /f /q objs main.exe