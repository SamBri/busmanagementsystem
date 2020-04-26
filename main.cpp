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

    public:
    bool isFaulty = true;
    bool isNew = true;

    /*Operation*/
    //Setters
    public:
    void setBusDetails(string busType, string busMake, string busFault, string regNumber)
    {

        //get bus details
        this->busType = busType;
        this->busMake = busMake;
        this->busFault = busFault;
        this->regNumber = regNumber;

        return;
    }
    //Display bus details;
    void displayBusDetails()
    {
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
    //Setters
    void setBusOwnerDetails(string name, string billingAddress, string gender, int contact){

        this->name = name;
        this->billingAddress = billingAddress;
        this->gender = gender;
        this->contact = contact;
    }

    void displayBusOnwerDetails()
    {
         cout <<name<<endl
          <<billingAddress<<endl<<gender<<endl
          <<contact<<endl;

    }
};

struct PERSON{
    string name;
};

struct REPAIRER{
    struct PERSON repairer;
};

struct HELPER{
struct PERSON helper;
};

struct INVENTORY
{

        map <float,string> parts; //a map of parts and prices.

    public:
     string requestParts(string p){
         map<float,string>::iterator itbeg = parts.begin();
         map<float,string>::iterator itend = parts.end();

         for( ; itbeg != itend; ++itbeg)
            {
                if(itbeg->second == p)
                    return itbeg->second;
                 else
                 {
                     cout <<"not found"<<endl;
                     break;
                 }

            }

            //return parts.find(p)->second;
        }

      float requestPrice(float p){
          return parts.find(p)->first;
      }

};
// TODO (FAMILY PC#1#): inventory list creation
//main function
int main()
{
    //welcome display to end user
    cout <<"*************************************"<<endl;
    cout <<"**WELCOME TO BIG OG BUS REPAIR SHOP**"<<endl;
    cout <<"*************************************"<<endl;

    INVENTORY ogList;
    ogList.parts.insert(pair<float,string>(10.2,"spanner"));
    ogList.parts.insert(pair<float,string>(10.2,"screwdriver"));
    ogList.parts.insert(pair<float,string>(10.2,"bolt"));
    ogList.parts.insert(pair<float,string>(10.2,"headlights"));
    ogList.parts.insert(pair<float,string>(10.2,"sparkplugs"));

    cout << ogList.requestPrice(10);
    cout << ogList.requestParts("bolt");


    //enter bus details
//    string busType, busMake, busFault,regNumber; bool isFaulty;
//    cout <<"Enter bus type:";
//    cin >> busType;
//    cout <<"Enter bus make:";
//    cin >>busMake;
//    cout <<"Enter bus fault:";
//    cin >> busFault;
//    cout <<"Enter registration Number:";
//    cin >> regNumber;
//    cout <<
//
//    //enter bus owner details
//    string name,billingAddress;
//    string gender; long contact;
//    cout <<"Enter Bus owner name:";
//    cin >> name;
//    cout <<"Enter Billing Address:";
//    cin >> billingAddress;
//    cout <<"Enter Gender:";
//    cin >> gender;
//    cout <<"Enter contact number:";
//    cin >> contact;
//
//        //debug bus input values
//      /* cout <<busType<<endl
//        <<busMake<<endl
//        <<busFault<<endl
//        <<regNumber<<endl;
//
//
//        //debug bus owner input values
//         cout <<name<<endl
// *       <<billingAddress<<endl
//         <<gender<<endl
//        <<contact<<endl;
//
//      */
//
//    //Add new bus to the system, all buses are faulty
//    BUS bus1; BUSOWNER busowner1;
//    if(bus1.isNew)
//   {
//    bus1.setBusDetails(busType,busMake,busFault,regNumber); //get bus details
//    busowner1.setBusOwnerDetails(name,billingAddress,gender,contact);
//    busowner1.bus = bus1; // busowner1 came to station with bus1
//
//    //schedule a repair.
//    if(bus1.isFaulty)
//    {
//        //repairer is assigned
//        REPAIRER repairer1;
//        repairer1.repairer.name = "John";
//
//        //Helper is assigned
//        HELPER helper1;
//        helper1.helper.name = "Kwame";
//
//
//    }
//    else
//    {
//    cout <<"Bus with details:";
//    bus1.displayBusDetails();
//    cout <<"Is Okay"<<endl;
//    }
//
//   }
//






    return 0;
}
