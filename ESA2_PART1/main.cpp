#include <iostream>

using namespace std;

class Employee
{
private:
    string surname, firstname;
    int Bd, Bm, By, Dh, ag;
public:
    Employee() {}

    void EnterData();
    void DisplayData();
    int age(int, int, int);

    string get_sname() {return surname;}
    string get_fname() { return firstname; }
    int get_holidays() { return Dh; }
    int get_age() { return ag; }

    void setter(int num) { Dh=num; }
};
void Employee :: EnterData()  //function to enter data of employees.
{                                                      //also check their age before saving the number of Holidays for specific employee
    cout<<"\tENTER  ALL NAMES IN CAPITAL/small LETTERS"<<endl<<endl;
    cout<<"Enter Surname: ";
    cin>>surname;
    cout<<"Enter Firstname: ";
    cin>>firstname;
    cout<<"Enter Date of Birth in this format DD MM YYYY: ";
    cin>>Bd>>Bm>>By;
    ag = age(Bd,Bm,By);  //call to function to get age in years.
    bool vrc = false;
    do{                             //"do-While" loop to save Holidays according to their age criteria
    if(ag>=50)
    {
       cout<<"Enter Number of Holidays per Year: ";
        cin>>Dh;
        if(Dh >32){
            cout<<"You are not allowed to take more than 32 Holidays"<<endl;
            cin.clear();
            cin.ignore(30, '\n');
            vrc = true;
        }else if (Dh<=32)
        vrc = false;
    }
    else if(ag<50){
            cout<<"Enter Number of Holidays per Year: ";
    cin>>Dh;
    if(Dh>30)
    {
       cout<<"You are not allowed to take more than 30 Holidays"<<endl;
       cin.clear();
       cin.ignore(30, '\n');
       vrc = true;
    }
    else if (Dh<=30)
    {
      vrc= false;
    }
    }
    }while(vrc==1);
}
void Employee :: DisplayData()  //function definition to display data
{
    cout<<"\t Surname: "<<surname<<" Firstname: "<<firstname<<endl;
    cout<<"\t Date of Birth: "<<Bd<<"/"<<Bm<<"/"<<By<<endl;
    cout<<"\t Number of Holidays: "<<Dh<<endl;
    int a = age(Bd,Bm,By);
}

int Employee :: age(int bd, int bm, int by)  //function to calculate exact age of employee
{                                                                   //Here age calculate according to reference of 01/01/2020
    int pd = 1;
    int pm = 1;
    int py = 2020;
  int days, months, years;
  int md[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };  //saved number of days for each month of 2020
  years = py - by;

  if (pd < bd)
  {
    pm--;
    pd = md[pm] + pd;
    days = pd - bd;
  }
  else
  {days = pd - bd;}
  if (pm < bm)
  {
    years--;
    pm += 12;
    months = pm- bm;
  }
  else
  {months = pm - bm;}
  cout << "Exact Age is : ";
  cout << years << " years " << months << " months " << days << " days. "<<endl<<endl;
  return years;
}


int main()
{
    int i=0, e;  //"e" for selection input and "i" for index of array
    Employee ec;
    Employee emp[500]; //array of objects

    do
    {
        cout<<"\tSelect Option By Entering Number"<<endl;
        cout<<"\t-----------------------------------"<<endl;
        cout<<"\t[1] To Enter Employee Data"<<endl;
        cout<<"\t[2] To Display All Data"<<endl;
        cout<<"\t[3] To Search Employee Data"<<endl;
        cout<<"\t[4] To Update Holidays"<<endl;
        cout<<"\t[5] To Delete Employee Data"<<endl;
        cout<<"\t[0] To Exit"<<endl;
        cin>>e;

        switch(e)
        {
        case 1:
            {
                system("cls");
                emp[i].EnterData();  // Call to function add data of employees
                i++;
                break;
            }
        case 2:
            {
                system("cls");
                 for(int j=0; j<i; j++)
                 {
                     emp[j].DisplayData();
                 }
                 break;
            }
        case 3:                                             //to find and display particular Employee data
            {
                system("cls");
                string sn, fn;
                cout<<"\tUSE ALL CAPITAL/small LETTERS"<<endl<<endl;
                cout<<"Enter Surname & Firstname of employee: ";
                cin>>sn>>fn;
                bool tmp = false;
                for(int k=0; k<i; k++) // "for loop" to find and display particular Employee data
                {
                    if( emp[k].get_sname()==sn && emp[k].get_fname()==fn )
                    {
                        emp[k].DisplayData();
                        tmp = true;
                        break;
                    }
                    }
                    if(tmp == 0)
                    {
                      cout<<"Employee Data is Not Existed"<<endl<<endl;
                    }
                break;
            }
        case 4:                                             //to find and update the holidays of any particular employee
            {
               system("cls");
                string sn, fn;
                cout<<"\tUSE ALL CAPITAL/small LETTERS"<<endl<<endl;
                cout<<"Enter Surname & Firstname of employee: ";
                cin>>sn>>fn;
                bool scc = false;
                for(int k=0; k<i; k++) // "for-loop" to find and update the holidays of any particular employee
                {
                    if( emp[k].get_sname()==sn && emp[k].get_fname()==fn )
                    {
                        int v = emp[k].get_holidays();
                        int s = emp[k].get_age();
                        cout<<"Already taken Holidays: "<<v<<endl;
                        int up=0;
                        bool cnf = false;
                        do{
    if(s>=50)
    {
       cout<<"Enter Number of Holidays you want more: ";
        cin>>up;
        v = up + v;
        cout<<v<<endl;
        if(v >32){
            v = emp[k].get_holidays();
            cout<<"You are not allowed to take more than 32 Holidays"<<endl;
            cin.clear();
            cin.ignore(30, '\n');
            cnf = true;
        }else if (v<=32) {
        emp[k].setter(v);
        cnf = false;
        cout<<"Holidays Updated"<<endl;
        }
    }
     else if(s<50){
    cout<<"Enter Number of Holidays you want more: ";
    cin>>up;
     v = v+up;
     cout<<v<<endl;
      if(v>30)
     {
        v = emp[k].get_holidays();
       cout<<"You are not allowed to take more than 30 Holidays"<<endl;
       cin.clear();
       cin.ignore(30, '\n');
       cnf = true;
     }
    else if (v<=30)
    {
      emp[k].setter(v);
      cnf = false;
      cout<<"Holidays Updated"<<endl;
    }
    }
    }while(cnf==1);
                        scc = true;
                        break;
                    }
                    }
                    if(scc == 0)
                    {
                      cout<<"Employee Data Not Existed"<<endl<<endl;
                    }
                break;
            }
        case 5:                             //to delete employee data
            {
                system("cls");
                string sn, fn;
                cout<<"\tUSE ALL CAPITAL/small LETTERS"<<endl<<endl;
                cout<<"Enter Surname & Firstname of employee: ";
                cin>>sn>>fn;
                bool scc = false;
                for(int k=0; k<i; k++)  // "for-loop" to delete employee data
                {
                    if( emp[k].get_sname()==sn && emp[k].get_fname()==fn )
                    {
                        scc = 1;
                        for(int t = k; t<i-1; t++)
                        {
                            emp[t] = emp[t+1];
                        }cout<<"Employee Data has been Deleted"<<endl;
                        i=i-1;
                    }
                }if(scc == 0)
                    {
                      cout<<"Employee Data Not Existed"<<endl<<endl;
                    }
                break;
            }
        }
    }while(e!=0);

  return 0;

}
