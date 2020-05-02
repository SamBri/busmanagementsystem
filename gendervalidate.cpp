
#include <iostream>
#include <algorithm>


using namespace std;

void Validate(string& valGender)
{
 transform(valGender.begin(), valGender.end(),valGender.begin(),::tolower);
	 
        if(valGender == "male")
	valGender = "male";
	else if(valGender == "female")
           valGender = "female";
          else
	  {
             cout <<"INVALID INPUT:"<<valGender<<endl;
             return;
           }
        
}


int main(int argc, char **argv){	//test gender validation
	string gender = argv[1];
         Validate(gender);
 cout << gender <<endl;

return 0;
}
