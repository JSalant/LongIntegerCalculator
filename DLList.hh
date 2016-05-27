/*****************************************************************
Jeremy Salant
cs435
Semester Project Part 1
3/31/2014

DLList.hh
- Defines the listADT functions for doubly linked lists
*****************************************************************/

#include "List.hh"
#include <cstddef> //for NULL
#include <iostream> //for testing using cout


class DLList : public List{
	public:
		DLLNode head;
		DLLNode tail;

		DLList(){
			head.next = &tail;
			head.prev = NULL;
			head.value = 0;
			tail.next = NULL;
			tail.prev = &head;
			tail.value = 0;
		}


		//Project step 2 - added destructor
		~DLList(){
			//std::cout << "***** in DLList Destructor ******\n";

			if(head.next == &tail){
				return;
			}

			DLLNode *temp = head.next;

			while(temp->next != NULL){
				temp = temp->next;
				delete temp->prev;
			}

			head.next = &tail;
			head.prev = NULL;
			head.value = 0;
			tail.next = NULL;
			tail.prev = &head;
			tail.value = 0;
		}

		DLLNode GET_LAST(){
			return *this->tail.prev;
		}

		DLLNode GET_FIRST(){
			return *this->head.next;
		}

		DLLNode NEXT_RIGHT(DLLNode N){
			return *N.next;
		}

		DLLNode NEXT_LEFT(DLLNode N){
			return *N.prev;
		}

		void INSERT_RIGHT(int v){
			//create new node to be added to end of list
			DLLNode *temp = new DLLNode();
			//update the previous prev pointer to point to new one
			tail.prev->next = temp;
			//set new nodes value to given value
			temp->value = v;
			//set new nodes prev pointer to what tail points to
			temp->prev = this->tail.prev;
			//set new nodes next pointer to tail
			temp->next = &this->tail;
			//update tail to point to new node
			this->tail.prev = temp;
		}

		void INSERT_LEFT(int v){
			//create new node to be added to beginning of list
			DLLNode *temp = new DLLNode();
			//update node next to head to point to temp through prev
			this->head.next->prev = temp;
			//set new nodes value to given value
			temp->value = v;
			//set new nodes next pointer to what head points to
			temp->next = this->head.next;
			//set new nodes prev pointer to head
			temp->prev = &this->head;
			//update head to point to new node
			this->head.next = temp;
		}

		bool IS_FIRST(DLLNode &N){
			return (N.prev == &this->head);
		}

		bool IS_LAST(DLLNode &N){
			return (N.next == &this->tail);
		}
};
