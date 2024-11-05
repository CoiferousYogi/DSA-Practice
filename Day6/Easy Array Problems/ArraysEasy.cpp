// Solving easy problems based on arrays

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void largestElementIterative(){
    cout<<"Finding the largest element in an array using iterative method."<<endl;

    int n;
    cout<<"Enter the number of terms of the array: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter the terms of the array: ";
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    // For iterative method, we will loop through each element of the array and check if it is the maximum
    
    int maxEle = arr[0]; // assuming the first element is the biggest
    
    int biggestEle = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > biggestEle){
            biggestEle = arr[i];
        }
    }
    cout<<"The largest element of the array is: "<<maxEle<<endl;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

int largestElementRecursive(vector<int> &arr, int i){
    // Applying the recursion cases for the problem
        // Base case
        if(i == arr.size() - 1){
            return arr[i];
        }

        // Finding the maximum from the rest of the array
        int maxEle = largestElementRecursive(arr, i+1);

    return max(maxEle, arr[i]);

    // Time Complexity: O(n)
    // Space Complexity: O(n) [stack space]
}

void secondSmallestAndSecondLargestBrute(vector<int> &arr){
    // for the brute force method(considering that the array has no repeating elements), we will sort the array in the ascending order. 
    // The 1st element [0-indexing] is the 2nd smallest and the (n-2) th element is the 2nd largest

    // We will use the in-built method to sort the array

        int n = arr.size();

        if((n==0) || (n==1)){
            cout<<"-1"<<endl; // because empty arrays and single element arrays are always sorted.
        }

        // using the in-built method
        sort(arr.begin(), arr.end());
        int sSmall = arr[1];
        int sBig = arr[arr.size() - 2];

        cout<<"The 2nd smallest element is: "<<sSmall<<endl;
        cout<<"The 2nd biggest element is: "<<sBig<<endl;


        // Time Complexity: O(n*log n) // for using in-built sorting method
        // Space Complexity: O(1) // constant extra space used
}

void secondSmallestSecondBiggestBetter(vector<int> &arr){
    // For the better approach, we will iteratively find out the largest and smallest element in the array in one single traversal.
    // Then we traverse the array again and find out the 2nd biggest and 2nd smallest elements.

    // finding the biggest and the smallest elements

    // assuming the 0th and the 1st elements are the smallest and biggest respectively
    int minEle = INT_MAX; 
    int maxEle = INT_MIN;
    for(int  i = 0; i < arr.size(); i++){
        // smallest element
        if(arr[i] < minEle){
            minEle = arr[i];
        }
        // largest element
        if(arr[i] > maxEle){
            maxEle = arr[i];
        }
    }

    cout<<"Max element: "<<maxEle<<endl;
    cout<<"Min element: "<<minEle<<endl;

    // finding the 2nd smallest and 2nd biggest elements
    int sMin = INT_MAX;
    int sMax = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        // for 2nd smallest
        if((arr[i] < sMin) && (arr[i] != minEle)){
            sMin = arr[i];
        }
        // fir 2nd biggest
        if((arr[i] > sMax) && (arr[1] != maxEle)){
            sMax = arr[i];
        }
    }
    cout<<"2nd smallest element: "<<sMin<<endl;
    cout<<"2nd biggest element: "<<sMax<<endl;

    // Time Complexity: O(2*n) => O(n)
    // Space Complexity: O(1)
}

void secondSmallestSecondBiggestOptimal(vector<int> &arr){
    int maxEle = INT_MIN;
    int secondMax = INT_MIN;
    int minEle = INT_MAX;
    int secondMin = INT_MAX;

    int n = arr.size();

    if(n < 2){
        cout<<"-1"<<endl;
    }

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < minEle){
            secondMin = minEle;
            minEle = arr[i];
        }
        else if((arr[i] < secondMin) && (arr[i] != minEle)){
            secondMin = arr[i];
        }
    }

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > maxEle){
            secondMax = maxEle;
            maxEle = arr[i];
        }
        else if((arr[i] > secondMax) && (arr[i] != maxEle)){
            secondMax = arr[i];
        }
    }

    cout<<"The second smallest element is: "<<secondMin<<endl;

    cout<<"The second biggest element is: "<<secondMax<<endl;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

