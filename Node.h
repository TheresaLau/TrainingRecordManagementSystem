#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node{
	public :
		string TE_ID;
		string TE_name;
		string TE_gender;
		string TE_age;
		string TE_hp;
		string TE_email;
		string TE_address;
		string TE_weight;
		string TE_height;
		string TE_plan;
		string TE_Trainer;
		Node *next;
		
		Node();
		Node(string,string,string,string,string,string,string,string,string,string,string);
};

#endif