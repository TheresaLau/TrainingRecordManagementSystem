#ifndef _STATUS_H_
#define _STATUS_H_
#include <string>
#define M 999
using namespace std;

class Status{

    private :
        int clk_in_hours[M], clk_in_minutes[M], clk_out_hours[M], clk_out_minutes[M];
        int d[M],m[M],y[M];

    public :
        int Duration(int, int, int, int,int);
        void displayStatus(Status,int);
        int getClkInHours(int);
        int getClkInMinutes(int);
        int getClkOutHours(int);
        int getClkOutMinutes(int);
        int getDay(int);
        int getMonth(int);
        int getYear(int);
        void writeStatus(int,int,int);
        void readStatus();
};

#endif