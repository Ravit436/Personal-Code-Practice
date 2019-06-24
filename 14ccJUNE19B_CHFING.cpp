#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int t;
    cin>>t;
    while(t--){
        unsigned long long int n, k, maxSumNum, nextNum, repeat;
        unsigned long long int missing = 0, mod = 1000000007, miss = 0, inv2 = 500000004, isTrue = 1;
        cin>>n>>k;
        repeat = (n - 1);
        if(k <= n){
            missing = (k - 1) % mod;
            missing = missing % mod;
            cout<<missing<<endl;
            continue;
        }
        maxSumNum = (k - n) / repeat;
        if((k - n) % repeat != 0){
            // cout<<"here"<<endl;
            maxSumNum++;
        }
        maxSumNum--;
        if(maxSumNum > 0){
            // miss = ((maxSumNum) * (maxSumNum + 1)) / 2;
            missing = ((maxSumNum % mod) * ((maxSumNum + 1) % mod)) % mod;
            missing = (missing * inv2) % mod;
            // cout<<missing<<" "<<miss<<" "<<miss%mod<<endl;  
            // miss = miss * ((n -1));
            missing = (missing * ((n - 1) % mod)) % mod;
            // cout<<missing<<" "<<maxSumNum<<endl;
        }
        nextNum = n + (n - 1) * maxSumNum;
        missing = missing % mod;
        if(maxSumNum >= 0 && k - nextNum > 0){
            // miss += ((maxSumNum + 1)) * ((k - nextNum));
            missing = (missing + (((maxSumNum + 1) % mod) * ((k - nextNum) % mod)) % mod) % mod;
                        // cout<<missing<<" "<<maxSumNum<<endl;
        }
        missing += (k - 1) % mod;
        missing = missing % mod;
        cout<<missing<<endl;
    }
}

// 2 3
// 0 -- 1  0
// 3 4
// 1 -- 3  1
// 4 5
// 3 -- 6  2
// 5 6
// 6 -- 10  3
// 6 7
// 10 -- 15  4
// 7 8
// 15 -- 21  5
// 8 9
// 21 -- 28  6
// 9 10
// 28 -- 36  7
// 10 11
// 36 -- 45  8
// 11 12
// 45 -- 55  9
// 12 13
// 55 -- 66  10

// 2 4
// 0 -- 1  18446744073709551561
// 2 4
// 0 -- 1  0
// 3 5
// 0 -- 2  0
// 4 6
// 1 -- 4  1
// 5 7
// 2 -- 6  1
// 6 8
// 4 -- 9  2
// 7 9
// 6 -- 12  2
// 8 10
// 9 -- 16  3
// 9 11
// 12 -- 20  3
// 10 12
// 16 -- 25  4
// 11 13
// 20 -- 30  4
// 12 14
// 25 -- 36  5
// 13 15
// 30 -- 42  5
// 14 16
// 36 -- 49  6
// 15 17
// 42 -- 56  6
// 16 18
// 49 -- 64  7



// 2 5
// 0 -- 1  18446744073709551567
// 3 6
// 0 -- 2  0
// 4 7
// 0 -- 3  0
// 5 8
// 1 -- 5  1
// 6 9
// 2 -- 7  1
// 7 10
// 3 -- 9  1
// 8 11
// 5 -- 12  2
// 9 12
// 7 -- 15  2
// 10 13
// 9 -- 18  2
// 11 14
// 12 -- 22  3
// 12 15
// 15 -- 26  3
// 13 16
// 18 -- 30  3
// 14 17
// 22 -- 35  4



// 15 17
// 42 -- 56  20
// 14 17
// 22 -- 35  18446744073709551596
// 14 17
// 22 -- 35  0
// 15 18
// 26 -- 40  4