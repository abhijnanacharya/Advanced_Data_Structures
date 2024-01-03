//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int open, int close, vector<string> &ans, string s,int n)
    {
        // base case
        if(open==0 and close ==0)
        {
            ans.push_back(s);
            return;
        }
    
        if(open>0)
        {
            s.push_back('(');
            solve(open-1, close, ans, s,n);
            s.pop_back();
        }
    
        if(close>open)
        {
            s.push_back(')');
            solve(open, close-1, ans, s,n);
            s.pop_back();
        }
        return;
    }
    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        
        vector<string> ans;
        int open=n;
        int close=n;
        string s="";
    
        solve(open, close, ans, s,n);
        
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends