cmake_minimum_required(VERSION 3.28)
project(Sea_battle)

set(CMAKE_CXX_STANDARD 17)

add_executable(
              Sea_battle 
              main.cc
              headers/CollisionException.h
              headers/DoubleDamage.h
              headers/GameField.h
              headers/NoSkillsException.h
              headers/OutOfFieldException.h
              headers/RandomShot.h
              headers/Scanner.h
              headers/Ship.h
              headers/ShipKilled.h
              headers/ShipManager.h
              headers/Skill.h
              headers/SkillManager.h
              headers/Game.h
              headers/GameState.h
              headers/ComputerEnemy.h
              headers/GameController.h
              headers/TerminalInputHandler.h
              headers/Tracker.h
              headers/TerminalField.h
              headers/GameRenderer.h
              headers/FileHandler.h

              sources/CollisionException.cc
              sources/DoubleDamage.cc
              sources/GameField.cc
              sources/NoSkillsException.cc
              sources/OutOfFieldException.cc
              sources/RandomShot.cc
              sources/Scanner.cc
              sources/Ship.cc
              sources/ShipKilled.cc
              sources/ShipManager.cc
              sources/Skill.cc
              sources/SkillManager.cc
              sources/Game.cc
              sources/GameState.cc
              sources/ComputerEnemy.cc
              sources/TerminalInputHandler.cc
              sources/Tracker.cc
              sources/TerminalField.cc
              sources/FileHandler.cc
              )