void checkIfArrayisSortedBrute(vector<int> &arr){
    // For the brute force solution, there will be use of two nested loops.
    // The outer loop will pick up the element from the array
    // The inner loop will then compare all the subsequent elements of the array with the outer loop element

    bool sorted = true;

    for(int i = 0; i < arr.size(); i++){
        int currEle = arr[i];

        // inner loop for the comparison element
        for(int j = i+1; j < arr.size(); j++){
            if(currEle > arr[j]){
                sorted = false;
            }
        }
    }
    if(sorted == false){
        cout<<"Unsorted array"<<endl;
    }
    else{
        cout<<"Sorted array"<<endl;
    }
}

void checkIfArrayIsSortedOptimal(vector<int> &arr){
    // We will check if there is a single element which breaks the order in a single pass

    bool isSorted = true;

    for(int i = 1; i < arr.size(); i++){
        
        if(arr[i] < arr[i-1]){
            isSorted = false;
        }
    }

    if(isSorted == true){
        cout<<"Sorted Array"<<endl;
    }
    else{
        cout<<"Unsorted Array."<<endl;
    }
}

int removeDuplicatesSortedArrayBrute(vector<int> &arr){
    // For the brute force method, we will use the data structure called Hash Set which does not take in any duplicate values.

        cout<<"Removing duplicated from an array using Brute force"<<endl;

        // Declaring a hash set
        set <int> s;

        // entering elements of arr in set s
        for(int i = 0; i < arr.size(); i++){
            s.insert(arr[i]);
        }

        int n = s.size();
        int j = 0;
        for(int x : s){ 
            arr[j++] = x;
        }

    return n;

    // Time Complexity: O(n + n*log n)
    // Space Complexity: O(n) // for using hash set
}

int removeDuplicatesSortedArrayOptimal(vector<int> &arr){
    // For the optimal solution, we will be using two pointers method.
    // Initialize 2 pointers, i and j
    // i is placed on the 0th element of the array and j starts from the 1st element of the array
    // j then moves to the subsequent elements of the array and skips the duplicates till it reaches an element such that: 
    //                  arr[j] != arr[i]
    // That element gets printed in the final array. i is updated to take the place of j and i becomes j+1 again.
    // This method works even for unsorted arrays

    int n = arr.size();

    int i = 0;
    for(int j = 1; j < arr.size(); j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }

    return i+1;

    // Time Complexity: O(n) for single pass of array of size n
    // Space Complexity: O(1)
}

vector<int> leftRotationArrayBrute(vector<int> &arr){
    // For the brute force solution, we will create an empty array and then push the elements from the 1st element till the (n-1)st element of the array.

    int n = arr.size();
    vector<int> v(n);
    for(int i = 1; i < arr.size(); i++){
        int x = arr[i];
        v[i - 1] = x;
    }

    v[n - 1] =  arr[0];

    return v;

    // Time Complexity: O(n)
    // Space Complexity: O(n) // for using the extra array
}

vector<int> leftRotationArrayOptimal(vector<int> &arr){
    // Since the rotation is only by 1 place we can easily take out the first element and store it in another variable. Then we can add that again afterwards

        int firstEle = arr[0];

        for(int i = 0; i < arr.size() - 1; i++){
            arr[i] = arr[i+1];
        }
        arr[arr.size()-1] = firstEle;

        // We can also directly apply the swap since it is a single element only.
        // swap(arr[0], arr[arr.size()-1]);
    
    return arr; 
}

