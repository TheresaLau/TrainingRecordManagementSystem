#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(){
		TE_ID = "";
		TE_name = "";
		TE_gender = "";
		TE_age = "";
		TE_hp = "";
		TE_email = "";
		TE_address = "";
		TE_weight = "";
		TE_height = "";
		TE_plan = "";
		TE_Trainer = "";
		next = NULL;
}

Node::Node(string id, string name, string gender, string age, string hp, string email, string address, string weight, string height, string plan, string trainer){
		TE_ID = id;
		TE_name = name;
		TE_gender = gender;
		TE_age = age;
		TE_hp = hp;
		TE_email = email;
		TE_address = address;
		TE_weight = weight;
		TE_height = height;
		TE_plan = plan;
		TE_Trainer = trainer;
}