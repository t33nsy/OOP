#include "../headers/TerminalInputHandler.h"

TerminalHandler::TerminalHandler() {
  try {
    ReadCommands();
  } catch (...) {
    commands_ = default_commands_;
  }
}

auto TerminalHandler::GetCommand() -> CommandType {
  while (!_kbhit()) {
    Sleep(50);
  }
  char c = _getch();
  // std::cout << (int)c<<" ";
  return commands_[c];
}

auto TerminalHandler::ReadCommands() -> void {
  std::string line;
  FileHandler fh(filename_, FileType::READ);
  line = fh.GetLine();
  int num_of_commands = 0;
  while (line != "") {
    std::string temp = line.substr(0, line.find(" "));
    char charnum;
    if (temp.size() > 1) {
      try {
        charnum = static_cast<char>(std::stoi(temp));
      } catch (const std::invalid_argument& ia) {
        throw std::runtime_error("wrong key in controls' set\n");
      }
    } else {
      charnum = temp[0];
    }
    auto it = commands_.find(charnum);
    if (it != commands_.end()) {
      throw std::runtime_error("setting two commands on one key\n");
    }
    temp = line.substr(line.find(" ") + 1);
    if (commands_map_.find(temp) == commands_map_.end()) {
      throw std::runtime_error("wrong control in controls' set\n");
    }
    CommandType curr_command = commands_map_[temp];
    if (used_commands_.find(curr_command) != used_commands_.end()) {
      throw std::runtime_error("setting two keys on one command\n");
    }
    used_commands_.insert(curr_command);
    commands_[charnum] = curr_command;
    line = fh.GetLine();
    ++num_of_commands;
  }
  if (num_of_commands < 15) {
    throw std::runtime_error("not enough commands in controls' set\n");
  }
}