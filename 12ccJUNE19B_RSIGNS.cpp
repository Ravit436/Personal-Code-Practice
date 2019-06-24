#include<bits/stdc++.h>
using namespace std;

long long int powerModulus(long long int k) 
{ 
    long long int result = 10, powerBase = 2; 
    long long int mod = 1000000007;
    while (k > 0) 
    {
        if (k % 2 == 1){
            result = (result * powerBase) % mod; 
        }
        k /= 2; 
        powerBase = (powerBase * powerBase) % mod;   
    } 
    return result; 
} 

int main(){
    long long int t, k;
    cin>>t;
    while(t--){
        cin>>k;
        long long int result = powerModulus(--k);
        cout<<result<<endl;
    }
}