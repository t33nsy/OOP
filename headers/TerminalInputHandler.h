#ifndef _t33nsy_TERMINALHANDLER
#define _t33nsy_TERMINALHANDLER

#include <conio.h>
#include <windows.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#include "FileHandler.h"

enum CommandType {
  START_GAME = 1,           //
  SAVE_GAME = 2,            //
  LOAD_GAME = 3,            //
  START_ROUND = 4,          //
  ADD_SHIP = 5,             //
  QUIT = 6,                 //
  X_DECREASE = 7,           //
  X_INCREASE = 8,           //
  Y_DECREASE = 9,           //
  Y_INCREASE = 10,          //
  CHANGE_ORIENTATION = 11,  //
  ATTACK = 12,              //
  SKILL = 13,               //
  SIZE_INCREASE = 14,       //
  SIZE_DECREASE = 15
};

class TerminalHandler {
 public:
  TerminalHandler();
  auto GetCommand() -> CommandType;
  auto ReadCommands() -> void;

 private:
  std::string filename_ = "../controls.txt";
  std::map<char, CommandType> default_commands_ = {{'w', Y_DECREASE},
                                                   {'W', Y_DECREASE},
                                                   {'s', Y_INCREASE},
                                                   {'S', Y_INCREASE},
                                                   {'a', X_DECREASE},
                                                   {'A', X_DECREASE},
                                                   {'d', X_INCREASE},
                                                   {'D', X_INCREASE},
                                                   {'r', CHANGE_ORIENTATION},
                                                   {'R', CHANGE_ORIENTATION},
                                                   {'z', SAVE_GAME},
                                                   {'Z', SAVE_GAME},
                                                   {'x', LOAD_GAME},
                                                   {'X', LOAD_GAME},
                                                   {'e', ATTACK},
                                                   {'E', ATTACK},
                                                   {'p', ADD_SHIP},
                                                   {'P', ADD_SHIP},
                                                   {'f', START_ROUND},
                                                   {'F', START_ROUND},
                                                   {'q', SKILL},
                                                   {'Q', SKILL},
                                                   {']', SIZE_INCREASE},
                                                   {'[', SIZE_DECREASE},
                                                   {13, START_GAME},
                                                   {27, QUIT}};
  std::map<char, CommandType> commands_ = {};
  std::map<std::string, CommandType> commands_map_ = {
      {"START_GAME", START_GAME},
      {"SAVE_GAME", SAVE_GAME},
      {"LOAD_GAME", LOAD_GAME},
      {"START_ROUND", START_ROUND},
      {"ADD_SHIP", ADD_SHIP},
      {"QUIT", QUIT},
      {"X_DECREASE", X_DECREASE},
      {"X_INCREASE", X_INCREASE},
      {"Y_DECREASE", Y_DECREASE},
      {"Y_INCREASE", Y_INCREASE},
      {"CHANGE_ORIENTATION", CHANGE_ORIENTATION},
      {"ATTACK", ATTACK},
      {"SKILL", SKILL},
      {"SIZE_INCREASE", SIZE_INCREASE},
      {"SIZE_DECREASE", SIZE_DECREASE}};
  std::set<CommandType> used_commands_;
};

#endif /* _t33nsy_TERMINALHANDLER */
