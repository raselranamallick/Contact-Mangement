//including Header files
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//global variables
string fname, lname, phone_num;

// Functions
void addContact();
void searchContact();
void help();
void self_exit();
bool checkDigits(string);
bool checkNumbers(string);

int main()
{
    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4.Exit\n\t>";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            getch();
            main();
    }
    return 0;
}

// Functions definitions
void self_exit()
{
    cout<<"\n\n\n\t\tThank You For Using !";
    exit(0);
}
void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout<<"\n\n\tEnter First Name :";
    cin>>fname;
    cout<<"\n\tEnter Last Name :";
    cin>>lname;
    cout<<"\n\tEnter Phone Number :";
    cin>>phone_num;

    if(checkDigits(phone_num)==true)
    {
        if(checkNumbers(phone_num)==true)
        {
            if(phone.is_open())
            {
                phone<<fname<<" "<<lname<<" "<<phone_num<<endl;
                cout<<"\n\tContact Saved Successfully !";
            }
            else
            {
                cout<<"\n\tError Opening File !";
            }
            phone.close();
        }
        else
        {
            cout<<"\n\n\tPhone Number Must Contain Only Digits from 0 to 9 !!";
        }
    }
    else
    {
        cout<<"\n\n\tPhone Number Must Contain 10 Digits ";
    }
}
void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout<<"\n\tEnter Name To Search :";
    cin>>keyword;
    while(myfile>>fname >>lname>>phone_num)
    {
        if(keyword == fname || keyword == lname)
        {
            system("cls");
            cout<<"\n\n\n\t\tContact Details...";
            cout<<"\n\n\tFirst Name :" <<fname;
            cout<<"\n\n\tLast Name :" <<lname;
            cout<<"\n\tPhone Number :"<<phone_num;
            found = true;
        }
    }
    if(found == false)
        cout<<"\n\tNo Such Contacts Found !";
}
void help()
{
    cout<<"\n\n\tThis Displays Help";
}
bool checkDigits(string x)
{
    if(x.length()==10)
        return true;
    else
        return false;
}
bool checkNumbers(string x)
{
    bool check = true;
    for(int i=0;i<10;i++)
    {
        if(x[i]<48 || x[i]>57)
        {
            check = false;
            break;
        }
    }
    return check;
}