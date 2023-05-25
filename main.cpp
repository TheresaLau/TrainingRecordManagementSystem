#include "UserLogin.cpp"
#include "Trainee.cpp"
#include "Trainer.cpp"
#include "Plan.cpp"
#include "Status.cpp"
#include "Report.cpp"
#include "Node.cpp"
#include "TraineeLinkedList.cpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#define N 999

//Inserting new trainee into trainee file (Registration for Trainee)
void InsertTrainee(Node * n1, TraineeLinkedList *t, Plan planc, Trainer trainerc){
	string TE_ID, TE_name, TE_gender, TE_age, TE_hp, TE_email, TE_address, TE_weight, TE_height, TE_plan, TE_Trainer;
	cout << "Enter the new trainee information" << endl;
	cout << "Enter the ID: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,n1->TE_ID);
	cout << "Enter the trainee's name: ";
	getline(cin,n1->TE_name);
	cout << "Enter the trainee's gender (Male/Female): ";
    cin >> n1->TE_gender;
	cout << "Enter the trainee's age: ";
    cin >> n1->TE_age;
    cout << "Enter the trainee's phone number: ";
    cin >> n1->TE_hp;
    cout << "Enter the trainee's email address: ";
    cin >> n1->TE_email;
    cout << "Enter the trainee's address: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, n1->TE_address);
    cout << "Enter the trainee's weight (kg): ";
    cin >> n1->TE_weight;
    cout << "Enter the trainee's height (m): ";
    cin >> n1->TE_height;
    planc.displayPlan();
    cout << "Enter the plan choosed by trainee according to unsorted order: ";
    cin >> n1->TE_plan;
    planc.displayTrainer(trainerc);
    cout << "Enter the trainer choosed by trainee: ";
    cin >> n1->TE_Trainer;
    t->InsertNode(n1);
}

//Delete the chosen Trainee
void DeleteTrainee(TraineeLinkedList *t){
	string id;
	cout << "Delete Trainee Information" << endl;
	t->printList();
	cout << "\nEnter the Trainee ID to be deleted: " << endl;
	cout << "ID : ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,id);
	t->deleteNode(id);
}

//Update the plan and trainer for chosen trainee
void UpdatePlanTrainer(TraineeLinkedList *t, Plan planc, Trainer trainerc){
	string id,plan,trainer;
	cout << "Update Plan and Trainer Operation" << endl;
	t->printList();
	cout << "\nEnter the Trainee ID to be updated: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,id);
	planc.displayPlan();
	cout << "Enter the new plan for the trainee according to unsorted order: ";
	cin >> plan;
	planc.displayTrainer(trainerc);
	cout << "Enter the new trainer for the trainee: ";
	cin >> trainer;
	t->updateNode(id,plan,trainer);
}

int binarySearch(string search_key, int array_size,const string array[]){
    bool found = false;
    int index = -1;
    int MIDDLE, LEFT = 0, RIGHT = array_size - 1;

    while ((LEFT<=RIGHT) && (!found)){
        MIDDLE = (LEFT+RIGHT)/2;
            if(array[MIDDLE] == search_key){
                index = MIDDLE;
                found = true;
            }
            else if(array[MIDDLE] > search_key){
                RIGHT = MIDDLE - 1;
            }
            else 
                LEFT = MIDDLE + 1;
    }
    return index;
}

