#ifndef TRAINEELINKEDLIST_H
#define TRAINEELINKEDLIST_H
#include "Node.h"
using namespace std;

class TraineeLinkedList{
	private :
		Node *head;
	
	public :
		TraineeLinkedList();
		TraineeLinkedList(Node *);
		Node* nodeExists(string);
		void InsertNode(Node *);
		void deleteNode(string);
		void updateNode(string,string,string);
		void printList();
		void updatefile(fstream &);
};

#endif