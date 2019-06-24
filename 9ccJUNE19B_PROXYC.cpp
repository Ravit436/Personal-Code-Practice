#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string report;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>report;
        int maxAttend = ceil(0.75*n);
        int proxy = 0, present = 0;
        for(int i = 0; i < n; i++){
            if(report[i] == 'P'){
                present++;
            }
        }
        for(int i = 2; i < n - 2; i++){
            if(maxAttend <= proxy + present){
                break;
            }
            cout<<i<<report[i]<<endl;
            if(report[i] == 'A' && ((report[i - 1] == 'P' || report[i - 2] == 'P')
            && (report[i + 1] == 'P' || report[i + 2] == 'P'))){
                proxy++;
            }
        }
        if(maxAttend <= proxy + present){
            cout<<proxy<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}