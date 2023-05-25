#include "Trainer.h"
#include <iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <fstream>
using namespace std;

Trainer::Trainer()
{
	for(int i=0; i<N; i++)
	{
		TR_age[i]="0";
	}
}

//Register for trainer, only for admin use
void Trainer::Registration(int i)
{

    cout<<"Enter the trainer's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, TR_name[i]);
    cout<<"Enter the trainer's gender (Male/Female): ";
    cin>>TR_gender[i];
    cout<<"Enter the trainer's age: ";
    cin>>TR_age[i];
    cout<<"Enter the trainer's phone number: ";
    cin>>TR_hp[i];
    cout<<"Enter the trainer's email address: ";
    cin>>TR_email[i];
    cout<<"Enter the trainer's address: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, TR_address[i]);
    cout<<"Enter the trainer's weight (kg): ";
    cin>>TR_weight[i];
    cout<<"Enter the trainer's height (m): ";
    cin>>TR_height[i];
    string str= to_string(i);
    if(i<10)
        TR_ID[i]="TR00"+str;
    else if (i<100)
        TR_ID[i]="TR0"+str;
    else
        TR_ID[i]="TR"+str;

    cout<<endl<<endl<<"Your ID is: "<<TR_ID[i]<<endl
    <<"Please use you phone number as password. Thank you!"<<endl;

    ofstream write("Trainer.txt", ios::out|ios::app);
    write.seekp(ios::ate, ios::cur);
    write<<TR_ID[i]<<"\t"<<TR_name[i]<<"\t"<<TR_gender[i]<<"\t"<<TR_age[i]<<"\t"
	<<TR_hp[i]<<"\t"<<TR_email[i]<<"\t"<<TR_address[i]<<"\t"<<TR_weight[i]<<"\t"<<TR_height[i]<<"\n";
	write.close();
}

//Display the trainer information in report
void Trainer::displayTrainerInfo(Trainer tr,int i){
    cout << "\nTrainer's Information" << endl;
    cout << "****************************************************" << endl;
    cout << "Name           : " << tr.getTrainerName(i) << endl;
    cout << "ID             : " << tr.getTrainerID(i) << endl;
    cout << "Gender         : " << tr.getTrainerGender(i) << endl;
    cout << "Age            : " << tr.getTrainerAge(i) << endl;
    cout << "Phone Number   : " << tr.getTrainerHP(i) << endl;
    cout << "Email          : " << tr.getTrainerEmail(i) << endl;
    cout << "Address        : " << tr.getTrainerAddress(i) << endl;
    cout << "Weight (kg)    : " << tr.getTrainerWeight(i) << endl;
    cout << "Height (m)     : " << tr.getTrainerHeight(i) << endl;
}

string Trainer::getTrainerName(int i)
{
    return TR_name[i];
}
string Trainer::getTrainerID(int i)
{
    return TR_ID[i];
}
string Trainer::getTrainerPass(int i)
{
    return TR_hp[i];
}
string Trainer::getTrainerGender(int i)
{
    return TR_gender[i];
}
string Trainer::getTrainerAge(int i)
{
    return TR_age[i];
}

string Trainer::getTrainerHP(int i){
    return TR_hp[i];
}

string Trainer::getTrainerEmail(int i){
    return TR_email[i];
}

string Trainer::getTrainerAddress(int i){
    return TR_address[i];
}

string Trainer::getTrainerWeight(int i){
    return TR_weight[i];
}

string Trainer::getTrainerHeight(int i){
    return TR_height[i];
}

//Read the trainer information from data file
void Trainer::readTrainer()
{
    ifstream read("Trainer.txt");
    if(read.fail())
		cout<<"Sorry, input file does not exist!\n";
    
    while(!read.eof())
    {
        getline(read, TR_ID[TrainerFile],'\t');
        getline(read, TR_name[TrainerFile],'\t');
        getline(read, TR_gender[TrainerFile], '\t');
        getline(read, TR_age[TrainerFile], '\t');
        getline(read, TR_hp[TrainerFile],'\t');
        getline(read, TR_email[TrainerFile],'\t');
        getline(read, TR_address[TrainerFile],'\t');
        read>>TR_weight[TrainerFile];
        read>>TR_height[TrainerFile];
        read.ignore(numeric_limits<streamsize>::max(), '\n');

        TrainerFile++;
    }
    TrainerFile=TrainerFile-1;

    read.close();
}

int Trainer::getTrainerFile()
{
	return TrainerFile;
}