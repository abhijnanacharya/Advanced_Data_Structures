#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>>dp;
Solution(){
   dp = vector<vector<int>>(10001, vector<int>(3, -1));
}

    int solve(vector<vector<int>>costs, int size,int currHouse,int currColor){
      if(currHouse==size)
        return 0;
       
      if(dp[currHouse][currColor]!=-1) return dp[currHouse][currColor];
      int totalCost=INT_MAX;
      for(int i=0;i<3;i++){
        if(i!=currColor){
          totalCost=min(totalCost,costs[currHouse][currColor]+solve(costs,size,currHouse+1,i));
        }
      }
      return dp[currHouse][currColor]=totalCost;
    }
    int minCost(vector<vector<int> >& costs){
    int size=costs.size();
    return (min({solve(costs,size,0,0),solve(costs,size,0,1),solve(costs,size,0,2)}));


    }
};



int main()
{
  vector<vector<int>>costs={{17,2,17},{16,16,5},{15,3,19}};
  Solution s;
  cout << s.minCost(costs) << endl;

  return 0;
}