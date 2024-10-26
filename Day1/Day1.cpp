#include <iostream>
#include <string>
#include <array>
using namespace std;

// int main(){
//         int x;
//         cout<<"Enter a number: ";
//         cin>>x;
        
//         cout<<"The number entered is: "<<x<<endl;
//     return 0;
// }


// Data Types
/*  1. int (Integer) 
        Range: -2^(31) to +2^(31)-1
    2. long (just like int but wider range)

    3. unsigned long (just like long but has no negative values so even more range on +ve side)

    4. long long (biggest range)

    5. float (just like int but allows decimal points)

    6. double (float with wider range)

    7. sting(an array of characters)

    8. char(for storing characters)

*/

// string 

// a void function to just print the name
void printName(){
        string name;
        cout<<"Enter your name: ";
        getline(cin, name);
        cout<<"Your name is: "<<name;

    return;
}

int addNumbers(){
        int a, b;
        cout<<"Enter 2 numbers to add respectively: ";
        cin>>a>>b;

        cout<<"The addition of "<<a<<" and "<<b<<" is: "<<a+b;
    return 0;
}

int main(){
        // string s1; 
        // // cout<<"Enter a string without spaces: ";
        // // cin>>s1;

        // // Entering a string with spaces
        // cout<<"Enter a string with spaces: ";
        // getline(cin, s1);

        //cout<<"String is: "<<s1<<endl;

        // if else statement
        // int age;
        // cout<<"Enter your age: ";
        // cin>>age;
        // if(age >= 18){
        //     cout<<"Adult."<<endl;
        // }
        // else{
        //     cout<<"Not an Adult."<<endl;
        // }

        // Arrays
        // int n;
        // cout<<"Enter number of terms of the array: ";
        // cin>>n;

        // Functions
        // void functions non parameterized
        //printName();

        // parameterized functions make an addition function
        // int x = 9;
        // int y = 10;

        addNumbers();
       
    return 0;
}
