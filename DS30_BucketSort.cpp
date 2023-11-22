#include<iostream>
using namespace std;

void PrintArray(float*,int); //Function Prototype Of Function PrintArray()......

void BucketSort(float arr[],float sorted[],int n){  //O(n)......
    for(int i=0;i<n;i++){
        int idx=arr[i]*n;
        sorted[idx]=arr[i];
    }
    cout<<"After Bucket Sort(In Ascending Order) --> ";
    PrintArray(sorted,n);
}

void PrintArray(float arr[],int n){ //Function To Print Array...
    // int n=sizeof(arr)/sizeof(int);
    cout<<"THE ARRAY IS ::: { ";
    for(int i=0;i<n;i++){
        if(i==(n-1)){
            cout<<arr[i]<<" }"<<endl;
        }
        else{
            cout<<arr[i]<<", ";
        }
    }
    cout<<endl;
}

int main(){
    float arr[10]={0.79,0.13,0.64,0.39,0.23,0.89,0.53,0.42,0.06,0.94};
    float sorted[10]={0};
    PrintArray(arr,10);
    BucketSort(arr,sorted,10);
    return 0;
}