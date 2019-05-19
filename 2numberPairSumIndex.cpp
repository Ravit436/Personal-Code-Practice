#include<bits/stdc++.h>
using namespace std;

vector<int> findPairSumIndex(vector<int> inp, int sum){
    vector<int> result; 
    unordered_map<int, int> visited;
    for(int i = 0; i < inp.size(); i++){
        if(visited.find(inp[i]) != visited.end()){
            result.push_back(visited.at(inp[i]));
            result.push_back(i);
            break;
        }
        visited[sum - inp[i]] = i;
    }
    return result;
}

int main(){
    int n, sum, num;
    cin>>n>>sum;
    vector<int> inp;
    for(int i = 0; i < n; i++){
        cin>>num;
        inp.push_back(num);
    }
    vector<int> indexes = findPairSumIndex(inp, sum);
    if(indexes.size() == 0){
        cout<<"false";
    }
    else{
        cout<<indexes[0]<<" "<<indexes[1];
    }
}
