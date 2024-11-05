// Basic math problems

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
int countDigitsBrute(int n){
        // Brute force approach. Just keep on dividing the number by 10 till it reaches 0
        int digits  = 0;

        while(n > 0){
            n = n/10;
            digits++;
        }
        
    return digits;
    // Time complexity: O(n)
    // Space complexity: O(1) => no extra space taken
}

int countDigitsOptimal(int n){

        // The log base 10 of a number gives us the count of digits present in a number
        // Using log10(n) + 1

        int digits = (int) (log10(n) + 1);
    return digits;
    // Time Complexity: O(1)
    // Space Complexity: O(1)
}

int reverseNumber(int n){
    // Step 1: Getting the digits of the number:
    int reverseNum = 0;

    while(n > 0){
        int lastDigit = n % 10;  
        reverseNum = (reverseNum * 10) + lastDigit;
        n = n/10;
    }
    return reverseNum;
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
}

bool isNumberPallindrome(int n){
    // Storing the value of n in a different variable
    int duplicate = n;
    // Step 1: Getting the reverse of the number
    int reverse = 0;

    while(n > 0){
        int lastDigit = n % 10;
        reverse = (reverse * 10) + lastDigit;
        n = n/10;
    }
    if(reverse == duplicate){
        return true;
    }
    else{
        return false;
    }
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
}

int gcdOfTwoNumbersBrute(int n, int m){
    int minNum = min(n, m);
    // We will iterate from 1 till the minimum between n and m and check if each number is a common factor of both input numbers.
    // If a number is a common factor, we will update the gcd or the ans variable accordingly.

    int gcd = 1;
    for(int i = 1; i <= minNum; i++){
        if((n % i == 0) && (m % i == 0)){
            gcd = i;
        }
    }

    return gcd;

    // Time Complexity: O(min(n, m))
    // Space Complexity: O(1)
}

int gcdOfTwoNumbersBetter(int n, int m){
        int minNum = min(n, m);

        int gcd = 1;

        for(int i = minNum; i >= 1; i--){
            if((n % i == 0) && (m % i == 0)){
                gcd = i;
            }
        }
    return gcd;
    // Time Complexity: O(min(n, m)) [worst case]
    // Space Complexity: O(1)
}

int gcdofTwoNumbersOptimal(int n, int m){
    // Using Euclidean algorithm
    
        while((n > 0) && (m > 0)){
            // if n > m, m = n % m
            // i.e, subtracting m from n
            if(n > m){
                n = n % m;
            }
            // if m >= n, then m = m % n
            else{
                m = m % n;
            }
        }
        if(n == 0){
            return m;
        }
    return m;
}

bool isArmstrong(int num) {
    // Calculate the number of
    // digits in the given number
    int k = to_string(num).length();
    // Initialize the sum of digits
    // raised to the power of k to 0
    int sum = 0;
    // Copy the value of the input
    // number to a temporary variable n
    int n = num;
    // Iterate through each
    // digit of the number
    while(n > 0){
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Add the digit raised to
        // the power of k to the sum
        sum += pow(ld, k); 
        // Remove the last digit
        // from the number
        n = n / 10;
    }
    // Check if the sum of digits raised to
    // the power of k equals the original number
    return sum == num ? true : false;
}

int* printDivisorsBrute(int n, int &size){
    // Allocate an empty array of size [size]
        int *divisors = new int[n];
        int count = 0;
        
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                divisors[count++]  = i;
            }
        }

        size = count;
    return divisors;

    // Time Complexity: O(n)
    // Space Complexity: O(n)
}

void printDivisorsOptimal(int n){
    vector<int> divisors;
    

    int squareRoot = sqrt(n); 

    for(int i = 1; i <= squareRoot; i++){
        if(n % i == 0){
            divisors.push_back(i);

            if(i != n/i){
                divisors.push_back(n/i);
            }
        }
    }

    cout<<"The divisors of "<<n<<" are: ";
    for(int divisor : divisors){
        cout<<divisor<<" ";
    }
    cout<<endl;
    
    // Time Complexity: O(sqrt(n))
    // Space Complexity: O(2*sqrt(n))
}

void determinePrimeOrNotBrute(int n){
    // Given an integer N, check whether it is prime or not. 
    // For the brute force approach we will iterate through all the numbers from 1 till n and check if any number is a divisor of the number n

        int count = 0;

        if(n == 1){
            cout<<"The number 1 is neither prime nor composite."<<endl;
            return;
        }

        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                count++;
            }
        }

        if(count == 2){
            cout<<"The number "<<n<<" is prime."<<endl;
        }
        else{
            cout<<"The number "<<n<<" is composite."<<endl;
        }
    
    // Time complexity: O(n)
    // Space complexity: O(1)
}

void determinePrimeorNotOptimal(int n){
    // For the optimal method, we will run the loop till the square root of n only.

    if(n == 1){
        cout<<"The number 1 is neither prime nor composite."<<endl;
        return;
    }

    int count = 0;
    int sqrtNum = sqrt(n);
    for(int i = 1; i <= sqrtNum; i++){
        if(n % i == 0){
            count++;
        }
    }

    if(count == 2){
        cout<<"The number "<<n<<" is prime."<<endl;
        return;
    }
    else{
        cout<<"The number "<<n<<" is composite."<<endl;
        return;
    }

    // Time complexity: O(sqrt(n))
    // Space complexity: O(1) : since we did not use any extra space

}

int main(){

        // 1. Count the number of digits in a number
        int n;
        cout<<"Enter a number: ";
        cin>>n;

        // cout<<"The number of digits by brute force method: "<<countDigitsBrute(n)<<endl;

        // cout<<"The number of digits by using optimal method: "<<countDigitsOptimal(n);

        // cout<<"The reversed number is: "<<reverseNumber(n);

        // bool ans = isNumberPallindrome(n);
        // if(ans == true){
        //     cout<<"The number is a pallindrome."<<endl;
        // }
        // else{
        //     cout<<"The number is not a pallindrome."<<endl;
        // }

        // GCD or HCF of 2 numbers
        // int m;
        // cout<<"Enter a second number: ";
        // cin>>m;

        // cout<<"The gcd of "<<n<<" and "<<m<<" using brute force is: "<<gcdOfTwoNumbersBrute(n, m)<<endl;

        // cout<<"The gcd of "<<n<<" and "<<m<<" using better approach is: "<<gcdOfTwoNumbersBrute(n, m)<<endl;

        //  cout<<"The gcd of "<<n<<" and "<<m<<" using better approach is: "<<gcdofTwoNumbersOptimal(n, m)<<endl;

        // bool ans = armstrongNumberOrNot(n);

        // if (isArmstrong(n)) {
        //     cout << n << " is an Armstrong number." << endl;
        // } else {
        //     cout << n << " is not an Armstrong number." << endl;
        // }

        // int size;
        // int *divisors = printDivisorsBrute(n, size);

        // cout<<"The divisors of: "<<n<<" are: ";
        // for(int i = 0; i < size; i++){
        //     cout<<divisors[i]<<" ";
        // }
        // cout<<endl;

        // delete[] divisors;

        //printDivisorsOptimal(n);

        determinePrimeOrNotBrute(n);

    return 0;
}


