/*****************************************************************
Jeremy Salant
cs435
Semester Project Part 1
3/31/2014

DLLNode.hh
- extends the basic node to work with doubly linked lists
*****************************************************************/

#include "Node.hh"

struct DLLNode : public Node{
	DLLNode *next;
	DLLNode *prev;
};
