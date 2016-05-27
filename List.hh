/*****************************************************************
Jeremy Salant
cs435
Semester Project Part 1
3/31/2014

List.hh
- holds listADTs function declarations
*****************************************************************/

#include "DLLNode.hh"

class List{
	public:
		//Return rightmost node of dll
		DLLNode GET_LAST();
		//Return leftmost node of dll
		DLLNode GET_FIRST();
		//Return node to right of N
		DLLNode NEXT_RIGHT(DLLNode);
		//Return node to left of N
		DLLNode NEXT_LEFT(DLLNode);
		//Insert value v as node in rightmost position
		void INSERT_RIGHT(int);
		//Insert value v as node in leftmostt position
		void INSERT_LEFT(int);
		//Determine if node N is leftmost node
		bool IS_FIRST(DLLNode);
		//Determine if node N is rightmost node
		bool IS_LAST(DLLNode);
};
