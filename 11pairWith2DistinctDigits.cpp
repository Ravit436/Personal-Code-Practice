#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 1000000, count = 0;
    for(int  i = 0; i < n; i++){
        int num1 = i, num2 = n - i - 1;
        int hash[10] = {}, distinct = 0;
        if(num1 == 0){
            hash[0] = 1;
            distinct++;
        }
        if(num2 == 0){
            hash[0] = 1;
            distinct++;
        }
        while(num1 > 0){
            int digit = num1 % 10;
            if(hash[digit] == 0){
                hash[digit] = 1;
                distinct++;
            }
            num1 /= 10;
        }
        while(num2 > 0){
            int digit = num2 % 10;
            if(hash[digit] == 0){
                hash[digit] = 1;
                distinct++;
            }
            num2 /= 10;
        }
        if(distinct == 2){
            cout<<i<<" "<<n-i-1<<" "<<++count<<endl;
        }
    }
}