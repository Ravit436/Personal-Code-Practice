#include<bits/stdc++.h>
using namespace std;

int main(){
    int y;
    cin>>y;
    while(y--){
        unsigned long long int t;
        cin>>t;
        t++;
        unsigned long long int ll = ((t - 1) / 10) * 100, hl = (((t - 1) / 10) + 1) * 100;
        unsigned long long int count = t - (t % 10);
        if(t % 10 == 0){
            count = t - 10;
        }
        for(unsigned long long int i = ll; i < hl; i++){
            unsigned long long int sum = 0;
            unsigned long long int num = i;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            if(sum % 10 == 0){
                count++;
                if(count == t){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}