vector<int> leftRotationArrayKTimesBrute(vector<int> &arr, int k){
    // Example 1: 
    /*         0,1,2,3,4,5,6
        arr = [1,2,3,4,5,6,7], n = 7, k = 3
            => arr = [5,6,7,1,2,3,4]
    */

   // for the brute force method, we will make a temporary array to store the elements that have to be shifted and then push the elements of the temp array to the main array

   /*
        Note: For an array of size n and being rotated by k places,
            if(k == n) => It gives the same array
            if(k > n) => We perform a modulus operation, k % n where the remainder is the number of places we have to actually rotate.
            For example,
                arr = [1,2,3,4,5,6,7]; n = 7, k = 10
                We can describe 10 left rotation as 7 + 3 left rotations. Which is to say, 7 left rotation returns the same array as the starting one. Hence, it is just net 3 left rotations. 
                To describe that mathematically, it is : 
                    k = 10 % 7 = 3 
                Hence, that calculation must be carried out in the beginning
                Resultant array: 
                    arr = [4,5,6,7,1,2,3]

        For left rotation: 
        1. Copy the first k elements into the temp array.
        2. Shift n - k elements from the last by k positions to the left.
        3. Copy the elements of the temp array into the main array
   */
        int n = arr.size();

        // Ensuring that value of k is within the bounds
        k = k % n;

        // declaring a temp vector to store the first k elements
        vector<int> temp(k);

        // Copying the first k elements of vector arr to vector temp
        for(int i = 0; i < k; i++){
            temp[i] = arr[i];
        }

        // Left shift the other remaining elements in the array by k positions
        for(int i = k; i < n; i++){
            arr[i - k] = arr[i];
        }

        // Place the elements from temp at the end
        for(int i = 0; i < k; i++){
            arr[n - k + i] = temp[i];
        }

        return arr;
    
    // Time Complexity: O(n)
    // Space Complexity: O(k) // for the temp array
}

vector<int> rightRotationArrayKTimesBrute(vector<int> &arr, int k){
    /*For left rotation: 
        1. Copy the first k elements from the back into the temp array.
        2. Shift n - k elements from the beginning by k positions to the right.
        3. Copy the elements of the temp array into the main array
    */
        int n = arr.size();

        if(n == 0 || n == 1){
            return arr;
        }

        k = k % n;

        // making a temporary array for storing the last k elements
        vector<int> temp(k);

        // inserting the last k array elements into temp array
        for(int i = 0; i < k; i++){
            temp[i] = arr[n - k + i];
        }

        // Shifting the elements in the arr to the right by k positions
        for(int i = n - k - 1; i >= 0; i--){
            arr[i + k] = arr[i];        
        }

        // Placing the elements to the beginning of the array
        for(int i = 0; i < k; i++){
            arr[i] = temp[i];
        }
    return arr;

    // Time Complexity: O(n)
    // Space Complexity: O(k) // for the temp array
}

void reverseArr(vector<int> &arr, int left, int right){
    // The algorithm is simple.
    // Start with the extreme ends of the array and swap them. Then increment the left and decrement the right till both left and right cross each other
    while(left <= right){
        // swapping the positions of left and right
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        // increment left and decrement right
        left++;
        right--;       
    }

}

