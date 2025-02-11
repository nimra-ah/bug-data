#include <iostream>
#include<fstream>
#include <string>
using namespace std;

struct bug{
     int id;
     string title;
     string status;
     int severity;
     string description;
};
//prototypes
void input(bug b1[], int size);
void store(bug b1[], int size);
void searchstatus(bug b1[], int size);
void searchsever(bug b1[], int size);
void displayfromfile(bug b1[], int size);

int main(){
    int size=2;
    bug b1[size];
    int choice;
    char again;
    do{
    cout<<"press 1 to input"<<endl;
    cout<<"press 2 to store data"<<endl;
    cout<<"press 3 to search by status"<<endl;
    cout<<"press 4 to search by severity"<<endl;
    cout<<"press 5 to display all data"<<endl;
    cin>>choice;
        switch(choice){
            case 1:
            input(b1,size);
            break;

            case 2:
            store(b1,size);
            break;

            case 3:
            searchstatus(b1, size);
            break;

            case 4:
            searchsever(b1, size);
            break;

            case 5:
            displayfromfile(b1,size);
            break;

            default:
            cout<<"invalid choice"<<endl;
            break;
        }
        cout<<"continue ?? (y or n)"<<endl;
        cin>>again;
    }while(again == 'Y' || again == 'y');

    return 0;
}
void input(bug b1[], int size){
    for(int i=0; i<size; i++){
      cout<<"enter bug id"<<endl;
      cin>>b1[i].id;
      cout<<"enter bug title"<<endl;
      cin>>b1[i].title;
      cout<<"enter bug status open, fixed, resolved or closed"<<endl;
      cin>>b1[i].status;
      cout<<"enter bug severity(1-5)"<<endl;
      cin>>b1[i].severity;
      cout<<"enter bug description"<<endl;
      cin>>b1[i].description;
    }
}
void store(bug b1[], int size){
    ofstream f("quiz.txt", ios::app);
    if (!f) {
        cout << "Error opening file for writing." << endl;
        return;
    }
        for (int i = 0; i < size; i++) {
        f << b1[i].id << endl;
        f << b1[i].title << endl;
        f << b1[i].status << endl;
        f << b1[i].severity << endl;
        f << b1[i].description << endl;
        f << "-----------------------" << endl; 
    }
    cout << "Data stored successfully!" << endl;
}
void searchstatus(bug b1[],int size){
    string stat;
    cout<<"enter status to search"<<endl;
    cin>>stat;
   for (int i = 0; i < size; i++){
    if (b1[i].status == stat) {
            cout << "Bug id: " << b1[i].id << endl;
            cout << "Title: " << b1[i].title << endl;
            cout << "Severity: " << b1[i].severity << endl;
            cout << "Description: " << b1[i].description << endl;
            cout << "-----------------------" << endl;

        }
   }

}
void searchsever(bug b1[],int size){
    int sever;
    cout << "Enter severity level to search (1-5): ";
    cin >> sever;
    
    bool found=false;
    
    for (int i = 0; i < size; i++){
    if (b1[i].severity == sever) {
            cout << "Bug id: " << b1[i].id << endl;
            cout << "Title: " << b1[i].title << endl;
            cout << "Severity: " << b1[i].severity << endl;
            cout << "Description: " << b1[i].description << endl;
            cout << "-----------------------" << endl;

            found = true;
        }
   }
   if(!found){
        cout<<"no such "<< sever <<"bug severity found"<<endl;
   }

}

void displayfromfile(bug b1[], int size){
    ifstream ff("quiz.txt", ios::in);
    if(!ff){
    cout<<"file not found";
    return;
    }
    string Data_From_File;
    while (getline(ff,Data_From_File))
    {
        cout<<Data_From_File<<endl;
    }
}