#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n , int m){
	//Base Case: When the pointers on either of the two strings reach to the beginning of the string
	//NO LCS Can be formed in that case so return 0 
	if(n==0 || m==0) return 0;

	//Recursive Case: Eliminate both of the characters from both the strings in each choice
	//and return the max length
	if(s1[n]==s2[m]) return 1+LCS(s1,s2,n-1,m-1);
	else { //if(s1[n]!=s2[m])
		return max(LCS(s1,s2,n-1,m),
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
	cout<<LCS(s1,s2,n,m);
	return 0;


}