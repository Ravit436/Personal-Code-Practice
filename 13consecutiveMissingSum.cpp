#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, oldcount = 0;
    cin>>t;
    while(t--){

    unsigned long long int i, j, low, high, end = 100000, count;
    unsigned long long int exists[end] = {};
    cin>>low>>high;
    unsigned long long int num = high;
    for(i = low; i <= high; i++){
        exists[i] = 1;
    }
    while(num < end){

        for(i = low; i <= high; i++){
            if(num + i > end){
                break;
            }
 
            for(j = low; j <= num; j++){
                if(i + j > end){
                    break;
                }
                if(exists[j] != 1){
                    continue;
                }
                // cout<<"exists "<<j+i<<endl;
                exists[j + i] = 1;
            }
            num = i + j;
        }
        

        // cout<<num<<" -- "<<" "<< low<<endl;
        if(num + low >= end){
            break;
        }
    }
    count = 0;
    for(i = low; i <= end - 20; i++){
       if(exists[i] == 0){
           count++;
           cout<<i<<" "<<count<<endl;
       }
    }
    // cout<<exists[6]<<endl;
    cout<<count<<" -- "<<count+low-1<<"  "<<(count - oldcount)<<endl;
    oldcount = count;
    }
}