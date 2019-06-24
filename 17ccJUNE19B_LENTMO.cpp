#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k, x;
        cin>>n;
        vector<long long int> arr, xorArr;
        long long int sum = 0, num;
        for(int i = 0; i < n; i++){
            cin>>num;
            arr.push_back(num);
        }    
        cin>>k>>x;
        vector<int> index;
        for(int i = 0; i < n; i++){
            xorArr.push_back((arr[i] ^ x) - arr[i]);
            index.push_back(i);
        }
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&xorArr](int i1, int i2) {
            return xorArr[i1] > xorArr[i2];
        });

        vector<long long int> array, xorArray;
        for(int i = 0; i < n; i++){
            xorArray.push_back(xorArr[index[i]]);
            array.push_back(arr[index[i]]);
            sum += arr[i];
            cout<<array[i]<<" "<<xorArray[i]<<" "<<index[i]<<endl;
        }

        int id = 0;
        vector<long long int> prevLoop;
        while(id < n){
            long long int intSum = 0, values = 0;
            int kTimes = 0;
            int max = n;
            if(id + k < n){
                max = id + k; 
            }
            // cout<<max<<" sgd-"<<endl;
            // cout<<xorArray[max - 1]<<endl;
            if(xorArray[max -1] < 0 || ((id + k > n) && prevLoop.size())){
                int pid = 0;
                int i = id;
                for(; i < max; i++){
                    if(xorArray[i] < 0 && prevLoop.size() > 0){
                        // cout<<"prevLoop"<<prevLoop[pid]<<endl;
                        while(prevLoop[pid] < -xorArray[i]){
                            intSum -= prevLoop[pid];
                            // cout<<"prevLoop"<<prevLoop[pid]<<" "<<intSum<<endl;
                            pid++;
                            kTimes++;
                            if(kTimes == k){
                                break;
                            }
                        }
                    }
                    if(kTimes == k){
                        break;
                    }
                    kTimes++;
                    intSum += xorArray[i];
                    if(kTimes == k){
                        break;
                    }
                    // cout<<kTimes<<" "<<intSum<<endl;
                }
                if(i == max && kTimes != k){
                    while(kTimes != k){
                        intSum -= prevLoop[pid];
                        kTimes++;
                    }
                }
                values = 1;
                
            }
            else{
                for(int i = id; i < max; i++){
                    intSum += xorArray[i];
                    kTimes++;
                }
                prevLoop.clear();
                int i = id + k - 1;
                if(i < n){
                    for(; i >= id; i--){
                        prevLoop.push_back(xorArray[i]);
                    }
                }
            }
            cout<<sum<<" -- "<<intSum<<" "<<id<<" "<<kTimes<<endl;
            if(intSum > 0 && kTimes == k){
                sum += intSum;
            }
            if(intSum < 0 || values == 1){
                break;
            }
            id += k;
            // cout<<sum<<" -- "<<intSum<<" "<<id<<"after"<<endl;
        }
        cout<<sum<<endl;
    }
}

player_id,matches,innings_played,no_of_balls,runs_given,wickets_taken,bowling_econ,five_wickets_haul