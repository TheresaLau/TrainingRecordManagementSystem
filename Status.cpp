#include "Status.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int Status::Duration (int ih, int im, int oh, int om, int a){
    clk_in_hours[a] = ih;
    clk_in_minutes[a] = im;
    clk_out_hours[a] = oh;
    clk_out_minutes[a] = om;

    if (clk_in_minutes[a] > clk_out_minutes[a]){
        --clk_out_hours[a];
        clk_out_minutes[a] += 60;
    }

    int difference_minutes = clk_out_minutes[a] - clk_in_minutes[a];
    int difference_hours = clk_out_hours[a] - clk_in_hours[a];

    int duration = difference_hours*60 + difference_minutes;

    return duration;
}

void Status::displayStatus(Status st, int i){
    int a;
    if(i==0){
    	a=i*11;
	}
	else
		a=i*11 + 1;
    cout << "\nStatus of the trainee for the training plan"<<endl;
    cout <<"****************************************************" << endl;
    float b;
    for(int n=0;n<12;n++){
            b = (n+1)/12.0*100;
            readStatus();
            cout << "\nDate                       : " << d[a] << "/" << m[a] << "/" << y[a] << endl;
            cout << "Duration of training       : " << Duration(clk_in_hours[a],clk_in_minutes[a],clk_out_hours[a],clk_out_minutes[a], a) << " minutes" << endl;
            cout << "Progress of the day        : " << b << "%" << endl;
            a++;
    }
    
}

void Status::writeStatus(int i, int j, int w){
	int d[w*12],m[w*12], y[w*12], ih[w*12], im[w*12], oh[w*12], om[w*12];
    i = (i*11)+j;
    cout << "\nEntering the status : " << endl;
        cout << "              Date              "<< endl;
        cout << "********************************"<< endl;
        cout << "Day                             : ";
            cin >> d[i];
        cout << "Month                           : ";
            cin >> m[i];
        cout << "Year                            : ";
            cin >> y[i];
        cout << "Training Time(in 24-hour format)"<< endl;
        cout << "********************************"<< endl;
    	cout << "Clock-in (hours)                : ";
    		cin >> ih[i];
    	cout << "Clock-in (minutes)              : ";
    		cin >> im[i]; 
   	 	cout << "Clock-out (hours)               : ";
    		cin >> oh[i];
    	cout << "Clock-out (minutes)             : ";
    		cin >> om[i];
	ofstream outfile;
    outfile.open("Status.txt",ios::out | ios::app);
    outfile << d[i] << "\t" << m[i] << "\t" << y[i] << "\t" << ih[i] << "\t" << im[i] << "\t" << oh[i] << "\t"  << om[i] << endl;
	outfile.close();
}

void Status::readStatus()
{
    ifstream infile("Status.txt");
    if(infile.fail())
		cout<<"Sorry, input file does not exist!\n";
    
    int count=0;
    while(!infile.eof())
    {
        infile >> d[count] >> m[count] >> y[count] >> clk_in_hours[count] >> clk_in_minutes[count] >> clk_out_hours[count] >> clk_out_minutes[count];


        count++;
    }

    infile.close();
}
int Status::getClkInHours(int i){
    return clk_in_hours[i];
}

int Status::getClkInMinutes(int i){
    return clk_in_minutes[i];
}

int Status::getClkOutHours(int i){
    return clk_out_hours[i];
}

int Status::getClkOutMinutes(int i){
    return clk_out_minutes[i];
}

int Status::getDay(int i){
    return d[i];
}

int Status::getMonth(int i){
    return m[i];
}

int Status::getYear(int i){
    return y[i];
}