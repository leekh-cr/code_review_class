// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	cursor = new Node(CUR_CHAR);
	typed_count = 0;
  return;
}

void TypingMachine::HomeKey() {
	while (cursor->GetPreviousNode()) LeftKey();
  return;
}

void TypingMachine::EndKey() {
	while (cursor->GetNextNode()) RightKey();
  return;
}

void TypingMachine::LeftKey() {
	if (cursor->GetPreviousNode())
	{
		cursor->InsertNextNode(cursor->GetPreviousNode()->GetData());
		cursor->ErasePreviousNode();
	}
  return;
}

void TypingMachine::RightKey() {
	if (cursor->GetNextNode())
	{
		cursor->InsertPreviousNode(cursor->GetNextNode()->GetData());
		cursor->EraseNextNode();
	}
  return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 0x20 || key > 0x7E || typed_count == MAX_TYPE_LENGTH) return false;
	
	cursor->InsertPreviousNode(key);
	typed_count++;

	return true;
}

bool TypingMachine::EraseKey() {
	if (cursor->GetPreviousNode() == nullptr || typed_count == 0) return false;

	cursor->ErasePreviousNode();
	typed_count--;

	return true;
}

std::string TypingMachine::Print(char separator) {
	Node* it = cursor;
	std::string typed_string = "";
	while (it->GetPreviousNode()) it = it->GetPreviousNode();

	while(it)
	{
		if (it->GetData() == CUR_CHAR)
		{
			if (separator == '\0'); 
			else typed_string += separator;
		}
		else
		{
			typed_string += it->GetData();
		}

		it = it->GetNextNode();
	}
	return typed_string;
}
