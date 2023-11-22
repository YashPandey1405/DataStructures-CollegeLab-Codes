#include<iostream>
using namespace std;

void PrintArray(int*,int); //Function Prototype Of Function PrintArray()......

int GetMax(int arr[],int n){
    int Max=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>Max){ Max=arr[i]; }
    }
    return Max;
}

void CountSort(int arr[],int pos,int n){
    int freq[10]={0};
    for(int i=0;i<n;i++){
        freq[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--freq[(arr[i]/pos)%10]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

void RadixSort(int arr[],int n){
    int MaxElement=GetMax(arr,n);
    for(int pos=1 ; (MaxElement/pos)>0 ;pos*=10){
        CountSort(arr,pos,n);
    } 
    cout<<"After Radix Sort(In Ascending Order) --> ";
    PrintArray(arr,n);
}

void PrintArray(int arr[],int n){ //Function To Print Array...
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
    int arr[7]={170,29,45,90,527,2,206};
    PrintArray(arr,7);
    RadixSort(arr,7);
    return 0;
}