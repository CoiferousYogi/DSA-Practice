#include <iostream>
#include <utility>
#include <string>
using namespace std;

// this is just the file about C++ STL (Standard Template Library)

/* 
The STL is divided into 4 parts:
1. Containers
2. Functions
3. Iterators
4. Algorithms
*/

void explainPair(){
    // A pair is a container class which combines two values of the same(homogeneous pair) or different data types(heterogeneous pair) in a single unit.
    // Defined under the <utility> header

    // Methods of initializing a pair
    // Method 1: using make_pair method
    //pair<int, string> myPair(24, "Ritwik");

    // Method 2: using the first and second keywords to initialize the variables respectively
    pair<int, int> pair2;
    // pair2.first = 31;
    // pair2.second = 20;

    
    // The elements of a pair can be accessed using the dot(.) operator and the keywords 'first' and 'second' for the first and second variable respectively
    // cout<<myPair.first<<endl;
    // cout<<myPair.second<<endl;
    //cout<<pair2.first<<" "<<pair2.second<<endl;
    
    // The pair is always an ordered pair, i.e, the first variable is always accessed using the first keyword and the second variable is always accessed using the second keyword.


    // Immutability: Once a pair is created, the elements cannot be modified w.r.t the data type.
    // To enforce immutability even on the values, we must use the const keyword.
    //pair2.first = "nsans";
    //cout<<pair2.first; // gives an error: invalid conversion from 'const char*' to 'int' [-fpermissive]

    // Let's do a homogeneous conversion. Will be valid if the variable is not declared using const
    // pair2.first = 92;
    // cout<<pair2.first;

    const std::pair<std::string, int> myPair("Hello", 42);
    //myPair.first = "Hi";  // Error: cannot modify a const object

    // Equality and ordering operators: pair provides overloaded operators for equality (==), inequality (!=), less-than (<), greater-than (>), less-than-or-equal (<=), and greater-than-or-equal (>=) comparisons. These operators compare the first elements of the pairs. 

}

int main(){

        // Before moving on to Containers, we see what is a pair in C++
        explainPair();

        // Part 1: Containers

    return 0;
}
