#ifndef TRAINER_H
#define TRAINER_H
#include<string>
#define N 999
using namespace std;

class Trainer
{
    private:
        string TR_name[N], TR_hp[N], TR_email[N], TR_address[N], TR_ID[N];
        int index;
        string TR_gender[N], TR_age[N];
        string TR_weight[N], TR_height[N];
        int TR_Trainee[10][N];
        int TrainerFile=0;
    public:
        Trainer();
        void Registration(int);
        void displayTrainerInfo(Trainer,int);
        string getTrainerName(int);
        string getTrainerID(int);
        string getTrainerPass(int);
        string getTrainerGender(int);
        string getTrainerAge(int);
        string getTrainerHP(int);
        string getTrainerEmail(int);
        string getTrainerAddress(int);
        string getTrainerWeight(int);
        string getTrainerHeight(int);
        void setTrainee(int, int);
        void readTrainer();
        int getTrainerFile();
};

#endif