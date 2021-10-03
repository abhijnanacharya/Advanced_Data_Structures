#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];//Standard dp table initializaton as a global variable 
int LCS(string s1, string s2, int n , int m){
	//Base Case: When the pointers on either of the two strings reach to the beginning of the string
	//NO LCS Can be formed in that case so return 0 
	if(n==0 || m==0) return 0;
	if(dp[n][m]!=-1) return dp[n][m];//Lookup if the value has been already stored in the dp table
	//If Yes then return the value from the table itself otherwise move to the next steps;

	//Recursive Case: Eliminate both of the characters from both the strings in each choice
	//and return the max length
	if(s1[n]==s2[m]) return dp[n][m]=1+LCS(s1,s2,n-1,m-1); //while returning the value store it in the table 
	else { //if(s1[n]!=s2[m])
		return dp[n][m]=max(LCS(s1,s2,n-1,m),
					LCS(s1,s2,n,m-1));
	}


}
int main(){
	string s1;
	string s2;

	int n,m;
	cin>>s1;
	cin>>s2;

	cin>>n>>m;
	cout<<endl;
	memset(dp,-1,sizeof(dp));
	cout<<LCS(s1,s2,n,m)<<endl;
	return 0;


}