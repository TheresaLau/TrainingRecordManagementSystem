#include "UserLogin.h"
#include<iostream>
#define N 999
using namespace std;

UserLogin::UserLogin(Trainer trainer, Trainee trainee):tr(trainer), te(trainee)
{
	tr=trainer;
	te=trainee;
}

//Check Trainer Login
bool UserLogin::TrainerLogin(string trid, string p, Trainer tr)
{
    for(int i=0; i<N; i++)
    {
        if((trid==tr.getTrainerID(i))&&(p==tr.getTrainerPass(i)))
        {
            TrainerID=trid;
            trainer=true;
            break;
        }
        else
            trainer=false;
    }
    return trainer;
}

//Check Trainee Login
bool UserLogin::TraineeLogin(string teid, string p, Trainee te)
{
    for(int i=0; i<N; i++)
    {
        if((teid==te.getTraineeID(i))&&(p==te.getTraineeHP(i)))
        {
            TraineeID=teid;
            trainee=true;
            break;
        }
        else
            trainee=false;
    }
    return trainee;
}

//Check Admin Login
bool UserLogin::AdminLogin(string aid, string p)
{
    if((aid=="TrainingRecord")&&(p=="hello555"))
        admin=true;
    else
        admin=false;
    
    return admin;
}

//User Menu for Login Option
bool UserLogin::UserMenu(Trainer tr, Trainee te)
{   
    int choice;
    string ID, p;
    bool status;
    cout<<"User login:"<<endl
    <<"1. Admin"<<endl<<"2. Trainer"<<endl<<"3. Trainee"<<endl
    <<"Please enter 1/2/3: ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: 
        cout<<"AdminID: ";
        cin>>ID;
        cout<<"Password: ";
        cin>>p;
        status=AdminLogin(ID, p);
        return status;
        break;
        case 2:
        cout<<"TrainerID: ";
        cin>>ID;
        cout<<"Password: ";
        cin>>p;
        status=TrainerLogin(ID, p, tr);
        return status;
        break;
        default:
        cout<<"TraineeID: ";
        cin>>ID;
        cout<<"Password: ";
        cin>>p;
        status=TraineeLogin(ID, p, te);
        return status;
        break;
    }
}

//Get Trainee Login Status
bool UserLogin::getTraineeLogin()
{
    return trainee;
}
//Get Trainer Login Status
bool UserLogin::getTrainerLogin()
{
    return trainer;
}
//Get Admin Login Status
bool UserLogin::getAdminLogin()
{
    return admin;
}
//Get Trainee ID that user use to login
string UserLogin::getTraineeID()
{
    return TraineeID;
}
//Get Trainer ID that user use to login
string UserLogin::getTrainerID()
{
    return TrainerID;
}