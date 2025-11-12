#include<stdio.h>


int main(){
    int a[]={1,2,3,4,5,3,2,2,3,4,5,1};
    int n = sizeof(a)/sizeof(a[0]);

    int count = 0;

    int frequency[n];

    for (int i = 0; i < n; i++) frequency[i] = 0;

    for(int i =0;i<n;i++){        
        frequency[a[i]]++;
    }

    for(int i =0;i<n;i++){ 
        if(frequency[i])       
       printf("\nThe frequency of %d in the array is: %d ",i,frequency[i]);
    }

    return 0;
}