vector<int> leftRotationArrayKTimesOptimal(vector<int> &arr, int k){
    /*
        For Rotating Elements to left
        Step 1: Reverse the first k elements of the array
        Step 2: Reverse the last n-k elements of the array.
        Step 3: Reverse the whole array.            
        For Eg , arr[]={1,2,3,4,5,6,7} , k=2

        We will be making a reverse function reverseArr to reverse the sub-arrays and the array
    */

        int n = arr.size();
        k = k % n;
        // Reversing the first k elements
        reverseArr(arr, 0, k - 1);
        
        // Reversing the last n - k elements
        reverseArr(arr, k, n - 1);

        // Reversing the entire array
        reverseArr(arr, 0, n-1);
    return arr;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

vector<int> rightRotationArrayKTimesOptimal(vector<int>& arr, int k){
    /*
        For Rotating Elements to right
        Step 1: Reverse the last k elements of the array
        Step 2: Reverse the first n-k elements of the array.
        Step 3: Reverse the whole array.            
        For Eg , arr[]={1,2,3,4,5,6,7} , k=2

        We will be making a reverse function reverseArr to reverse the sub-arrays and the array
    */

        int n = arr.size();
        k = k % n;

        // Reversing the last k elements of the array
        reverseArr(arr, n-k, n-1);
        
        // Reversing the first n - k elements
        reverseArr(arr, 0, n-k-1);

        // Reversing the entire array
        reverseArr(arr, 0, n-1);

    return arr;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

vector<int> moveZeroesToEndBrute(vector<int>& arr){
    /*
        You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.
    */
   /*
        Brute Force Solution: Using an extra array to store the non-zero elements and pushing them in the original array from the beginning. 
   */

        int n = arr.size();

        // making a temp array to store non-zero elements
        vector<int> temp;

        // traversing the array to find non-zero elements and to push them to temp
        
        for(int i = 0; i < n; i++){
            if(arr[i] != 0){
                temp.push_back(arr[i]);
            }
        }

        int count = temp.size(); // for keeping count of non-zero elements

        // Making the first count elements as non-zero in arr
        for(int i = 0; i < count; i++){
            arr[i] = temp[i];
        }

        // filling the rest of the places with zeroes
        for(int i = count; i < n; i++){
            arr[i] = 0;
        }

    return arr;

    // Time Complexity: O(n) + O(count) ~ O(2*N)
    // Space Complexity: O(count) or O(n) [worst case]
}

vector<int> moveZeroesToEndOptimal(vector<int>& arr){
    /*
        Optimal Solution: Using 2 pointers technique

        Step 1: Initialize 2 pointers, i and j=-1 such that the j always points to the first zero element in the array.
        Step 2: Using a loop, we will place the pointer j. If no zero is found, we will not continue further. 
        Step 3: If suppose a zero is found, we move the pointer i to j+1 and check if arr[j+1] is a zero or non-zero. 
            **Case a:** arr[i] = arr[j+1] != 0
                        Swap arr[i] and arr[j]. 
                        This will result in j pointing to zero again. Increment j after swap.  
            **Case b:** arr[i] = arr[j+1] == 0
                        Increment j to j+1
    */

        int n = arr.size();
        int j = -1; 

        // placing pointer j to the first zero
        for(int i = 0;  i < n; i++){
            if(arr[i] == 0){
                // first zero found
                j = i;
                break;
            }
        }

        // No zero elements found, i.e., j = -1
        if(j == -1){
            return arr;
        }

        // moving pointers i and j and swapping accordingly
        for(int i = j+1; i < n; i++){
            if(arr[i] != 0){
                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                // increment j
                j++;
            }
        }

    return arr;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

int linearSearch(vector<int> arr, int num){
    //Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

    // traverse the whole array and check each element if it is num
    int ans = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == num){
            ans = i;
            return ans;
        }
    }

    return ans;
}

vector<int> findUnionBrute(vector<int> &arr1, vector<int> &arr2){
    // Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

    // The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

    /*
        Brute force approach: Using a map [ordered map]
        Our aim is to find the elements common to both arr1 and arr2. 
    */

        int n = arr1.size();
        int m = arr2.size();

        // Declaring a vector to store the union
        vector<int> uni;

        // Declaring a map to store the frequency of the elements
        map <int, int> freq;

        // adding elements of arr1 to map freq
        for(int i = 0; i < n; i++){
            freq[arr1[i]]++;
        }

        // adding elements of arr2 to the map freq
        for(int i = 0; i < m; i++){
            freq[arr2[i]]++;
        }

        for(auto & it: freq){
            uni.push_back(it.first);
        }

    return uni;

    // Time Complexity: O((n+m)*log(n+m))
    // Space Complexity: O(n+m)
}

vector<int> findUnionBruteSet(vector<int> &arr1, vector<int> &arr2){
    // This is also a brute force solution, but it uses set instead of map

    int n = arr1.size();
    int m = arr2.size();

    // A set automatically drops repeated values
    // Declaring a set for the union
    set <int> s;

    vector<int> uni;

    // pushing the elements of arr1 to set s
    for(int i = 0; i < n; i++){
        s.insert(arr1[i]);
    }

    // pushing the elements of arr2 to set s
    for(int i = 0; i < m; i++){
        s.insert(arr2[i]);
    }

    for(auto & it:s){
        uni.push_back(it);
    }

    return uni;

    // Time Complexity: O((n+m)*log(n+m))
    // Space Complexity: O(n+m)
    
}

vector<int> findUnionOptimal(vector<int> &arr1, vector<int> &arr2){
    // for the optimal solution, we will use 2 pointers
    // But there is a bit of an issue. 
    /*
        The brute force solution works for both sorted and unsorted arrays. 
        But in this case, we will assume that the arrays are not sorted. Hence the time complexity will be worse than if the arrays were sorted. 
    */

        int n = arr1.size();
        int m = arr2.size();

        // First, we will sort the two arrays using in-built sorting method
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        // intitialize two pointers i and j to zero
        int i = 0; // for arr1
        int j = 0; // for arr2

        vector<int> uni; // declaring an array for the union

        while((i < n) && (j < m)){
            if(arr1[i] < arr2[j]){
                uni.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i] > arr2[j]){
                uni.push_back(arr2[j]);
                j++;
            }
            else{
                // both are equal
                uni.push_back(arr1[i]);
                i++;
                j++;
            }
        }

        // suppose there are elements remaining in arr1
        while(i < n){
            uni.push_back(arr1[i]);
            i++;
        }

        // suppose there are elements remaining in arr2
        while(j < m){
            uni.push_back(arr2[j]);
            j++;
        }
    
    return uni;

    // Time Complexity: O(n + m)
    // Space Complexity: O(n + m)
}

