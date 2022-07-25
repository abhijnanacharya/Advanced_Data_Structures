//PROBLEM STATEMENT: Count More than n/k Occurrences
//Given an array arr[] of size N and an element k. 
//The task is to find all elements in array that appear more than n/k times.

//Example 1:

// Input:
// N = 8
// arr[] = {3,1,2,2,1,2,3,3}
// k = 4
// Output: 2
// Explanation: In the given array, 3 and
//  2 are the only elements that appears 
// more than n/k times.

//NAIVE: USE 2 Loops to find count of each element and store the count if it is greater than n By K.
//MORE EFFICIENT: Create a hashmap and store the frequencies of the element and increment the counter
//for which the value is greater than n/k times.
//TC:O(2N)= O(N)
//SC:O(N)<HashMap>

//MOST EFFICIENT: Sort the array and in a single pass you can find number of elements
//crossing n/k count. 

// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    // int countOccurrence(int arr[], int n, int k) {
    //     // Your code here
    //     unordered_map<int,int>mp;
    //     int count=0;
    //     int nByk=n/k;
    //     for(int i=0;i<n;i++){
    //         if(mp[arr[i]])
    //             mp[arr[i]]++;
    //         else
    //             mp[arr[i]]=1;
    //     }
    //     for(auto it: mp){
    //         if(it.second>nByk){
    //             count++;
    //         }
    //     }
    //     return count;
    // }
	int countOccurrence(int arr[], int n, int k) {
		int ans=0; 
		sort(arr,arr+n); 
		int nByk=n/k;
		int cnt=1; 
		int curr=arr[0];
		for(int i=1;i<n;){
			if(arr[i]==curr){
				while(arr[i]==curr){ 
					cnt++; 
					i++;
				}
				if(cnt>nByk) ans++;
			}
			else{
				curr=arr[i]; cnt=1; i++;
			}
		}
	return ans;
	}
};


// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurrence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends