#include <bits/stdc++.h> 
using namespace std; 

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

        int maxNum = 0, secondMax = 0;
        for (int i = 0; i < array.size(); i++) { 
            if(array[i] > maxNum){
                secondMax = maxNum;
                maxNum = array[i];
            }
            else if(array[i] > secondMax && array[i] != maxNum){
                secondMax = array[i];
            }
        }
        if(secondMax == 0){
            cout<<array[0] + array[1]<<endl;
            continue;
        }

        int gcd1, gcd2;
        vector<int> A, B;
        for (int i = 0; i < array.size(); i++) { 
            if(array[i] != maxNum){
                A.push_back(array[i]);
            }
        }
        gcd1 = maxNum + findGCD(A);

        for (int i = 0; i < array.size(); i++) { 
            if(array[i] != secondMax){
                B.push_back(array[i]);
            }
        }
        gcd2 = secondMax + findGCD(B);
        
        int maxGcd = gcd1;
        if(maxGcd < gcd2){
            maxGcd = gcd2;
        }
        cout<<maxGcd<<endl;
    }
} 