//Author: Sam
//Date Started:25th April 2020
//Program: Bus management system

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include<fstream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

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
    string name; //name of busowner
    string firstName;   //first name  of bus owner
    string lastName;    //last name of bus owner
    string billingAddress; //billing address
    string gender; //gender of bus owner
    string contact; //contact of bus owner
    struct BUS bus; // bus details of bus owner.

    /*Operation*/
    //Getters
    string GetFirstName()
    {
        return this->firstName;
    }
    string GetLastName()
    {
        return this->lastName;
    }

    string GetName(){
        return this->name;
    }

    string GetBillingAddres(){
        return this->billingAddress;
    }

    string GetGender(){
        return this->gender;
    }

    string GetContact(){
        return this->contact;
    }


    //Setters
     void SetName(string firstName, string lastName){
        this->name = firstName+" "+lastName;
        //clog << this->name; // name
    }
    void SetFirstName(string firstName){
        this->firstName = firstName;
    }

    void SetLastName(string lastName){
        this->lastName = lastName;
    }

    void SetBillingAddres(string billingAddress){
        this->billingAddress = billingAddress;
    }

    void SetGender(string gender){
     this->gender = gender;
    }

    void SetContact (string contact){
            this->contact = contact;

        }

    void SetBusOwnerDetails(string firstName, string lastName, string billingAddress, string gender, string contact){

        this->name = firstName+" "+lastName;
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

        /*
        clog <<"Before if statement,argument->part:"<<part<<endl;
        */
       if(parts.find(part)->first == part)
       {
        /*clog <<"inside if find request, clog->map parts:"<<parts.find(part)->first << endl;*/
        return true;
       }
   }
    //Setters
   void setRequestedPartPrice(string part, float price)
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
 //;

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


//BUS STATION - (-) NEXT BUILD:multiple buses: Bus owner can have more than one bus hence bus assignment to bus owner has to be dynamic
class BUSSTATION
{
   //

};


/*@FIXME*/
/* FIXME (FAMILY PC#1#04/27/20): Next Build
(-) (1) Insert a measure of control for parts requested and bus fault detected.
(+) (2) Make registration number accepts strings plus whitespaces:
(+) (3) Make billing address accept strings plus whitespaces
(+) (4) Make name to accept strings plus whitespaces
*/

/* DONE: Reference TO @FIXME(04/27/20) (FAMILY PC#1#04/28/20):
(+)(2) Registration number accepts strings plus whitespaces
(+)(3) Billing Address accept strings plus whitespaces
(+)(4) Name is first name and last name for input but displays full name for receipt generation.
*/


/* NOTE (FAMILY PC#1#04/27/20): Refactoring
(-) (1) Bus owner can have more than one bus hence bus assignment to bus owner has to be dynamic
(-) (2) Bus can have more than one faults hence faults should be in a collection or container.
(-) (3) @FIXME (1) Measure of control as to be consider from UI perspective - USABILITY.
*/

/* TODO (FAMILY PC#1#04/28/20): Next Build
VALIDATION: Using a single function() =>
(+)(1) Reject Gender Options(male, female) not provided by system
(+)(2) Reject an Invalid phone number
(-)(3) Rejection of an invalid registration number

LIMITS:
(-) (1) Set Price entry limts

 */

/* DONE Reference TO @TODO(04/28/20) (FAMILY PC#1#05/01/20):
(+) (1) Rejection of invalid gender options implemented
(+) (2) Rejection of invalid phone number implemented

*/

int ValidateGender(string&  valGender)
{
    //change entry to lowercase
 transform(valGender.begin(), valGender.end(),valGender.begin(),::tolower);

        if(valGender == "male")
        valGender = "male";
        else if(valGender == "female")
           valGender = "female";
          else
          {
             cout <<"INVALID INPUT:"<<valGender<<endl;
             return -1;
           }

}



int ValidateContact(string valContact){

    /*check the contact length
        if length is not equal to 10
            then reject
        else
          continue statement
        */
        if(valContact.size() != 10)
        {
            cout <<"PHONENUMBER LENGTH IS INCORRECT"<<endl;
            return -1;
        }
        else
        {
            /*
        break contact into three segments
        for the first segment
        if the code is not equal to registered codes
          reject
          else
          continue statement
    */
        //cout <<"successful"<<endl; confirm phone length checked.
        if(valContact.substr(0,3) == "027");
        else if(valContact.substr(0,3) == "020");
        else if(valContact.substr(0,3) == "024");
        else if (valContact.substr(0,3) == "054");
        else if (valContact.substr(0,3) == "026");
        else
          {
          cout <<"INVALID NETWORK CODE:"<<valContact.substr(0,3)<<endl;
          return -1;
          }
        }

    return 1;

}

