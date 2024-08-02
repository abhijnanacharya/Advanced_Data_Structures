/*
	FIBONACCI + MODULAR ARITHMETIC+ MODULO INVERSE USING FERMATS LITTLE THEOREM

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;


int fact[100005];
int power(int base, int n){
    int ans=1;
    while(n){
        if(n%2){
            n=n-1;
            ans=(ans*base)%MOD;
        }else{
            n=n/2;
            base=(base*base)%MOD;
        }
    }
    return ans;
}
void precomputeFact(){
    fact[0]=1;
    fact[1]=1;
    
    for(int i=2;i<100005;i++){
        fact[i]=(i%MOD * fact[i-1]%MOD)%MOD;
    }
}
int nCr(int n, int r){
     
		return  (fact[n]%MOD*(power(fact[r],MOD-2)%MOD * power(fact[n-r],MOD-2)%MOD)%MOD)%MOD;
}




signed main()
{
    int T;
    cin>>T;
    precomputeFact();
    while(T--){
        int n,r;
        cin>>n>>r;
        cout<<nCr(n,r)<<endl;
    }

    return 0;
}