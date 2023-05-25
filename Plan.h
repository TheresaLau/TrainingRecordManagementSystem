#ifndef PLAN_H
#define PLAN_H
#include "Trainer.h"
#include<string>
#define N 999
#define P 15
using namespace std;

class Plan
{
    private:
        //int plan_selected;
		//string trainer_selected;
        string plan_name[P];
        float plan_price[P];
        int plan_no;
        string trainer_name[N];
        int trainer_age[N];
        char trainer_gender[N];
    public:
        void bubbleSort(float*,string*,int);
        //void choosePlan();
        //void chooseTrainer(Trainer);
        void displayTrainer(Trainer);
        void displayPlan();
        //int userMenu(Trainer);
        //int getPlanSelected();
        //string getTrainerSelected();
        void readPlan();
};

#endif