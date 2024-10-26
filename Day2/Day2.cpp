#include <iostream>
using namespace std;

void simpleSquare(int n){
    for(int i = 0; i < n; i++)
    {
        for(int j = 0;  j < n; j++)
        {
            cout<<" * ";
        }
        cout<<endl;
    }
}

void simpleTriangle(int n){
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j<=i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void numberedSimpleTriangle(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j <= i){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void rightAngledNumberedPyramid(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j <= i){
                cout<<i;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void invertedRightPyramid(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + j < n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void invertedNumberedRightPyramid(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i + j <= n){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void leftHalfPyramidPattern(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j <= i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void leftHalfInvertedPyramidPattern(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout<<"*";
        }
        for(int k = 0; k <=i; k++){
            cout<<" ";
        }
        cout<<endl;
    }

}

void erectPyramidPattern(int N){
     for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=0;j< 2*i+1;j++){
            
            cout<<"*";
        }
        
        // For printing the spaces after the stars in each row
         for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
        
        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}

void invertedPyramidPattern(int N){
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=0;j< 2*N -(2*i +1);j++){
            
            cout<<"*";
        }
        
        // For printing the spaces after the stars in each row
         for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
        
        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}

void binaryNumberSimpleLeftSidedTrianglePattern(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if((i+j)%2 == 0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

void numberedCrownPattern(int n){

    for(int i = 1; i <= n; i++){
        // 1st loop for numbers
        int spaces = 2*(n-i);
        for(int j = 1; j <= i; j++){
            cout<<j;
        }
        // for spaces in between
        for(int k = 1; k <= spaces; k++){
            cout<<" ";
        }
        for(int j = i; j >= 1; j--){
            cout<<j;
        }
        cout<<endl;
    }
}

void increasingNumberTrianglePattern(int n){
    int val = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<val<<" ";
            val++;
        }
        cout<<endl;
    }
}

void increasingLetterTrianglePattern(int n){
    for(int i = 0; i < n; i++){
        // loop for characters in column
        for(char ch = 'A'; ch <= 'A'+i; ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void reverseLetterTrianglePattern(int n){
    for(int i = 0; i < n; i++){
        // inner loop for columns
        char ch = 'A';
        for(int j = 0; j < n-i; j++){
            int ans = ch + j;
            cout<<(char)ans; // typecasting the variable ans from ASCII to char
        }
        cout<<endl;
    }
}

void alphaRampPattern(int n){
    // This is just like the simple triangle pattern in which every column value is the row number but with letters
    for(int i = 0; i < n; i++){
        // defining the character for each row
        for(char ch =('A'+n-1)-i;ch<=('A'+n-1);ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void alphaHillPattern(int n){
    // This is just the pyramid patter with letters
    // For the character loop, we define the breakpoint till where the character must increase and after that, it must decrease. The breakpoint can be defined by (2*i+1)/2 for each row.
    
    for(int i = 0; i < n; i++){
        // defining the char for each row
        char ch = 'A';
        int breakpoint = (2*i+1)/2;

        // 1st inner loop for the spaces
        for(int j = 0; j < (n-i)-1; j++){
            cout<<" ";
        }

        // 2nd inner loop for characters
        for(int k = 1; k <= (2*i)+1; k++){
            cout<<ch;
            if(k <= breakpoint){
                ch++;
            }
            else{
                ch--;
            }
        }

        // 3rd loop for spaces
        for(int j = 0; j < (n-i)-1; j++){
            cout<<" ";
        }

        cout<<endl;
    }
}

void alpahReversedTrianglePattern(int n){
    // This pattern is simple: we just have to print the characters in reverse order but in style of simple triangle

    for(int i = 0; i < n; i++){
        for(char ch =('A'+n-1)-i;ch<=('A'+n-1);ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void symmetricVoidPattern(int n){
   
    
    int upperSpaces = 0;
    int lowerSpaces = (2*n)-2;

    // upper part
    for(int i = 0; i < n; i++){
        // 1st inner loop for stars
        for(int j = 1; j <= n-i; j++){
            cout<<"*";
        }
        // 2nd inner loop for spaces
        for(int k = 0; k < upperSpaces; k++){
            cout<<" ";
        }
        // 3rd inner loop for stars
        for(int j = 1; j <= n-i; j++){
            cout<<"*";
        }
        upperSpaces += 2;
        cout<<endl;
    }

    // lower part
    for(int i = 0; i < n; i++){
        // 1st inner loop for stars
        for(int j = 0; j < i+1; j++){
            cout<<"*";
        }
        // 2nd inner loop for spaces
        for(int k = 0; k < lowerSpaces; k++){
            cout<<" ";
        }
        // 3rd inner loop for stars
        for(int j = 0; j < i+1; j++){
            cout<<"*";
        }
        lowerSpaces -= 2;
        cout<<endl;
    }
}

void symmetricButterflyPattern(int n){
      int spaces = 2*n-2;
      
      // Outer loop for printing rows
      for(int i = 1; i <= 2*n-1; i++){
        // stars for upper half
        int stars = i;
        
        // stars for lower half
        if(i > n){
            stars = 2*n - i;
        }

        // 1st inner loop for stars
        for(int j = 1; j <= stars; j++){
            cout<<"*";
        }

        // 2nd inner loop for spaces
        for(int k = 1; k <= spaces; k++){
            cout<<" ";
        }

        // 3rd inner loop for stars
        for(int j = 1; j <= stars; j++){
            cout<<"*";
        }
        cout<<endl;
        if(i < n){
            spaces -= 2;
        }
        else{
            spaces += 2;
        }
      }
}

void hollowRectanglePattern(int n){
    // In hollow rectangle pattern, the first and the last row have all the columns filled.
    // All other rows have only the first and last columns filled.
    // i.e, the stars exist only if i==0, j==0, i==(n-1), j==(n-1)
    // in all other cases we see only blank spaces

    // outer loop for number of rows
    for(int i = 0; i < n; i++){
        // 1st inner loop for number of columns
        for(int j = 0; j < n; j++){
            // 2nd inner loop for conditional printing of stars
            if((i==0) || (j==0) || (i==(n-1)) || (j==(n-1))){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void repeatingNumberPattern(int n){
    // In this pattern, we must observe the numbers carefully.

    /*
        For n = 5,

        5 5 5 5 5 5 5 5 5
        5 4 4 4 4 4 4 4 5
        5 4 3 3 3 3 3 4 5
        5 4 3 2 2 2 3 4 5
        5 4 3 2 1 2 3 4 5
        5 4 3 2 2 2 3 4 5
        5 4 3 3 3 3 3 4 5
        5 4 4 4 4 4 4 4 5
        5 5 5 5 5 5 5 5 5
    */

    // Starting with a similar pattern (for n = 4)
    /*
        0 0 0 0 0 0 0
        0 1 1 1 1 1 0
        0 1 2 2 2 1 0
        0 1 2 3 2 1 0
        0 1 2 2 2 1 0
        0 1 1 1 1 1 0
        0 0 0 0 0 0 0
    */
    // For the above pattern, any cell (i,j), the value present at that cell is calculated as the minimum distance of the cell from all the four directions
    // For example, for the cell (0,0) for a pattern with n = 5, the minimum distance from the other corners,
    // i.e., from the right and the bottom is 4. Hence, the value for the cell is calculated as: 
    //      Value at (0,0) = min(undefined [distance from top], undefined [distance from left], 4 [distance from right], 4[distance from bottom]) => 4
    //(We will not consider the distance from top and left as these are out of bounds for the current cell according to the pattern.)
    // Similarly, we for cell (1,3), the distances from top, left, right and bottom are 1, 3, 3, 5 respectively. Hence,
    //      Value at (1,3) = min (1, 3, 3, 5) => 1


    // For the concerned pattern however, it is the opposite. We need the maximum distance so we subtract the min from the value of n 
    // The distance from top is just the row number (i)
    // The distance from the left is just the column number (j)
    // The distance from the right is just (2*n -2) - j
    // The distance from the bottom is (2*n - 2) - i

     // Outer loop for no. of rows
     for(int i=0;i<2*n-1;i++){
         
         // inner loop for no. of columns.
         for(int j=0;j<2*n-1;j++){
             
            // Initialising the top, down, left and right indices of a cell.
            int top = i;
            int bottom = j;
            int right = (2*n - 2) - j;
            int left = (2*n - 2) - i;

            cout<<(n- min(min(top,bottom), min(left,right)))<<" ";
         }
         cout<<endl;
     }
}

int main(){

        int n;
        cout<<"Enter the number of rows: ";
        cin>>n;
        // Pattern 1: Simple Square
        // simpleSquare(n); 

        // Pattern 2: Simple Triangle
        // simpleTriangle(n); 

        // Pattern 3: Numbered Simple Triangle
        // numberedSimpleTriangle(n);

        // Pattern 4: Right angled numbered pyramid
        // rightAngledNumberedPyramid(n);

        // Pattern 5: Inverted left half pyramid pattern
        // invertedRightPyramid(n);

        // Pattern 6: Inverted Numbered Right Pyramid
        // invertedNumberedRightPyramid(n);
        
        // Pattern 7: Full Pyramid Pattern
        // erectPyramidPattern(n);

        // Pattern 8: Inverted full Pyramid
        // invertedPyramidPattern(n);

        // Pattern 9: Diamond pattern
        // Upper loop as per pattern 7
        //erectPyramidPattern(n);
        //Lower loop as per pattern 8 but till n
        //invertedPyramidPattern(n);
        
        // Pattern 10: Half left sided diamond pattern
        //leftHalfPyramidPattern(n);
        //leftHalfInvertedPyramidPattern(n);

        // Pattern 11: 
        //binaryNumberSimpleLeftSidedTrianglePattern(n);

        // Pattern 12:
        //numberedCrownPattern(n);

        // Pattern 13:
        //increasingNumberTrianglePattern(n);

        // Pattern 14:
        //increasingLetterTrianglePattern(n);

        // Pattern 15:
        //reverseLetterTrianglePattern(n);

        // Pattern 16:
        // alphaRampPattern(n);

        // Pattern 17:
        // alphaHillPattern(n);

        // Pattern 18:
        //alpahReversedTrianglePattern(n);

        // Pattern 19:
        //symmetricVoidPattern(n);

        // Pattern 20:
        //symmetricButterflyPattern(n);

        // Pattern 21:
        //hollowRectanglePattern(n);

        // Pattern 22:
        // repeatingNumberPattern(n);


    return 0;
}
