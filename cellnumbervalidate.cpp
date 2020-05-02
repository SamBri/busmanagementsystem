#include <iostream>
#include <cstdio>

using namespace std;


/*class PHONENUMBER{
//Data Members of phonenumber object	
     unsigned char telcoCode[3];
     unsigned char mid[3];
     unsigned char last[4];
     unsigned char phoneNumber;

 #define MTN 054
#define AirtelTigo 027
#define Vodafone 020	

//operator for reading phonenumber object type
istream &operator>>(istream &is, PHONENUMBER &number)
{

   is >> number.telecoCode[0] >> number.telecoCode[1] >> number.telecoCode[2];
    cout <<" "<<flush;
  
 is >> number.mid[0] >> number.mid[1] >>number.mid[2]; 
	cout <<" "<<flush;
 
is >> number.last[0] >> number.last[1] >> number.last[2] >> number.last[3];
 
	if(is);
          cout << "succcess"<<endl;
         else
             cout <<"failure"<<endl;
 	
	return is;

};
*/



void Validate(char phoneNumber)
{

	
}


int main()
{

//PhoneNumber Solution 1							
/*	//phone number object  of fixed size 10 
	 char phoneNumber[10];         
         //accept inputs
	 cout <<"Enter phoneNumber:"<<endl;
         scanf("%[0-9]s", phoneNumber);
          cout << phoneNumber<<endl;
 */        
//phonenumber solution 2
/*PHONENUMBER contact;
 cout <<"Enter phone number:";
 cin >> contact;
*/

//phonenumber solution 3
  string phonenumber;
   cin >> phonenumber;
      if(phonenumber.size() != 10)
        cout <<"PHONENUMBER LENGTH IS INCORRECT"<<endl;
	else
        cout <<"successful"<<endl;
      if(phonenumber.substr(0,3) == "027");
       else if(phonenumber.substr(0,3) == "020");
	else if(phonenumber.substr(0,3) == "024");
	else if (phonenumber.substr(0,3) == "054");
         else
          cout <<"INVALID NETWORK CODE:"<<phonenumber.substr(0,3)<<endl;
 

}
