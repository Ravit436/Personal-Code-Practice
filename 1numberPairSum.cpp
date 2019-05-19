#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> visited;
    int n, sum, num;
    cin>>n>>sum;
    vector<int> inp;
    for(int i = 0; i < n; i++){
        cin>>num;
        inp.push_back(num);
    }
    for(int i = 0; i < n; i++){
        if(visited.find(inp[i]) != visited.end()){
            cout<<"true";
            return 0;
        }
        visited.insert(sum - inp[i]);
    }
    cout<<"false";
}