int missingNumber(vector<int> &arr, int N){
    // Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

    // Brute force approach: For the brute force approach we will search the array using linear search and find the missing number.

        
        for(int i = 1; i <= N; i++){
            // declaring a variable to flag the missing number
            int flag = 0;

            // searching the element using linear search
            for(int j = 0; j < N - 1; j++){
                if(arr[j] == i){
                    // i is present in the array
                    flag = 1;
                    break;
                }
            }
            // suppose for some i, flag = 0 => i is not present in the array => i is the missing number
            if(flag == 0){
                return i;
            }
        }
    
    return -1;

    // Time Complexity: O(n^2) [worst case scenario]
    // Space Complexity: O(1)
}

int missingNumberOptimal1(vector<int> &arr, int N){
    // For the first optimal approach we will be using the property of the sum of first n natural numbers

        // Step 1: Calculate the sum of the N natural numbers
        int naturalSum = (N*(N+1))/2;

        // Step 2: Sum up all the elements of the array
        int arrSum = 0;

        for(int i = 0; i < arr.size(); i++){
            arrSum += arr[i]; 
        }

        int diff = naturalSum - arrSum;

    return diff;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

int missingNumberOptimal2(vector<int> &arr, int N){
    // Using XOR
    /*
        Two important properties of XOR are the following:

        1. XOR of two same numbers is always 0 i.e. a ^ a = 0.
        2. XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.

        Now, let’s XOR all the numbers between 1 to N.
        xor1 = 1^2^.......^N
    */

        int xor1 = 0;
        int xor2 = 0;

        for(int i = 0; i < N - 1; i++){
            xor2 = xor2 ^ arr[i]; // xor of the elements of array
            xor1 = xor1 ^ (i+1); // xor up to [1.....N-1]
        }

        xor1 = xor1 ^ N; 

    return (xor1 ^ xor2);
}

int maximumConsecutiveOnes(vector<int> &arr){
    // Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

        int count = 0; // for counting the number of 1's
        int maxCount = 0; // gets updated with the maximum count till i

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 1){
                count++;
            }
            else{
                // reset count if arr[i] != 1
                count = 0;
            }

            // after every iteration check if maxCount is less than count and if it is, update maxCount
            maxCount = max(count, maxCount);
        }
    return maxCount;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

int getSingleElementBrute(vector<int> & arr){
    // Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.
    
    // For the brute force method, we will apply a linear search over the whole array and count the number of occurences of each element.
        int n = arr.size();

        int ans = -1;
        for(int i = 0; i < n; i++){
            int currNum = arr[i];
            int count = 0;

            for(int j = 0; j < n; j++){
                if(arr[j] == currNum){
                    count++;
                }
            }
            if(count == 0){
                ans = currNum;
            }
        }

    return ans;

    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
}

