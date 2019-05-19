#include <iostream> 
using namespace std; 

int minSwap(int *arr, int n, int k) { 
      
    int result = 0;
    int right = n - 1;
    for (int i = 0; i < n; i++) {
        if(arr[i] > k){
            while(i < right){
                if(arr[right--] <= k){
                    result++;
                    break;
                }
            }
            if(i >= right){
                break;
            }
        }    
    }
    return result;
} 

int main() { 
      
    int arr[] = {2, 1, 5, 6, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    cout << minSwap(arr, n, k) << "\n"; 
      
    int arr1[] = {2, 7, 5, 9, 8, 7, 4}; 
    n = sizeof(arr1) / sizeof(arr1[0]); 
    k = 5; 
    cout << minSwap(arr1, n, k); 
    return 0; 
} 