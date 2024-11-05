// Sorting algorithms

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void selectionSort(){
    // Implementing the selection sort algorithm
    // Algorithm: Select the minimum element in the array and push it to the beginning of the array

    

    /* Example: 
        arr = [2,92,19,2,95,28]
        // step 2: arr = [2, 2, 19, 92, 95, 28]
        // step 4: arr = [2,2,19,28,95,92]
        // step 5: arr = [2,2,19,28,92,95]
        arr = [7, 5, 9, 2 8], n = number of elements = 5
        Step 1: 
        Select the entire array as the range. 
        Run a loop from the first element till the last element i.e, if i is an iterator, range of i is from 0 to arr.size()-1 [n-1]
        Select the minimum element, in this case, 2.
        Swap the first element of the array with the minimum element. The array becomes: 
            arr = [2, 5, 9, 7, 8]
        Clearly, our array is now sorted till the first element or till i = 0;

        Step 2: 
        Now the range is reduced from the first element till the (n-1)th element.
        For our array, the new range is: [5, 9, 7, 8].
        Apply Step 1 again. 
    */

    cout<<"Implementing the selection sort algoorithm."<<endl;

    int n;

    cout<<"Enter the number of terms of the array: ";
    cin>>n;

    vector<int> v;
    cout<<"Enter the elements of the array: ";

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<"The entered array is: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // Implementing selection sort
    // For the implementation, we will use 2 loops
    // The outer loop will be for the selecting the range
    // The inner loop will be for the comparison
    // arr = [7, 5, 9, 2, 8], n = number of elements = 5 => [2,5,9,8,7]
    for(int i = 0; i < v.size()-1; i++){
        int minIdx = i; // for storing index of min. element
        for(int j = i+1; j < n; j++){
            // Compare v[minIdx] and v[j]
            if(v[j] < v[minIdx]){
                // Element smaller than v[minIdx] found
                minIdx = j;
            }
        }
        // Swap the v[minIdx] with v[i] => swapping the minimum element with the first element in the range
        int temp = v[minIdx];// int temp = v[1] = 5
        v[minIdx] = v[i]; // v[1] = v[0] => v[1] = 7
        v[i] = temp; // v{0th element} = v[1] => v[0] = 5 
    }

    cout<<"After Selection Sort, the array is: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // Time complexity: O(n^2) [worst case]
    // Space complexity: O(1)
}

void bubbleSort(){
    // Implementing the Bubble Sort algorithm
    // Algorithm: Comparing adjacent elements and swapping them if necessary

    /* Example: 
         arr =  [13, 46, 24, 52, 20, 9], n = 6
         Iteration 1: 
            Step 1: 
                Select the adjacent element pairs starting from the first element and swap if the 2nd element is lesser than the first
                Our first pair are indices 0 and 1, i.e,  arr  [0] = 13 and arr[1] = 46.
                    arr = [{13, 46}, 24, 52, 20, 19]
                Since, arr[0] < arr[1] => no swap
                    arr = [{13, 46}, 24, 52, 20, 19]
            Step 2: 
                Now, we select the 1st and 2nd element, i.e, arr[1] = 46 and arr[2] = 24 as pairs
                    arr = [13, {46, 24}, 52, 20, 9]
                Since, arr[1] > arr[2] => swap
                    arr = [13, {24, 46}, 52, 20, 9]
            Step 3: 
                Now, selecting the 2nd and the 3rd element
                    arr = [13, 24, {46, 52}, 20, 9]
                Since, arr[i] < arr[i+1] => no swap
                    arr = [13, 24, {46, 52}, 20, 9]
            Step 4: 
                Selecting the 3rd and 4th element
                    arr = [13, 24, 46, {52, 20}, 9]
                Since, arr[i] > arr[i+1] => swap
                    arr = [13, 24, 46, {20, 52}, 9]
            Step 5:
                Selecting the 4th and the 5th element
                    arr = [13, 24, 46, 52, {20, 9}]
                Since, arr[i] > arr[i+1] => swap
                    arr = [13, 24, 46, 52, {9, 20}]
            This marks the end of the 1st iteration
            If we observe carefully, the maximum element has reached its rightful place, i.e, at the end of the array. It means the last element is in its sorted position.

        Iteration 2: 
            For the 2nd iteration, we will reduce the range and cut out the last element. We will proceed as in Step 1.

        **Note:** 
            In bubble sort, the maximum element gets pushed to the end, making it assume its correct place in sorted order.
            The worst time complexity for bubble sort is O(n^2) where the two loops run fully.
            But if the array is already in a sorted order, there is no need to run the algorithm fully and check for pairs
            So, we introduce a variable, say, a boolean to check if any swap has occured in the first iteration[or any subsequent iteration afterwards]. If no swaps take place in a particular iteration, there is no need to continue further. 
    */
    cout<<"Implementing the bubble sort algorithm."<<endl;

    int n;
    cout<<"Enter the number of terms of the array: ";
    cin>>n;

    vector<int> v;
    cout<<"Enter the terms of the array: ";
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<"The terms of the array are: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // Implementing bubble sort
    for(int i = 0; i < v.size()-1; i++){
        bool didSwap = false;
        for(int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                // swap
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;

                didSwap = true;
            }
        }
        if(didSwap == false){
            break;
        }
    }

    cout<<"The array after bubble sort: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // Time Complexity: O(n^2) for the worst case and O(n) for the best case
    // Space Complexity: O(1)
}

