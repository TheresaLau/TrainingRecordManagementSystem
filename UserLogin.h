#ifndef USERLOGIN_H
#define USERLOGIN_H
#include<string>
#include "Trainee.h"
#include "Trainer.h"
using namespace std;

class UserLogin
{
    private:
        string userID, userPassword;
        Trainer tr;
        Trainee te;
        bool admin=false;
        bool trainee=false;
        bool trainer=false;
        string TraineeID="", TrainerID="";
    public:
        UserLogin(Trainer, Trainee);
        bool TrainerLogin(string, string, Trainer);
        bool TraineeLogin(string, string, Trainee);
        bool AdminLogin(string, string);
        bool UserMenu(Trainer, Trainee);
        bool getTraineeLogin();
        bool getAdminLogin();
        bool getTrainerLogin();
        string getTraineeID();
        string getTrainerID();
};

#endif