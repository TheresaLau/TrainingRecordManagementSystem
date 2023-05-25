#include "Plan.h"
#include <iostream>
#include<string>
#include <iomanip>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <fstream>
using namespace std;

void Plan::bubbleSort(float arr[],string p[],int n){
	float tempf=0.0f;
	string temps;
	bool sorted=false;
	
	for(int pass=1;(pass<n) && !sorted; ++pass){
		sorted = true;
			for(int x=0;x<n-pass;++x){
				if(arr[x]>arr[x+1]){
					tempf = arr[x];
					arr[x] = arr[x+1];
					arr[x+1] = tempf;
					
					temps = p[x];
					p[x] = p[x+1];
					p[x+1] = temps;
					sorted = false;
				}
			}
	}
	cout<<"\nList of Plan Offered"<<endl;
    cout<<setw(5)<<left<<"No."
    <<setw(45)<<left<<"Plan Name"
    <<"Plan Price"<<endl;
    
	for(int i=0;i<n;++i){
		cout<<setw(5)<<left<<i+1
       		<<setw(45)<<left<<p[i]
        	<<arr[i]<<endl;
	}
}

/*void Plan::choosePlan()
{
    displayPlan();
    cout<<"Enter the Plan no based on unsorted plan: ";
    cin>>plan_selected;
}

int Plan::getPlanSelected()
{
    return plan_selected;
}

void Plan::chooseTrainer(Trainer tr){
    displayTrainer(tr);
    cout<<"Enter Trainer ID: ";
    cin>>trainer_selected;
}

string Plan::getTrainerSelected()
{
    return trainer_selected;
}*/

//Display the list of trainer information from data file to choose trainer for trainee
void Plan::displayTrainer(Trainer tr)
{
    cout<<"\nList of Trainer"<<endl;
    cout<<setw(12)<<left<<"Trainer ID"
    <<setw(30)<<left<<"Trainer Name"
    <<setw(15)<<left<<"Trainer Gender"
    <<"Trainer Age"<<endl;
    for(int i=0; i<N; i++)
    {
        if(tr.getTrainerAge(i)!="0")
        {
            cout<<setw(12)<<left<<tr.getTrainerID(i)
            <<setw(30)<<left<<tr.getTrainerName(i)
            <<setw(15)<<left<<tr.getTrainerGender(i)
            <<tr.getTrainerAge(i)<<endl;
        }
    }
}

//Display the list of plan from the data file
void Plan::displayPlan()
{
    cout<<"\nList of Plan Offered"<<endl;
    cout<<setw(5)<<left<<"No."
    <<setw(45)<<left<<"Plan Name"
    <<"Plan Price"<<endl;
    readPlan();
    int count = 0;
    for(int i=0; i<P; i++)
    {
        if(plan_price[i]!=0)
    	{
    		cout<<setw(5)<<left<<i+1
       		<<setw(45)<<left<<plan_name[i]
        	<<plan_price[i]<<endl;
            count++;
		}
    }
    int j;
    cout << "\nDo you want to sort according to the price?"<< endl;
    cout << "1. Yes " << endl;
    cout << "2. No  " << endl;
    cout << "Please enter 1/2: ";
    cin >> j;
    if(j==1){
        bubbleSort(plan_price,plan_name,count);
    }
}

//Read the plan from data file
void Plan::readPlan()
{
    ifstream read;
    int i=0;
    read.open("Plan.txt");
    if(read.fail())
		cout<<"Sorry, input file does not exist!\n";
    
    while(!read.eof())
    {
        getline(read, plan_name[i],'\t');
        read>>plan_price[i];
        read.ignore(numeric_limits<streamsize>::max(), '\n');
        i++;
    }

    read.close();
}

/*
//User menu for choose plan
int Plan::userMenu(Trainer tr)
{
    int choice;
    cout<<"\nPlan: "<<endl;
    cout<<"1. Choose Plan"<<endl<<"2. None"<<endl;
    cout<<"Please enter 1/2: ";
    cin>>choice;

    switch(choice)
    {
        case 1: {choosePlan(); chooseTrainer(tr);}break;
        default: break;
    }
    return choice;
}*/