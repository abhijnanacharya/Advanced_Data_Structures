//PROBLEM:Given a sorted array arr[] of size N without duplicates, and given a value x. 
//Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
//Find the index of K(0-based indexing).
//Example 1:
// Input:
// N = 7, x = 5 
// arr[] = {1,2,8,10,11,12,19}
// Output: 1
// Explanation: Largest Number less than 5 is
// 2 (i.e K = 2), whose index is 1(0-based 
// indexing).
//Your Task:
//The task is to complete the function findFloor() which 
//returns an integer denoting the index value of K or return -1 if there isn't any such number.
// Expected TC:O(log N)
//Expected SC:O(1)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    //The intuition is simple, you are provided with a sorted array,
    //now you can utilize BS to find the search element. If you find
    //it then very good and you can return the element i.e mid,
    //otherwise you check if mid element is greater than search element,
    //in that case set high to mid-1,
    //else set low to mid-1 and store the ans as mid element can be a valid answer.
    int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
        int ans=INT_MAX;
        int low=0; 
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]>x)
                high=mid-1;
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};


// { Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}  // } Driver Code Ends