int main(){

    Trainee trainee;
    Trainer trainer;
    TraineeLinkedList *TraineeList=new TraineeLinkedList;
    trainer.readTrainer();
    trainee.readTrainee();
    //Read trainee file for trainee linked list
    string TE_ID, TE_name, TE_gender, TE_age, TE_hp, TE_email, TE_address, TE_weight, TE_height, TE_plan, TE_Trainer;
    int TraineeFile=0;
    fstream read;
	read.open("Trainee.txt", ios::in);
    if(read.fail())
		cout<<"Sorry, input file does not exist!\n";
    
    while(!read.eof())
    {
        getline(read, TE_ID,'\t');
        getline(read, TE_name,'\t');
        getline(read, TE_gender, '\t');
        getline(read, TE_age, '\t');
        getline(read, TE_hp,'\t');
        getline(read, TE_email,'\t');
        getline(read, TE_address,'\t');
        getline(read, TE_weight, '\t');
        getline(read, TE_height, '\t');
        getline(read, TE_plan, '\t');
        read>>TE_Trainer;
        read.ignore(numeric_limits<streamsize>::max(), '\n');
        Node *add = new Node;
        add->TE_ID=TE_ID;
        add->TE_name=TE_name;
        add->TE_gender=TE_gender;
        add->TE_age=TE_age;
        add->TE_hp=TE_hp;
        add->TE_email=TE_email;
        add->TE_address=TE_address;
        add->TE_weight=TE_weight;
        add->TE_height=TE_height;
        add->TE_plan=TE_plan;
        add->TE_Trainer=TE_Trainer;
        TraineeList->InsertNode(add);

        TraineeFile++;
	}
    TraineeFile=TraineeFile-1;
    read.close();

    //user login to the system
    UserLogin login(trainer, trainee);
    bool loginStatus;
    cout<<"\tWelcome to the Training Record Management System"<<endl;
    cout<<"******************************************************************"<<endl<<endl;
    do
    {
        loginStatus=login.UserMenu(trainer, trainee);
        if(loginStatus==false)
            cout<<"Wrong UserID or Password. Please try again."<<endl<<endl;
        else
            cout<<"Congrats! Login Successful."<<endl<<endl;
    }while(loginStatus==false);
    
    //registration for trainer, only available for admin
    int trainerIndex=trainer.getTrainerFile();
    if(login.getAdminLogin()==true)
    {
        int reg;
        do{
        cout<<"\nAdmin:\n"<<"Registration:\n";
        cout<<"1. Registration for Trainer\n"<<"2. No Registration"<<endl;
        cout<<"Please enter 1/2: ";
        cin>>reg;
        if(reg==1)
        {
            int n;
            cout<<"Registration for how many Trainer: ";
            cin>>n;
            for(int i=trainerIndex; i<(n+trainerIndex); i++)
            {
                trainer.Registration(i);
            }
            trainerIndex+=n;
        }
        }while(reg!=2);
    }
    
    //Trainee Linked List
    fstream infile;
    int llchoice;
    if(login.getAdminLogin() == true){
    	do{
            cout<<"\nTrainee:";
    		cout << "\nWhat operation do you want to perform?" << endl;
    		cout << "1. Insert a new trainee into the file (Registration for Trainee)" << endl;
    		cout << "2. Delete trainee information from the file" << endl;
    		cout << "3. Update plan and trainer of the trainee " << endl;
    		cout << "4. View updated trainee information" << endl;
    		cout << "5. None" << endl;
    		cout << "Please enter 1/2/3/4/5 : ";
    		cin >> llchoice;
    		Node *nn = new Node();
    		Plan planc;

    		switch(llchoice){
    			case 1:
    				InsertTrainee(nn,TraineeList, planc, trainer);
    				break;
    			case 2:
    				DeleteTrainee(TraineeList);
    				break;
    			case 3:
    				UpdatePlanTrainer(TraineeList, planc, trainer);
    				break;
    			case 4:
    				cout << "Latest trainee information in the system"<< endl;
    				TraineeList->printList();
    				break;
    			case 5: 
    				break;
			}
		}while (llchoice != 5);
		
		TraineeList->updatefile(infile);
	}
    
    trainee.readTrainee();

    //status of the day
    Status status;
    Report report;
    int a,b,c,g,w=0,y=0;
    string te_id,tr_te_id;
    //count how many trainee for now
    while(trainee.getTraineeID(w).length() != 0){
        w++;
    }
    while(trainer.getTrainerID(y).length() != 0){
        y++;
    }
    string TraineeIDStat[w];
    string TraineeIDRep[w];
    string TrainerIDRep[y];
     if(login.getTrainerLogin()==true){
         int m;
         cout << "\nTrainer" << endl;
         cout << "Key-in Status of the Trainee" << endl;
         cout << "1. Yes" << endl;
         cout << "2. No" << endl;
         cout << "Please enter 1/2 : ";
         cin >> m;

             if (m==1){
                int p=0;
                while(p<w)
                {
                    if(trainee.getTraineeID(p).length() != 0)
                    {
                        TraineeIDStat[p] = trainee.getTraineeID(p);
                    }
                    else if(trainee.getTraineeID(p).length() != 0)
                        break;
                    p++;
                }
             	cout << "Enter the trainee's ID : " ;
                cin.ignore();
             	getline(cin,te_id);
                a = binarySearch(te_id,  p, TraineeIDStat);
                cout << "Lesson Number : ";
                cin >> c;
             	status.writeStatus(a,c,w);
             	cout << "Status recorded." << endl;
             }
 	}
    
    //Display report of Trainee
     if(login.getAdminLogin()==true || login.getTraineeLogin()==true || login.getTrainerLogin()==true){
         int m;
         cout << "\nViewing Report" << endl;
         cout << "1. Yes" << endl;
         cout << "2. No" << endl;
         cout << "Please enter 1/2 : ";
         cin >> m;
            
             if(m==1){
                int d=0,e=0;
                cout<<"\nList of Trainee ID available: \n";
                while(d<w)
                {
                    if(trainee.getTraineeID(d).length() != 0)
                    {
                        TraineeIDRep[d] = trainee.getTraineeID(d);
                        cout << TraineeIDRep[d]<<endl;
                    }
                    else if(trainee.getTraineeID(d).length() != 0)
                        break;
                    d++;
                }
                while(e<y)
                {
                    if(trainer.getTrainerID(e).length() != 0)
                    {
                        TrainerIDRep[e] = trainer.getTrainerID(e);
                    }
                    else if(trainer.getTrainerID(e).length() != 0)
                        break;
                    e++;
                }
                if(login.getTraineeLogin()==true){
                    te_id = login.getTraineeID();
                }
                else{
                cout << "\nEnter the trainee's ID : "; 
                cin.ignore();
                getline(cin,te_id);
                }
                b = binarySearch(te_id,  d, TraineeIDRep);
                tr_te_id = trainee.getTeTrainerID(b);
                g = binarySearch(tr_te_id, e, TrainerIDRep);
                report.displayReport(status, trainee, trainer, b, g);
             }
		}
		
	cout << "\nThank you for using our system!";
}
