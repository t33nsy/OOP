#ifndef _t33nsy_FILEHANDLER
#define _t33nsy_FILEHANDLER
#include <fstream>

#include "GameState.h"

enum FileType { READ, WRITE };
class FileHandler {
 public:
  FileHandler(std::string filename, FileType type);
  ~FileHandler();
  auto ReadState(GameState &state) -> void;
  auto WriteState(GameState &state) -> void;
  auto GetLine() -> std::string;

 private:
  std::ifstream input_;
  std::ofstream output_;
};

#endif /* _t33nsy_FILEHANDLER */
