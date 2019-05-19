#include<stdio.h> 
  
int main() 
{ 
    int arr[2]; 
  
    // * as index out of bound 
    // * is not checked in C. 
    
    // printf("%d ", arr[3]); 
    // printf("%d ", arr[-2]); 
  
    // * Array declaration by specifying size and initializing 
    // * elements 
    int arr2[6] = { 10, 20, 30, 40 };
    
    // * Compiler creates an array of size 6, initializes first 
    // * 4 elements as specified by user and rest two elements as 0. 
    // * above is same as  "int arr[] = {10, 20, 30, 40, 0, 0}" 

    int x = 10; 
    int *ptr = &x; // This is fine 
    printf("%d\n", *ptr);

    int arr3[] = {10, 20, 30, 40, 50, 60, 44, 444, 453}; 
    int *ptr1 = arr3; 
    int val1 = sizeof(arr3);
     
    // sizof(int) * (number of element in arr[]) is printed 
    printf("Size of arr[] %d\n", val1); 
    
    // sizeof a pointer is printed which is same for all type  
    // of pointers (char *, void *, etc) 
    printf("Size of ptr %lu", sizeof(ptr1)); 

    // arr[] is not terminated with '\0' 
    // and its size is 5 
    char arr6[] = "geeks";  
        
    printf("%lu", sizeof(arr6)); 
    
    return 0; 
} 