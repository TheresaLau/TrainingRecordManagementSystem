#ifndef _REPORT_H_
#define _REPORT_H_
#include "Trainee.h"
#include "Trainer.h"
#include "Status.h"
#include <string>
using namespace std;

class Report{

    private :
        Trainee trainee;
        Trainer trainer;
        Status status;
        Plan plan;

    public :
        void displayReport(Status, Trainee, Trainer, int, int);
};

#endif