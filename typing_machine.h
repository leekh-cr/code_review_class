// Copyright 2018 <Author>

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"
#define CUR_CHAR 0x10
#define MAX_TYPE_LENGTH 100

class TypingMachine {
 public:
  TypingMachine();
  void HomeKey();
  void EndKey();
  void LeftKey();
  void RightKey();
  bool TypeKey(char key);
  bool EraseKey();
  std::string Print(char separator);

private:
	Node* cursor;
	int typed_count;
};

#endif  // TYPING_MACHINE_H_