void insertionSort(){
    // Implementing the insertion sort algorithm.
    // Taking an element and place it in its correct position

    /*
        Logic:
        1.  Start from left to right.
        2.  Examine each element and compare it to the elemnents to its left
        3.  Insert the element in its correct position in the array.
            To do that, compare the element with the element to its left until
            current element >= left element
        4.  The array will form sorted and unsorted portions.

        Example:
        Given array: arr = {3,2,1}

        1.  For the sub-array, {3}, it is already sorted.
        2.  Now, consider the element 2 and the sub-array, {3,2}.
            2 is not in the correct position ==> swap
            {2,3}
            Resultant array: arr = {2,3,1}
        3.  Now, the element {1} and the sub-array, {2,3,1} 
            1 is compared to the elements on its left until it is in the correct position.
            3 > 1 ==> swap
            arr = {2,1,3}
            Now, compare 1 with the element on its left, 2
            1 < 2 ==> swap
            arr = {1,2,3} which is sorted
    */

    cout<<"Implementing the insertion sort algorithm."<<endl;

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

    cout<<"The terms of the array are: ";
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Implementing the insertion sort algorithm
    for(int i = 0; i <= arr.size() - 1; i++){
       int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout<<"The array after insertion sort: ";
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

/*
        ** Merge Sort**
    
    Merge sort is an algorithm based on the divide and merge (divide and conquer) concept. 
    In this kind of sorting, we divide the given array recursively till the smallest division possible[single element]
    Then we merge the divided arrays in the sorted order.

    **LOGIC**:
    1.  In order to implement merge sort, we need to divide the original array into two parts.
        Rather than making separate arrays, we will use the indices of the original array to make divisions.
    2.  For odd number of terms, the array cannot be divided equally => Use normalinteger division for languages like C++ or Java and for languages like Javascript, use Math.floor() or Math.ceil() to make a division. Hence the division algorithm is:
            Suppose the array is having 7 terms. As 7 is odd, it cannot be divided into 2 equal sub-arrays.
            int arr[7] = {7,3,4,1,2,5,9};
            Declare 3 variables,
            int low = 0;
            int high = n-1; //(n is size of array)
            int mid = (low+high)/2;
            // here mid = (0+7)/2 = 3
        We create sub-arrays as follows:
        i.  arr sub1 from 0th(low) element to (mid) element,
            i.e., 0th element till 3rd element.[4 terms in total].
            arr sub1 = {7,3,4,1};
        ii. arr sub2 from (mid+1) element to n-1(high) element.
            arr sub2 = {2,5,9};

        We create sub-divisions recursively until we get single term arrays.

        **Pseudo code of recursion**
        merge_sort(arr,low,mid) // 1st sub-array[LHS]
        merge_sort(arr,mid+1,high) //2nd sub-array[RHS]

        
    3.  Now, the base case is important to complete the recursive function.
        We can see that we need to stop dividing the array when a given array has only 1 element left.
        For a single element array, low==high. Hence we need to stop at that point.

        The base case is:
        if(low>=high)
        {
            return;
        }

    4.  Merging the sub-arrays.
        a.  While merging, we use a temporary array to store the elements of 
            the two sorted arrays after merging. i.e, left and right sub-arrays.
        b.  For merging the two arrays, we use a 2 pointer approach.
            int left = low;
            int right = mid+1;
        c.  Using a while loop, we compare the elements and append them to a new array
            in sorted array.
            Condition of while loop: while(left<=mid && right<=high)
            We select two elements, one from each half and compare them. The smaller element gets pushed back 
            int the temporary array.
        d.  After that, the remaining elements of either array get copied as it is(because they are already sorted)

    **Psuedo code**:
    merge(arr[], low, mid, high)
    {
        int temp[n]; // n is size of original array
        int left = low; // 1st element to compare from left sub-array
        int right = mid+1; // 1st element to compare from right sub-array

        // comparing the two sub-arrays
        while(left<=mid && right<=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(left);
                left++;
            }
            else // arr[right] > arr[left]
            {
                temp.push_back(right);
                right++;
            }
        }

        // if left sub-array is smaller than right sub-array
        while(right<=high)
        {
            temp.push_back(right);
            right++;
        }

        // if right sub-array is smaller than left sub-array
        while(left<=mid)
        {
            temp.push_back(left);
            left++;
        }

        // inserting from temp array to original array
        for(int i=low; i<=high; i++) // low = 0, high= n-1
        {
            arr[i] = temp[i-low];
        }
    }


    merge_sort(arr[], low, high)
    {
        // base case
        if(low==high)
        {
            return;
        }

        int mid = (low + high)/2;

        // left-sub array
        merge_sort(arr[], low, mid);

        // right sub_array
        merge_sort(arr[], mid+1, high);

        merge(arr, low, mid, high);
    }
*/

void merge(vector<int> &v, int low, int mid, int high){
    vector<int> temp; // temporary array for sorting and merging
    int left = low; // starting index of left half
    int right = mid + 1; // starting index of right half

    // storing the elements in the temporary array in a sorted manner

    while((left <= mid) && (right <= high)){
        if(v[left] <= v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }

    // Case 1: Suppose elements are still remaining in the left half 
    while(left <=  mid){
        temp.push_back(v[left]);
        left++;
    }

    // Case 2: Suppose elements are still remaining in the right half
    while(right <= high){
        temp.push_back(v[right]);
        right++;
    }

    // Transfering all the elements from the temp vector to vector v
    for(int i = low; i <= high; i++){
        v[i] = temp[i - low];
    }
}


void mergeSort(vector<int> &v, int low, int high){
    if(low >= high){
        return;
    }

    // Determine the mid point
    int mid = (low + high)/2;

    // Call the mergeSort recursively for 
    // Case 1: from low to mid (left half)
    mergeSort(v, low, mid);
    // Case 2: from mid + 1 to high (right half)
    mergeSort(v, mid+1, high);

    // Merge the two halves
    merge(v, low, mid, high);

    // Time Complexity: O(n*log n)
    // Space Complexity: O(n)
}

/*
            ** Quick Sort Algorithm **
    **Intuition:
    Quick Sort is a divide-and-conquer algorithm like the Merge Sort. But unlike Merge sort, this algorithm does not use any extra array for sorting(though it uses an auxiliary stack space). So, from that perspective, Quick sort is slightly better than Merge sort.
    This algorithm is basically a repetition of two simple steps that are the following:
    1.  Pick a pivot and place it in its correct place in the sorted array.
    2.  Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.


    Now, let’s discuss the steps in detail considering the array {4,6,2,5,7,9,1,3}:

    Step 1: The first thing is to choose the pivot. A pivot is basically a chosen element of the given array. The element or the pivot can be chosen by our choice. So, in an array a pivot can be any of the following:
            #   The first element of the array
            #   The last element of the array
            #   Median of array
            #   Any Random element of the array

    After choosing the pivot(i.e. the element), we should place it in its correct position(i.e. The place it should be after the array gets sorted) in the array. 
    For example, if the given array is {4,6,2,5,7,9,1,3}, 
                    the correct position of 4 will be the 4th position.

    **Note: Here in this tutorial, we have chosen the first element as our pivot. You can choose any element as per your choice.

    Step 2: In step 2, we will shift the smaller elements(i.e. Smaller than the pivot) to the left of the pivot and the larger ones to the right of the pivot. 
            In the example, if the chosen pivot is 4, after performing step 2 the array will look like: {3, 2, 1, 4, 6, 5, 7, 9}. 
            From the explanation, we can see that after completing the steps, pivot 4 is in its correct position with the left and right subarray unsorted. 
            Now we will apply these two steps on the left subarray and the right subarray recursively. 
            And we will continue this process until the size of the unsorted part becomes 1(as an array with a single element is always sorted).

    So, from the above intuition, we can get a clear idea that we are going to use recursion in this algorithm.

    To summarize, the main intention of this process is to place the pivot, 
    after each recursion call, at its final position, where the pivot should be in the final sorted array.



    **Approach:

    Now, let’s understand how we are going to implement the logic of the above steps. 
    In the intuition, we have seen that the given array should be broken down into subarrays. 
    But while implementing, we are not going to break down and create any new arrays. 
    Instead, we will specify the range of the subarrays using two indices or pointers(i.e. low pointer and high pointer) each time while breaking down the array.

    **The algorithm steps are the following for the Quick Sort algorithm:

    1.  Initially, the low points to the first index and the high points to the last index(as the range is n i.e. the size of the array). 
    2.  After that, we will get the index(where the pivot should be placed after sorting) while shifting the smaller elements on the left and the larger ones on the right 
        using a partition() function discussed later.
    3.  Now, this index can be called the partition index as it creates a partition between the left and the right unsorted subarrays.
    4.  After placing the pivot in the partition index(within the partition() function specified), 
        we need to call the function quickSort() for the left and the right subarray recursively. 
        So, the range of the left subarray will be [low to (partition index – 1)] 
        and the range of the right subarray will be [(partition index + 1) to high]. 
    5   This is how the recursion will continue until the range becomes 1.

    **Pseudo-code for quick sort
    void quick_sort(arr[], int low, int high)
    {
        // checking if the array size is >1
        if(low<high)
        {
            pIndex = partition(arr,low,high);

            // calling quick_sort on left sub-array (elements lesser than pivot)
            quick_sort(arr, low, pIndex-1);

            // calling quick_sort on right sub-array (elements greater than pivot)
            quick_sort(arr, pIndex+1, high);
        }
    }

    **Logic for partition
    Now, let’s understand how to implement the partition() function to get the partition index.

    1.  Inside the function, we will first select the pivot(i.e. arr[low] in our case).
    2.  Now, we will again take two-pointers i and j. 
        The i pointer points to low and the j points to high.
    3.  Now, the pointer i will move forward and find the first element that is greater than the pivot. 
        Similarly, the pointer j will move backward and find the first element that is smaller than the pivot.
        Here, we need to add some checks like i <= high-1 and j >= low+1. 
        Because it might happen that i is standing at high and trying to proceed or j is standing at low and trying to exceed.
    4.  Once we find such elements i.e. arr[i] > pivot and arr[j] < pivot, and i < j, 
        we will swap arr[i] and arr[j].
    5.  We will continue step 3 and step 4, until j becomes smaller than i.
        Finally, we will swap the pivot element(i.e. arr[low]) with arr[j] 
        and will return the index j i.e. the partition index.

    **Pseudo-code for partition index**
    int partition(arr[], int low, int high)
    {
            int pivot = arr[low];
            int i = low;
            int j = high;

            while(i<j) // we have to find the first element from i which is greater than pivot and first element from j less than pivot
            {
                while(arr[i] <= pivot && i <= high-1) // loop stops if arr[i] > pivot
                {
                    i++;
                }
                while(arr[j] > pivot && j >= low+1) // loop stops if arr[j] < pivot
                {
                    j--;
                }

                if(i<j)
                {
                    swap(arr[i], arr[j]);
                }
            }

            swap(arr[low], arr[j]); // swapping pivot to its correct place
        return j; // partition index
    }
*/


int partitionIndex(vector<int> &v, int low, int high){
    // Declaring the pivot element
        // Selecting the first element as the pivot
        int pivot = v[low];
        int i = low;
        int j = high;

        while(i < j){
            // Search for the element just bigger than the pivot on the left side
            while ((v[i] <= pivot) && (i <= high - 1)){
                // keep looking
                i++;
            }
            // Search for the element lesser than the pivot on the right side
            while((v[i] > pivot) && (j >= low + 1)){
                // keep looking
                j--;
            }

            // if we do not find such elements, swap the values of v[i] and v[j]
            if(i < j){
                swap(v[i], v[j]);
            }
        }
        // The pivot element takes its correct position in sorted order
        swap(v[low], v[j]);
    
    return j;
}

void qSort(vector<int> &v, int low, int high){
    if(low < high){
        int pIndex = partitionIndex(v, low, high);

        // Applying quickSort on the left half
        qSort(v, low, pIndex-1);

        // Applying quickSort on the right half
        qSort(v, pIndex+1, high);
    }

}

vector<int> quickSort(vector<int> &v){
        qSort(v, 0, v.size() - 1);

    return v;

    // Time Complexity: O(n*log n)
    // Space Complexity: O(n) 
}

int main(){
    // selectionSort();
    // bubbleSort();
    // insertionSort();

        // cout<<"Implementing the merge sort algorithm."<<endl;

        cout<<"Implementing the quick sort algorithm."<<endl;

        int n;
        cout<<"Enter the number of terms of the array: ";
        cin>>n;

        vector<int> v;
        cout<<"Enter the terms of the array: ";
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            v.push_back(x);
        }

        cout<<"The entered vector is: ";
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

        // Implementing merge sort
        // mergeSort(v, 0, v.size()-1);
        // cout<<"The array after applying merge sort: ";
        // for(int i = 0; i < n; i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;

        // Implementing the merge sort algorithm

        quickSort(v);

        cout<<"The array after Quick Sort is: ";
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    return 0;
}