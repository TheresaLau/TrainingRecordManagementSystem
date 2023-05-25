#include "TraineeLinkedList.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

TraineeLinkedList::TraineeLinkedList(){
	head = NULL;
}

TraineeLinkedList::TraineeLinkedList(Node* n){
	head = n;
}
Node* TraineeLinkedList::nodeExists(string id){
	Node * temp = NULL;
	Node * ptr = new Node;
	ptr = head;
	
	while (ptr != NULL){
		if(ptr->TE_ID == id){
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}

//Insert the new information of Trainee (Registration for Trainee)
void TraineeLinkedList::InsertNode(Node *n){
	Node * ptr1 = new Node;
	ptr1 = NULL;
	ptr1 = nodeExists(n->TE_ID);
	
	if (ptr1 == NULL){
		Node *curr = head;
		Node *prev = NULL;
		
		while (curr && n->TE_ID > curr->TE_ID){
			prev = curr;
			curr = curr->next;
		}
		
		Node *newnode = new Node;
		newnode = n;
		
		if (prev == NULL){
			newnode->next = head;
			head = newnode;
		}
		else {
			newnode->next = prev->next;
			prev->next = newnode;
		}
	}
	
	else{
		cout << n->TE_ID << " is exist in menu. Insertion failed." << endl;
	}
}

//Delete the chosen trainee information
void TraineeLinkedList::deleteNode(string id){
	if (head == NULL){
		cout << "No item is available to be deleted from the trainee information record." << endl;
	}
	else if (head != NULL){
		if(head->TE_ID == id){
			Node*tempNod = new Node;
			tempNod = head;
			head = head->next;
			cout << tempNod->TE_name << " with the ID of " << tempNod->TE_ID << " is deleted." << endl;
			delete tempNod;
		}
		else{
			Node *temp = NULL;
			Node * prevptr = head;
			Node * currentptr = head->next;
			
			while (currentptr != NULL){
				if(currentptr->TE_ID == id){
					temp = currentptr;
					currentptr = NULL;
				}
				else{
					prevptr = prevptr->next;
					currentptr = currentptr->next;
				}
			}
			
			if(temp != NULL){
				prevptr->next = temp->next;
				cout << temp->TE_name << " with the code of "<< temp->TE_ID << " is deleted." << endl;
				delete temp; 
			}
			else{
				cout << "The trainee ID entered is invalid" << endl;
			}
		}
	}
}

//Update the plan and trainer for trainee
void TraineeLinkedList::updateNode(string id,string plan, string trainer){
	Node* ptr = nodeExists(id);
	if ( ptr != NULL){
		ptr->TE_plan = plan;
		ptr->TE_Trainer = trainer;
		cout << "Personal information for " << id << " is updated successfully." << endl;
	}
	else{
		cout << id << " is invalid." << endl;
	}
}

//Display the trainee information
void TraineeLinkedList::printList(){
	if(head == NULL){
		cout << "The trainee information is empty.";
	}
	else{
		Node* temp = head->next;
		cout << "\nTrainee's Information" << endl;
    	cout << "****************************************************" << endl;
    	while(temp != NULL){
			cout << "\nName           : " << temp->TE_name << endl;
    		cout << "ID             : " << temp->TE_ID << endl;
    		cout << "Gender         : " << temp->TE_gender << endl;
    		cout << "Age            : " << temp->TE_age << endl;
    		cout << "Phone Number   : " << temp->TE_hp << endl;
   			cout << "Email          : " << temp->TE_email << endl;
    		cout << "Address        : " << temp->TE_address << endl;
    		cout << "Weight (kg)    : " << temp->TE_weight << endl;
    		cout << "Height (m)     : " << temp->TE_height << endl;
    		cout << "Plan no        : " << temp->TE_plan << endl;
			cout << "Trainer        : " << temp->TE_Trainer << endl;
			temp = temp->next;
		}
	}
}

//Update Trainee Information in data file
void TraineeLinkedList::updatefile(fstream &infile){
	infile.open("Trainee.txt",ios::out);
	Node* temp = head->next;
	while (temp != NULL){
		infile << temp->TE_ID << "\t" 
			   << temp->TE_name << "\t"
			   << temp->TE_gender << "\t"
			   << temp->TE_age << "\t"
			   << temp->TE_hp << "\t"
			   << temp->TE_email << "\t"
			   << temp->TE_address <<"\t"
			   << temp->TE_weight << "\t"
			   << temp->TE_height << "\t"
			   << temp->TE_plan << "\t"
			   << temp->TE_Trainer << "\n";
		temp = temp->next;
	}
	infile.close();
}
