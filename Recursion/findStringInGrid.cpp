//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> dirs={{0,1}, {1,0}, {0,-1}, {-1,0} , {-1,1},{1,1},{1,-1}, {-1,-1}};
    void solve(vector<vector<char>>grid, int x , int y, string word){
        int n=grid.size();
        itn m=grid[0].size();
        //Base Case
        if(index==word.length())
            return true;
        
        
        //Rec case
        for(auto dir:dirs){
            if(isValid(x+dir[0], y+dir[y],n,m) and word[i+1]==grid[x+dir[0]][y+dir[0]]){
                solve(grid, x+dir[0], y+dir[y], word)
            }
        }
        
        
    }
    
	void searchWord(vector<vector<char>>grid, string word){
	    // Code here
	                //                  (0,1)
	                //        (-1,1)             (1,1)
	                //
	                //     (-1,0)                   (1,0)
	                //
	                //          (-1,-1)           (1,-1)
	                //                 (0,-1)
	                //
	                
	    
	    solve(grid,0,0,word);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends


