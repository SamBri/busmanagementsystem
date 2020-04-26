//Author: Sam
//Date:25th April 2020
//Program: Bus management system

#include <iostream>
#include <string>
#include <map>

using namespace std;

//bus details
struct BUS{

    /*Data Members*/
    private:
    string busType; //bus type
    string busMake; //bus make
    string busFault; // bus fault
    string regNumber;  //registration number

    /*Operation*/
    //Getters
    public:
    string GetBusType(){
        return this->busType;
    }

    string GetBusMake(){
        return this->busMake;
    }

    string GetBusFault(){
        return this->busFault;
    }

    string GetRegNumber(){
        return this->regNumber;
    }

    //Setters
    public:
    void SetBusType(string busType){
        this->busType = busType;
    }

    void SetBusMake(string busMake){
        this->busMake = busMake;
    }

    void SetBusFault(string busFault){
     this->busFault = busFault;
    }

    void SetRegNumber(string regNumber){
        this->regNumber = regNumber;
    }

    void SetBusDetails(string busType, string busMake, string busFault, string regNumber){

        //get bus details
        this->busType = busType;
        this->busMake = busMake;
        this->busFault = busFault;
        this->regNumber = regNumber;

        return;
    }
    //Display bus details;
    void DisplayBusDetails(){
        cout <<busType<<endl
        <<busMake<<endl
        <<busFault<<endl
        <<regNumber<<endl;
    }



};

//bus owner details
struct BUSOWNER{

    /* Data Members*/
    string name;   //name of bus owner
    string billingAddress; //billing address
    string gender; //gender of bus owner
    long contact; //contact of bus owner
    struct BUS bus; // bus details of bus owner.

    /*Operation*/
    //Getters
    string GetName(){
        return this->name;
    }

    string GetBillingAddres(){
        return this->billingAddress;
    }

    string GetGender(){
        return this->gender;
    }

    long GetContact(){
        return this->contact;
    }


    //Setters
    void SetName(string name){
        this->name = name;
    }

    void SetBillingAddres(string billingAddress){
        this->billingAddress = billingAddress;
    }

    void SetGender(string gender){
     this->gender = gender;
    }

    void SetContact (long contact){
            this->contact = contact;

        }

    void SetBusOwnerDetails(string name, string billingAddress, string gender, int contact){

        this->name = name;
        this->billingAddress = billingAddress;
        this->gender = gender;
        this->contact = contact;
    }

    void DisplayBusOnwerDetails(){
         cout <<name<<endl
          <<billingAddress<<endl<<gender<<endl
          <<contact<<endl;

    }
};

struct PERSON{
    string name;
};

struct MECHANIC{
    struct PERSON mechanic;
};

struct HELPER{
struct PERSON helper;
};

struct INVENTORY
{
   map <string,float> parts; //a map of parts and prices.

};
// TODO (FAMILY PC#1#): inventory list creation
//main function
int main()
{
    //welcome display to end user
    cout <<"*************************************"<<endl;
    cout <<"**WELCOME TO ADUM BUS REPAIR SHOP**"<<endl;
    cout <<"*************************************"<<endl;

    INVENTORY adumList; //inventory of parts
    adumList.parts.insert(pair<string, float>("headlights", 25.3));
    adumList.parts.insert(pair<string, float>("bolts", 15.23));
    adumList.parts.insert(pair<string, float>("spark plugs", 30.5));


    //enter bus details
    string busType, busMake, busFault, regNumber; char isBusFaulty, isBusNew;
    cout <<"Enter Bus Type:";
    cin >> busType;
    cout <<"Enter Bus Make:";
    cin >>busMake;
    cout <<"Enter Bus Fault:";
    cin >> busFault;
    cout <<"Enter Registration Number:";
    cin >> regNumber;
    cout <<"Is Bus New(Y/N)?:";
    cin >> isBusNew;
    cout <<"Is Bus Faulty(Y/N)?:";
    cin >> isBusFaulty;


    //enter bus owner details
    string name,billingAddress;
    string gender; long contact;
    cout <<"Enter Bus owner name:";
    cin >> name;
    cout <<"Enter Billing Address:";
    cin >> billingAddress;
    cout <<"Enter Gender:";
    cin >> gender;
    cout <<"Enter contact number:";
    cin >> contact;

        //debug bus input values
      /* cout <<busType<<endl
        <<busMake<<endl
        <<busFault<<endl
        <<regNumber<<endl;


        //debug bus owner input values
         cout <<name<<endl
 *       <<billingAddress<<endl
         <<gender<<endl
        <<contact<<endl;

      */

    //Add new bus to the system, all buses are faulty
    if(isBusNew == 'Y')
   {
    BUS* bus1;
    bus1 = new BUS; //new bus in station

    BUSOWNER* busowner1;
    busowner1 = new BUSOWNER; //new busowner in station

    //read details
    if(bus1 != nullptr && busowner1 != nullptr){
        //set bus details
        bus1->SetBusMake(busMake);
        bus1->SetBusFault(busFault);
        bus1->SetBusType(busType);
        bus1->SetRegNumber(regNumber);

        //set bus owner details
        busowner1->SetName(name);
        busowner1->SetGender(gender);
        busowner1->SetContact(contact);
        busowner1->SetBillingAddres(billingAddress);


        //assume that a
        busowner1->bus = *bus1;

        busowner1->bus.DisplayBusDetails();

    }
    else
        cout <<"Error"<<endl;

        if(isBusFaulty == 'Y')
        {
            cout <<"Repair Mode"<<endl;
            //mechanic and helper assigned to bus
            MECHANIC mech;
            mech.mechanic.name = "Kwame";

            HELPER help;
            help.helper.name = "John";

            cout <<"\nMechanic,"<<mech.mechanic.name<<" and "<<"Helper,"
            <<help.helper.name<<" assigned to car with registration number: "<<bus1->GetRegNumber() << endl;


        }
   }
   else
   {
       cout <<"----"<<endl;
   }








    return 0;
}