#define ERROR -1
//main function
int main()
{
    //welcome display to end user
    cout <<"*************************************"<<endl;
    cout <<"**WELCOME TO ADUM BUS REPAIR SHOP**"<<endl;
    cout <<"*************************************"<<endl;

    INVENTORY adumList; //inventory of parts
    adumList.parts.insert(pair<string, float>("headlight", 0));
    adumList.parts.insert(pair<string, float>("bolt", 0));
    adumList.parts.insert(pair<string, float>("starter", 0));
    adumList.parts.insert(pair<string, float>("engine oil", 0));
    adumList.parts.insert(pair<string, float>("taillight", 0));
    adumList.parts.insert(pair<string, float>("spark plugs", 0));


    //enter bus details
    string busType, busMake, busFault, regNumber; char isBusFaulty, isBusNew;
    cout <<"Enter Bus Type:";
    getline(cin,busType);

    //cout <<busType<< endl; //debug getline

    cout <<"Enter Bus Make:";
    getline(cin,busMake);

    cout <<"Enter Bus Fault:";
    getline(cin,busFault);

    cout <<"Enter Bus Registration Number:";
    getline(cin, regNumber);

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

    /* debug getline inputs
    cerr << "busFault="<<busFault<<endl;
    cerr <<"busMake="<<busMake << endl;
    cerr <<"busType="<< busType <<endl;
    */


    //enter bus owner details
    string firstName,lastName,billingAddress;
    string gender;  string contact;

    cout <<"Enter First Name of bus owner:";
    cin >> firstName;

    cout <<"Enter Last Name of bus owner:";
    cin >> lastName;

    cout <<"Enter Billing Address:";
    cin.ignore();
    getline(cin, billingAddress);

    cout <<"Enter Gender:";
    getline(cin,gender);
    if(ValidateGender(gender) == ERROR)
        return 0; //check gender input.


    cout <<"Enter contact number:";
    cin >> contact;
    if(ValidateContact(contact) == ERROR)
        return 0; //check contact number format.


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
        busowner1->SetName(firstName,lastName);
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
            system("pause"); //new screen for supervisor
            //clear screen
            system("cls"); //move to new screen for supervisor

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

            system("pause"); //new screen for repairer
            system("cls");  //move to new screen for repairer

            cout <<"\t\t***Parts Inventory***"<<endl;
            //find parts
            cout <<"Parts Request."<<endl;
            cout <<"Search requeseted part.."<<endl;
            cout <<"Enter part:"<<endl;
            string parts;
            cin.ignore(); //clear cin buffer
            getline(cin,parts);


            /*
                inserting a measure of control

                -compare the fault detected to the parts requested
                   if they are th same then we can proceed
                    else there is a problem

            */



            //debug parts for strings
            /*
            clog << "Before parts check, clog->parts:"<<parts<<endl;
            */
            if(adumList.FindRequestedPart(parts))
            {
              cout <<"Match Found!"<<endl;
              cout <<"Price requested part:GHC";
              float price;
              //cin.ignore();
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


              ofstream outReceipt("receipt.txt"); //create receipt
              if(!outReceipt)
              {
                  cout <<"Cannot open file. \n";
                  return 1;
              }
               else{
                 outReceipt<<"ADUM BUS REPAIR SHOP INVOICE\n" <<"Date of transaction:"<<timestamp<<endl
               <<"Type of repair:"<<bus1->GetBusFault()<<endl<<"Parts used:"<<adumList.GetRequestedPart(parts)<<endl
               <<"Cost of parts:GHC"<<invoice1.CalculateInovice(adumList,quantity,parts) << endl
               <<"Mechanic assigned:"<<mech.mechanic.name<<endl<<"Helper assigned:"<<help.helper.name<<endl<<"Thank you for visting Adum Bus Repair Shop,"
               <<busowner1->GetName()<<endl;


               }

                //check file status states
            /*  cout <<"good() = " <<outReceipt.good() <<endl;
                cout << "bad() = "<<outReceipt.bad() <<endl;
                cout << "fail() = "<<outReceipt.fail() << endl;
                */

               //check file is not in error
              if(!outReceipt.bad())
                {
                    cout <<"Invoice generated successfully"<<endl;
                    //open receipt
                    system("notepad receipt.txt");
                    delete bus1;
                    delete busowner1;
                }

                  outReceipt.close(); //close receipt file

                  //pause a while
                  system("pause");
            }
            else
            cout <<"Not available in inventory"<<endl;

        }
        else{
            cout <<"No Repair needed"<<"\nBus is not faulty"<<endl;
            system("pause");
            return -1;
        }

        }
   else
    ; //null statement








    return 0;
}