int getSingleElementBetterMap(vector<int> &arr){
    // The better way to solve the problem is to use a map or to use hashing
    // In  this function, we will use the map

        int n = arr.size();

        map<int, int> freq;

        int ans = -1;

        // Pushing elements of array to the map
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }

        // finding the single element
        for(auto it: freq){
            if(it.second == 1){
                ans = it.first;
            }
        }
    return ans;

    // Time Complexity: O(n*log m) + O(m) 
        // where, m = size of map 
}

int getSingleElementOptimal(vector<int> &arr){
    // For the optimal approach, we will be using the xor operation 
    // Given the condition of the array, if we xor all the elements of the array, we will be left only with the single element

        int n = arr.size();
        int xorr1 = 0;
        
        // applying xor to all the elements of the array
        for(int i = 0; i < n; i++){
            xorr1 = xorr1 ^ arr[i];
        }

    return xorr1;
}

int longestSubarrayWithSumKPositivesBrute(vector<int> &arr, int k){
    // Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

    // For the brute force approach, we will generate all the possible subarrays of the given array and then calculate the sum of the subarrays.

        int n = arr.size();

        int len = 0; // for the length of the subarray

        // outer loop selects the starting index of subarray
        for(int  i = 0; i < n; i++){
            // inner loop selects the ending index of the subarray
            for(int j = i; j < n; j++){
                int sum = 0;

                // summing up all the elements from i to j
                for(int q = i; q <= j; q++){
                    sum += arr[q];
                }
                 // checking if sum == k
                if(sum == k){
                    len = max(len, j-i+1);
                }
            } 
        }
    return len;
}

int longestSubarrayWithSumKPositivesBruteOptimised(vector<int> &arr, int k){
    // we can optimize the brute force method by using the second loop for selecting the current element as well as the ending index of the subarrays

        int n = arr.size();
        int len = 0;

        // outer loop for selecting the starting index
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];

                if(sum == k){
                    len = max(len, j-i+1);
                }
            }
        }
    return len;
}

int longestSubarrayWithSumKPositivesBetter(vector<int> &arr, int k){
    // For the better approach we will use maps and prefix sums
    /*
        Algorithm:
        
    */

        int n = arr.size();

        map<int, int> prefixSum;
        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];

            if(sum == k){
                maxLen = max(maxLen, i+1);
            }

            // calculating the sum of the remaining part
            int rem = sum - k;

            if(prefixSum.find(rem) != prefixSum.end()){
                int len = i - prefixSum[rem];
                maxLen = max(maxLen, len);
            }

            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
    return maxLen;
}

