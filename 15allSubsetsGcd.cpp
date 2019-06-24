#include <bits/stdc++.h> 
using namespace std; 

void findAllSubsets(vector<int>& A, vector<vector<int> >& res, 
                 vector<int>& subset, int index) { 
    res.push_back(subset); 
    for (int i = index; i < A.size(); i++) {   
        subset.push_back(i); 
        findAllSubsets(A, res, subset, i + 1); 
        subset.pop_back(); 
    } 
  
    return; 
} 
  
vector<vector<int>> getSubsetsList(vector<int>& A) { 
    vector<int> subset; 
    vector<vector<int> > res; 
  
    findAllSubsets(A, res, subset, 0); 
  
    return res; 
} 

int gcd(int a, int b) { 
    if (a == 0) {
        return b;
    } 
    return gcd(b % a, a); 
} 

int findGCD(vector<int> arr) { 
    int result = arr[0]; 
    for (int i = 1; i < arr.size(); i++) {
        result = gcd(arr[i], result); 
    }
    return result; 
} 
  
int main() { 
    int t;
    cin>>t;
    while(t--){
        int n, num;
        cin>>n;
        vector<int> array; 
        for(int i = 0; i < n; i++){
            cin>>num;
            array.push_back(num);
        }
        vector<vector<int> > res = getSubsetsList(array); 

        int count = 0;
        for (int i = 0; i < res.size(); i++) { 
            if(res[i].size() == 0 || res[i].size() == array.size()){
                continue;
            }
            cout<<count++<<" -> ";
            for (int j = 0; j < res[i].size(); j++) 
                cout << res[i][j] << " "; 
            cout << endl; 
        } 

        vector<int> gcdSum;
        for (int i = 0; i < res.size(); i++) { 
            if(res[i].size() == 0 || res[i].size() == array.size()){
                continue;
            }
            vector<int> A, B;
            int j = 0, start = 0;
            // cout<<"oolllgrre"<<res[i].size()<<endl;
            for (; j < res[i].size(); j++){
                int end = res[i][j];
                for(int k = start; k < end; k++){
                    // cout<<"o"<<k<<endl;
                    B.push_back(array[k]);
                }
                // cout<<"ooollll"<<start<<endl;
                A.push_back(array[end]);
                start = end + 1;
            }
            for(int l = start; l < array.size(); l++){
                // cout<<"ooo"<<l<<endl;
                B.push_back(array[l]);
            }
            // cout<<findGCD(A)<<" - "<<findGCD(B)<<endl;
            gcdSum.push_back(findGCD(A) + findGCD(B));
        }  
        
        int maxGcd = 0, index = 0;
        for (int i = 0; i < gcdSum.size(); i++) { 
            if(gcdSum[i] > maxGcd){
                maxGcd = gcdSum[i];
                index = i;
            }
        }
        cout<<maxGcd<<" "<<index<<endl;
    }
} 