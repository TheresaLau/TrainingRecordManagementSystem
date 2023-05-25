#include "Report.h"
#include "Trainee.h"
#include "Trainer.h"
#include "Status.h"
#include <iostream>
using namespace std;

void Report::displayReport(Status st, Trainee te, Trainer tr,int i,int j){
    trainee.displayTraineeInfo(te, i);
    trainer.displayTrainerInfo(tr, j);
    status.displayStatus(st, i);
}