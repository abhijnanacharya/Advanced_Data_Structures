//PROBLEM STATEMENT: Smallest Positive missing number 
//Given an array arr[] of size N, 
//find the smallest positive number missing from the array.

// Example 1:
// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing
// number is 6.
 
// Example 2:
// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//NAIVE: You can use two loops to find out which positive integer is missing. TC:O(N^2)
//Better: Create a hashMap of size N(Maximum capacity). Traverse the array and mark the visited ones.
//Now traverse the array to find the missing element.
//BEST: USE THE PRINCIPLE OF CYCLIC SORT. Imagine you have designated chairs for n students
//now if you allocate the respective student to their respective chairs then you can easily find th missing in one scan.
//TC:O(N)
//SC:O(1)
class Solution
{
public:
    // Function to find missing integer in array
    // arr: input array
    // n: size of array
  int findMissing(int arr[], int n){

  	// Your code here
    int i = 0;
    while (i < n){
      if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]){
        swap(arr[i], arr[arr[i] - 1]);
      }
      else{
      	    i++;
          }
    }

    for (int i = 0; i < n; i++){
      if (i + 1 != arr[i]){
        return i + 1;
      }
    }
    return n + 1;
  }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.findMissing(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends