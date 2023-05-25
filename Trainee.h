#ifndef TRAINEE_H
#define TRAINEE_H
#include<string>
#define N 999
using namespace std;

class Trainee
{
    private:
        string TE_name[N], TE_hp[N], TE_email[N], TE_address[N], TE_ID[N];
        string TE_age[N];
        int index;
        string TE_gender[N];
        string TE_weight[N], TE_height[N];
        string TE_plan[N], TE_Trainer[N];
        int TraineeIndex;
        int TraineeFile=0;
    public:
        //void Registration(int);
        void displayTraineeInfo(Trainee, int);
        string getTraineeHP(int);
        string getTraineeID(int);
        string getTraineeName(int);
        string getTraineeEmail(int);
        string getTraineeAddress(int);
        string getTraineeAge(int);
        string getTraineeGender(int);
        string getTraineeWeight(int);
        string getTraineeHeight(int);
        string getTraineePlan(int);
        string getTeTrainerID(int);
        //void setPlan(string, int);
        //void setTrainer(string, string);
        int getTraineeIndex();
        void readTrainee();
        int getTraineeFile();
};

#endif