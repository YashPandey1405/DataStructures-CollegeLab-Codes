// In Insersion Sort , We Move The Element From Unsorted Part To Sorted Part.... 
// In Each Iteration , We Do This By Moving The Element To The Sorted Part In Front Side Of Array......
// Time Complexity Of Insersion Sort Is O(n^2)......

#include<iostream>
using namespace std;

void PrintArray(int*,int); //Function Prototype Of Function PrintArray()......

//Function To Perform Insersion Sort In Ascending Order.......
void InsersionSort_AscendingOrder(int arr[],int n){  //O(n^2)......
    // int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=1 ; i < n ; i++){
        int Curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>Curr){  //-->(1)......
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=Curr;
    }
    cout<<"After Insersion Sort In Ascending Order --> ";
    PrintArray(arr,n);
}

//Change The Sign From '>' --> '<' In (1) To Get Sorting In Descending Order, Rest Code Will Be Same.....
//Function To Perform Insersion Sort In Descending Order.......
void InsersionSort_DescendingOrder(int arr[],int n){  //O(n^2)......
    // int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=1 ; i < n ; i++){
        int Curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]<Curr){  
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=Curr;
    }
    cout<<"After Insersion Sort In Descending Order --> ";
    PrintArray(arr,n);
}

void PrintArray(int arr[],int n){ //Function To Print Array...
    // int n=sizeof(arr)/sizeof(int);
    cout<<"THE SORTED ARRAY IS ::: { ";
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
    int arr[8]={3,2,6,1,5,7,8,4};
    PrintArray(arr,8);
    InsersionSort_AscendingOrder(arr,8);
    InsersionSort_DescendingOrder(arr,8);
    return 0;
}