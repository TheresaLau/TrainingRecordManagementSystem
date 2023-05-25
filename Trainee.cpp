#include "Trainee.h"
#include <iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include<fstream>
#include <string>
using namespace std;

/*//Register for trainee, only for admin use
void Trainee::Registration(int i)
{
    cout<<"Enter the trainee's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, TE_name[i]);
    cout<<"Enter the trainee's gender (Male/Female): ";
    cin>>TE_gender[i];
    cout<<"Enter the trainee's age: ";
    cin>>TE_age[i];
    cout<<"Enter the trainee's phone number: ";
    cin>>TE_hp[i];
    cout<<"Enter the trainee's email address: ";
    cin>>TE_email[i];
    cout<<"Enter the trainee's address: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, TE_address[i]);
    cout<<"Enter the trainee's weight (kg): ";
    cin>>TE_weight[i];
    cout<<"Enter the trainee's height (m): ";
    cin>>TE_height[i];
    string str= to_string(i);
    if(i<10)
        TE_ID[i]="TE00"+str;
    else if (i<100)
        TE_ID[i]="TE0"+str;
    else
        TE_ID[i]="TE"+str;

    cout<<endl<<endl<<"Your ID is: "<<TE_ID[i]<<endl
    <<"Please use you phone number as password. Thank you!"<<endl;

    ofstream write("Trainee.txt", ios::out|ios::app);
    write.seekp(ios::ate, ios::cur);
    write<<TE_ID[i]<<"\t"<<TE_name[i]<<"\t"<<TE_gender[i]<<"\t"<<TE_age[i]<<"\t"
	<<TE_hp[i]<<"\t"<<TE_email[i]<<"\t"<<TE_address[i]<<"\t"<<TE_weight[i]<<"\t"<<TE_height[i]<<TE_plan[i]<<TE_Trainer[i]<<"\n";
	write.close();
}*/

//Display the trainee information in report
void Trainee::displayTraineeInfo(Trainee te, int i){
    cout << "\nTrainee's Information" << endl;
    cout << "****************************************************" << endl;
    cout << "Name           : " << te.getTraineeName(i) << endl;
    cout << "ID             : " << te.getTraineeID(i) << endl;
    cout << "Gender         : " << te.getTraineeGender(i) << endl;
    cout << "Age            : " << te.getTraineeAge(i) << endl;
    cout << "Phone Number   : " << te.getTraineeHP(i) << endl;
    cout << "Email          : " << te.getTraineeEmail(i) << endl;
    cout << "Address        : " << te.getTraineeAddress(i) << endl;
    cout << "Weight (kg)    : " << te.getTraineeWeight(i) << endl;
    cout << "Height (m)     : " << te.getTraineeHeight(i) << endl;
    cout << "Plan no        : "<<te.getTraineePlan(i)<<endl;
	cout << "Trainer        : "<<te.getTeTrainerID(i)<<endl;
}

string Trainee::getTraineeHP(int i)
{
    return TE_hp[i];
}

string Trainee::getTraineeID(int i)
{
    return TE_ID[i];
}

string Trainee::getTraineeName(int i){
    return TE_name[i];
}

string Trainee::getTraineeEmail(int i){
    return TE_email[i];
}

string Trainee::getTraineeAddress(int i){
    return TE_address[i];
}

string Trainee::getTraineeAge(int i){
    return TE_age[i];
}

string Trainee::getTraineeGender(int i){
    return TE_gender[i];
}

string Trainee::getTraineeWeight(int i){
    return TE_weight[i];
}

string Trainee::getTraineeHeight(int i){
    return TE_height[i];
}

string Trainee::getTeTrainerID(int i)
{
	return TE_Trainer[i];
}
/*//Set the plan for trainee
void Trainee::setPlan(string id, int pln)
{
    for(int i=0; i<N; i++)
    {
        if(TE_ID[i]==id)
        {
            TraineeIndex=i;
            TE_plan[i]=to_string(pln);
            break;
        }
    }
}

//Set the trainer for the trainee
void Trainee::setTrainer(string id, string tr)
{
    for(int i=0; i<N; i++)
    {
        if(TE_ID[i]==id)
        {
            TE_Trainer[i]=tr;
            break;
        }
    }
}*/

int Trainee::getTraineeIndex()
{
    return TraineeIndex;
}

//Read the trainee information from data file
void Trainee::readTrainee()
{
    TraineeFile=0;
    ifstream read;
	read.open("Trainee.txt");
    if(read.fail())
		cout<<"Sorry, input file does not exist!\n";
    
    while(!read.eof())
    {
        getline(read, TE_ID[TraineeFile],'\t');
        getline(read, TE_name[TraineeFile],'\t');
        getline(read, TE_gender[TraineeFile], '\t');
        getline(read, TE_age[TraineeFile], '\t');
        getline(read, TE_hp[TraineeFile],'\t');
        getline(read, TE_email[TraineeFile],'\t');
        getline(read, TE_address[TraineeFile],'\t');
        getline(read, TE_weight[TraineeFile], '\t');
        getline(read, TE_height[TraineeFile], '\t');
        getline(read, TE_plan[TraineeFile], '\t');
        read>>TE_Trainer[TraineeFile];
        read.ignore(numeric_limits<streamsize>::max(), '\n');

        TraineeFile++;
	}
    TraineeFile=TraineeFile-1;
}

int Trainee::getTraineeFile()
{
	return TraineeFile;
}

string Trainee::getTraineePlan(int i)
{
	return TE_plan[i];
}