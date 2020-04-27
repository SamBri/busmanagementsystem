//Author: Sam
//Date:25th April 2020
//Program: Bus management system

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include<fstream>
#include <ctime>
#include <cstdio>

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

    /*Operations*/
    //Find part
   bool FindRequestedPart(string part){

       if(parts.find(part)->first == part)
        return true;
   }
    //Setters
   float setRequestedPartPrice(string part, float price)
   {
       parts.find(part)->second = price;
       cout <<"Successful"<<endl;
   }

   //Getters
   float GetRequestedPartPrice(string part){
    return parts.find(part)->second;
   }

   string GetRequestedPart(string part)
   {
       return parts.find(part)->first;
   }



};

struct TRANSACTION
{


};

struct INVOICE
{
    int hoursSpent; //hours spent on the bus
    int quantity;

    /*Operations*/
    //Getters
    int GetHoursSpent(){
        return hoursSpent;
    }

    int GetQuantity(){
    return quantity;
    }


    //Setters
    int SetHoursSpent(int hours){
        this->hoursSpent = hours;
    }

    int SetQuantity(int quantity){
     this->quantity = quantity;
    }



   float CalculateInovice(struct INVENTORY inventory, int quantity,string part){

       return (inventory.GetRequestedPartPrice(part)* quantity);
   }

};


/* FIXME (FAMILY PC#1#04/27/20): Next Build
1) Insert a measure of control for parts requested and bus fault detected.
2) Make registration number accepts strings plus whitespaces
3) Make billing address accept strings plus whitespaces
4) Make name to accept strings plus whitespaces
*/

/* NOTE (FAMILY PC#1#04/27/20): Refactoring
1)  Bus owner can have more than one bus hence bus assignment to bus owner has to be dynamic
2) Bus can have more than one faults hence faults should be in a collection or container.
*/


//main function
int main()
{
    //welcome display to end user
    cout <<"*************************************"<<endl;
    cout <<"**WELCOME TO ADUM BUS REPAIR SHOP**"<<endl;
    cout <<"*************************************"<<endl;

    INVENTORY adumList; //inventory of parts
    adumList.parts.insert(pair<string, float>("headlights", 0));
    adumList.parts.insert(pair<string, float>("bolts", 0));
    adumList.parts.insert(pair<string, float>("spark plugs", 0));


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
    switch(isBusNew){ //check for input invalid input
    case 'Y':
        ;
        break;
    case 'N':
        ;
        break;
    default:
        cout <<"INVALID INPUT:"<<isBusNew<<endl;
        return -1;
    }
    cout <<"Is Bus Faulty(Y/N)?:";
    cin >> isBusFaulty;
    switch(isBusFaulty){ //check for input invalid input
    case 'Y':
        ;
        break;
    case 'N':
        ;
        break;
    default:
        cout <<"INVALID INPUT:"<<isBusFaulty<<endl;
        return -1;
    }

    cout <<endl;

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
    if(isBusNew == 'N' || isBusNew == 'Y')
   {
    BUS* bus1;
    bus1 = new BUS; //new bus in station

    time_t rawtime; string timestamp;
    time(&rawtime);
    timestamp = ctime(&rawtime); //timestamp created.
    cout <<"Timestamp:"<< timestamp << endl;

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

        //busowner1->bus.DisplayBusDetails();

    }
    else
        cout <<"Memory allocation error"<<endl;

        //schedule a repair
        if(isBusFaulty != 'N')
        {
            system("pause");
            //clear screen
            system("cls");

            cout <<"\t\t***Repair Mode***"<<endl;
            //mechanic and helper assigned to bus
            MECHANIC mech;
            mech.mechanic.name = "Kwame";

            HELPER help;
            help.helper.name = "John";

            //display mechanic, task details
            cout <<"\nMechanic:"<<mech.mechanic.name<<endl<<"Helper:"
            <<help.helper.name<<endl<<"Task:"<<"assigned to "<<"bus with registration number,"<<bus1->GetRegNumber()
            << endl <<"Fault:"<<bus1->GetBusFault()<<endl;

            //find parts
            cout <<"Parts Request."<<endl;
            cout <<"Search requeseted part.."<<endl;
            cout <<"Enter part:"<<endl;
            string parts;
            cin >> parts;

            if(adumList.FindRequestedPart(parts))

            {
              cout <<"Match Found!"<<endl;
              cout <<"Price requested part:GHC"<<flush;
              float price;
              cin >> price;
              adumList.setRequestedPartPrice(parts,price);

              cout <<"Enter hours spent:";
              int hours;
              cin >> hours;

              cout<<"Enter Quantity used:"<<flush;
              int quantity;
              cin >> quantity;

              //produce invoice
              INVOICE invoice1;
              invoice1.SetQuantity(quantity);

              system("pause");
              system("cls");  // new screen
              cout <<"\t\t***Generating Receipt***"<<endl;
              //invoice1.SetHoursSpent(hours);
              //cout <<invoice1.CalculateInovice(adumList,quantity,parts)<<endl;

              ofstream out("receipt.txt"); //create receipt
              if(!out)
              {
                  cout <<"Cannot open file. \n";
                  return 1;
              }
               else{
                 out<<"ADUM BUS REPAIR SHOP INVOICE\n" <<"Date of transaction:"<<timestamp<<endl
               <<"Type of repair:"<<bus1->GetBusFault()<<endl<<"Parts used:"<<adumList.GetRequestedPart(parts)<<endl
               <<"cost of parts:GHC"<<invoice1.CalculateInovice(adumList,quantity,parts) << endl
               <<"Mechanic assigned:"<<mech.mechanic.name<<endl<<"Helper assigned:"<<help.helper.name<<endl<<"Thank you for visting Adum Bus Repair Shop,"
               <<busowner1->GetName()<<endl;

               out.close();
               }

               //check file is not in error
              if(!out.goodbit)
                {
                    cout <<"Invoice generated successfully"<<endl;
                    delete bus1;
                    delete busowner1;
                }

                //





            }
            else
            cout <<"Not available in inventory"<<endl;

        }
        else{
            cout <<"No Repair needed"<<"\nBus is not faulty"<<endl;
            return -1;
        }

        }
   else
    ; //null statement








    return 0;
}