int longestSubarrayWithSumKPositivesOptimal(vector<int> &arr, int k){
    // for the optimal solution, we will use the two pointers method

        int n = arr.size();

        int left = 0;
        int right = 0;
        int maxLen = 0;
        int sum = 0;

        while(right < n){
            // if sum > k, reduce the subarray from the left until sum <= k
            while(left <= right && sum > k){
                sum -= arr[left];
                left++;
            }

            // if sum == k, update maxLen
            if(sum == k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;

            if(right < n){
                sum += arr[right];
            }
        }
    
    return maxLen;
}

// int longestSubarrayWithSumKBrute(vector<int> &arr, int k){      
//         // for the brute force approach, we will generate all the possible subarrays of the given array and check for the subarray sum
//         int n = arr.size();
//         int maxLen = 0;   
      

//         // outer loop for the starting index
//         for(int i = 0; i <n; i++){
//             for(int j = i; j < n; j++){
//                 int subArraySum = 0;

//                 // add all elements from i to k
//                 for(int h = i; h <= j; h++){
//                     subArraySum += arr[h];
//                 }
//                 // check if the sum is equal to k
//                 if(subArraySum == k){
//                     maxLen= max(maxLen, j - i + 1);
//                 }
//             }
//         }
    
//     return maxLen;

//     // Time Complexity: O(N^3) // because of 3 nested loops
//     // Space Complexity: O(1)
// }

int longestSubarrayWithSumKBrute(vector<int> &arr, int k){
    // for the better approach we will optimise the 3 loops and reduce it to 2 loops

        int maxLen = 0;
        int n = arr.size();

        // Outer loop for the starting index
        for(int i = 0; i < n; i++){
            // the inner loop will be for the elements getting added to the sum
            int subArraySum = 0;
            for(int j = i; j < n; j++){
                subArraySum += arr[j];

                if(subArraySum == k){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
    return maxLen;
}

int longestSubarrayWithSumKOptimal(vector<int> &arr, int k){
        int n = arr.size();
        int subArrSum = 0;
        int maxLen = 0;

        // creating a map to store all the prefix sums
        map<int, int> preSum;

        for(int i = 0; i < n; i++){
            subArrSum += arr[i];

            if(subArrSum == k){
                maxLen  = max(maxLen, i + 1);
            }

            int rem = subArrSum - k;

            if(preSum.find(rem) != preSum.end()){
                int len = i - preSum[rem];
                maxLen = max(len, maxLen);
            }

            if(preSum.find(subArrSum) == preSum.end()){
                preSum[subArrSum] = i;
            }
        }

    return maxLen;
}

int main(){
        //largestElementIterative();

        // cout<<"Finding the largest element in an array using recursive method."<<endl;

        int n1;
        cout<<"Enter the number of terms of the 1st array: ";
        cin>>n1;

        vector<int> arr1;
        cout<<"Enter the terms of the array: ";
        for(int i = 0; i < n1; i++){
            int x;
            cin>>x;
            arr1.push_back(x);
        }

        // int n2;
        // cout<<"Enter the number of terms of the 2nd array: ";
        // cin>>n2;

        // vector<int> arr2;
        // cout<<"Enter the terms of the 2nd array: ";
        // for(int i = 0; i < n2; i++){
        //     int x;
        //     cin>>x;
        //     arr2.push_back(x);
        // }


        // int num;
        // cout<<"Enter the value of number to be searched: ";
        // cin>>num;

        //cout<<"The largest element in the array is: "<<largestElementRecursive(arr, 0)<<endl;

        //secondSmallestSecondBiggestOptimal(arr);

        //checkIfArrayisSortedBrute(arr);

        //checkIfArrayIsSortedOptimal(arr);

        //int k = removeDuplicatesSortedArrayBrute(arr);
        // int k = removeDuplicatesSortedArrayOptimal(arr);
        // cout<<"After removing duplicates, the array is: ";
        // for(int i= 0; i < k; i++){
        //     cout<<arr[i]<<" ";
        // }

        // vector<int> ans = leftRotationArrayOptimal(arr);
        // cout<<"The array after left rotation by 1 place: ";
        // for(int i = 0; i < ans.size(); i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        // vector<int> ans = rightRotationArrayKTimesOptimal(arr, k);

        // cout<<"Array after right rotation by k places: ";
        // for(int i = 0; i < ans.size(); i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        // vector<int> ans = moveZeroesToEndOptimal(arr);

        // cout<<"Array after moving zeroes to the end: ";
        // for(int i = 0; i < ans.size(); i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        //int ans = linearSearch(arr, num);

        // if(ans == -1){
        //     cout<<"Element not found in the array."<<endl;
        // }
        // else{
        //     cout<<"The index of "<<num<<" in array is: "<<ans<<endl;
        // }

        // vector<int> uni = findUnionBrute(arr1, arr2);

        // cout<<"The union of 2 arrays are: ";
        // for(int i = 0; i < uni.size(); i++){
        //     cout<<uni[i]<<" ";
        // }
        // cout<<endl;

        // int N;
        // cout<<"Enter the value of N: ";
        // cin>>N;

        // vector<int> a = {1, 2, 4, 5};
        // int ans = missingNumber(a, N);
        // cout << "The missing number is: " << ans << endl;

        // int ans = maximumConsecutiveOnes(arr1);

        // cout<<"Maximum consecutive 1's: "<<ans<<endl;

        largestElementIterative();
    return 0;
}