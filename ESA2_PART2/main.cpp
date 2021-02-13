#include <iostream>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

class Bike   //class Bike to save bike name and reservation status
{
    friend class Customer;  //friend class customer declaration
private:
    string nameBike;
    bool s =0;

public:
    Bike() {}
    Bike(string nm, bool r) : nameBike (nm), s(r) { s=false; }
   string bikeName() {return nameBike;}
    bool get_status() { return s; }
    void show()
    {
        cout<<nameBike;
    }

};

class Customer  //class customer to register and save customer details
{
private:
    string name, fname, str, city;
    int plz;
    long long tel;
    int bd, bm, by;
    bool a;
    bool hb =0;
    Bike rbike;             //User defined data type
public:
    Customer(){}
    bool get_license() { return a; }
    string get_name() { return name; }
    string get_fname() { return fname; }
    bool get_hb() { return hb; }
    Bike get_rbike() { return rbike; }

    void reserve(Bike rbike)        //Function to reserve bike status
    {
        this->rbike = rbike;
        rbike.s=true;
        hb = true;
    }


    friend istream& operator>> (istream& ist, Customer& x);  // Input operator overloading function declaration
    friend ostream& operator<< (ostream& ost,  Customer& y); //output operator overloading function declaration

};



istream& operator>> (istream& ist,  Customer& x)  //Input operator overloading function definition
{
    cout << endl << "Name and FirstName: ";
    ist >> x.name >>x.fname;
    cout << "Date of Birth in DD MM YYYY: ";
    ist >> x.bd >> x.bm >> x.by;
    cout<< "City and Street:";
    ist >> x.city >> x.str;
    cout<< "Postal Code:";
    ist >> x.plz;
    cout<<"TelePhone:";
    ist >> x.tel;
    cout<< "Class A Driving License Holder: YES [1] or NO [0] ->";
    ist >> x.a;
    return ist;
}
ostream& operator<< (ostream& ost, Customer& y)             //Output operator overloading function definition
{
    ost << "Full Name:" << y.name << " "<< y.fname<< endl;
    ost <<"D.O.B. "<<y.bd<<"/"<<y.bm<<"/"<<y.by<<endl;
    ost<<"Address :"<<y.str<<" "<<y.city<<" "<<y.plz<<endl;
    ost<<"TelePhone :"<<y.tel<<endl;
    if(y.a==1){
        ost <<"Customer has Class A Driving License"<<endl;
    }else{
        ost <<"Customer has NOT Class A Driving License"<<endl;
    }
    return ost;
}

int main()                      //Main function //////////////////////////////////////////////////////////
{
    ofstream myFile;
    vector<Customer> cData;
    list<Customer>::iterator itr;
    Customer c1;
    Bike b[4] = {{"Suzuki Bandit",0}, {"Honda TransAlp",0}, {"BMW F 650 GS",0}, {"Kawasaki ZZR1400",0}};
    int i, slt;
    string sn, fn;

    do                      //"do-While" loop
    {
        cout<<"\t[1] To Register Customer Data"<<endl;
        cout<<"\t[2] To Reserve Bike"<<endl;
        cout<<"\t[0] To Exit"<<endl;
        cin>>i;

        switch(i)                               //"Switch-case Statement"
        {
        case 1:
            {
               system("cls");
               cin >> c1;
               cData.push_back(c1);
               myFile.open ("Bike_Reservation_Management.txt", ios :: app );   //Function to open and write information in the file
               myFile<<c1;
               myFile.close();
              break;
            }
        case 2:
            {
                system("cls");
                cout<<"Surname: ";
                cin>>sn;
                cout<<"FirstName: ";
                cin>>fn;
                bool x=0;
                for(vector<int>:: size_type k =0; k<cData.size(); k++)
                {
                    if(cData[k].get_name() == sn && cData[k].get_fname() == fn)
                    {  x=1;
                        if(cData[k].get_license()== true)
                        {

                            if (cData[k].get_hb() == false)
                            {
                                cout<<"Select Bike"<<endl;
                                for(int i = 0; i<4; i++)
                            {
                                cout<<i+1<<"->";
                                b[i].show();
                                cout<<endl;
                            }
                                cin>>slt;
                                if(b[slt-1].get_status()==false)
                                {
                                    cData[k].reserve(b[slt-1]);
                                    myFile.open("Bike_Reservation_Management.txt", ios :: app);
                                    myFile<<cData[k].get_rbike().bikeName()<<endl;
                                    myFile.close();
                                    cout<<"Bike Reserved Successfully"<<endl;
                                }else { cout << "Bike already reserved" << endl; }
                            }else { cout << "You can't reserve bike, you already reserved"<<endl; break; }
                        }else { cout << "Need a class A driving license" << endl; }

                    }
                }if(x==0) { cout <<"Customer Not Registered"<< endl; }
               break;
            }
        }
    }while(i!=0);

    system("cls");

    cout<<"-----BYE BYE-----"<<endl;

    return 0;
}
