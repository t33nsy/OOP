#include "../headers/FileHandler.h"

FileHandler::FileHandler(std::string filename, FileType type) {
  if (type == FileType::READ) {
    input_ = std::ifstream(filename);
  } else {
    output_ = std::ofstream(filename);
  }
}

FileHandler::~FileHandler() {
  if (input_.is_open()) {
    input_.close();
  }
  if (output_.is_open()) {
    output_.close();
  }
}

auto FileHandler::ReadState(GameState& state) -> void {
  if (input_.is_open()) {
    input_ >> state;
  } else {
    throw "File not found";
  }
}
auto FileHandler::WriteState(GameState& state) -> void {
  if (output_.is_open()) {
    output_ << state;
  } else {
    throw "File not found";
  }
}

auto FileHandler::GetLine() -> std::string {
  if (input_.eof()) {
    return "";
  }
  std::string line;
  std::getline(input_, line);
  return line;
}
