// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) : m_data(data) {
	prev_node = nullptr;
	next_node = nullptr; 
	return;
}

char Node::GetData() {
	return m_data;
}

Node* Node::GetPreviousNode() {
	if (prev_node) return prev_node;
	return nullptr;
}

Node* Node::GetNextNode() {
	if (next_node) return next_node;
	return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node *temp = new Node(data);
	temp->prev_node = prev_node;
	temp->next_node = this;
	
	if (prev_node){
		prev_node->next_node = temp;
	}
	prev_node = temp;

    return temp;
}

Node* Node::InsertNextNode(char data) {
	Node *temp = new Node(data);
	temp->prev_node = this;
	temp->next_node = next_node;
	
	if (next_node){
		next_node->prev_node = temp;
	}
	next_node = temp;

	return temp;
}

bool Node::ErasePreviousNode() {
	if (prev_node == nullptr) return false;

	Node *temp = prev_node;
	Node *prev_prev_node = prev_node->prev_node;
	prev_node = prev_prev_node;
	
	if (prev_prev_node) prev_prev_node->next_node = this;

	delete temp;
	return true;
}

bool Node::EraseNextNode() {
	if (next_node == nullptr) return false;

	Node *temp = next_node;
	Node *next_next_node = next_node->next_node;
	next_node = next_next_node;

	if (next_next_node) next_next_node->prev_node = this;

	delete temp;
	return true;
}
