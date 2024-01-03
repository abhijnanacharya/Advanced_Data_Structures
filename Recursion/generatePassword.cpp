#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:


  void generatePassword(vector<char>& charList, int i, string output, int len) {
    if(i==0){
      cout<<output<<endl;
      return;
    }
    for(int j=0;j<len;j++){
      string appended=output+charList[j];
      generatePassword(charList, i-1,appended,len);
    }
    return;

  }
};


int main() {
  int n,m;
  cin >> n >> m;
  vector<char> arr(n);
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    arr[i] = x; 
  }
  Solution ob;
  ob.generatePassword(arr, m,"",n);

  return 1;
}