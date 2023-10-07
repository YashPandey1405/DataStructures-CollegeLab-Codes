// In Bubble Sort , We Move The Smallest Element To Start Of The Array 
// In Each Iteration , We Do This By Swapping Of Smallest No With Adjacent Elements......
// Time Complexity Of Selection Sort Is O(n^2)......

#include<iostream>
using namespace std;

void PrintArray(int*,int); //Function Prototype Of Function PrintArray()......

//Function To Perform Selection Sort In Ascending Order.......
void SelectionSort_AscendingOrder(int arr[],int n){  //O(n^2)......
    // int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i < (n-1) ; i++){
        int max=i;
        for(int j=(i+1) ; j < n ; j++){
            //Statement To Get max. Index.....
            if(arr[max] > arr[j]){     max=j;  } // -->(1)....
        }
        //Swap arr[i] & arr[max].....
        int Temp=arr[i];
        arr[i]=arr[max];
        arr[max]=Temp;
    }
    cout<<"After Selection Sort In Ascending Order --> ";
    PrintArray(arr,n);
}

//Change The Sign From '>' --> '<' In (1) To Get Sorting In Descending Order, Rest Code Will Be Same.....
//Function To Perform Selection Sort In Descending Order.......
void SelectionSort_DescendingOrder(int arr[],int n){  //O(n^2)......
    // int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i < (n-1) ; i++){
        int max=i;
        for(int j=(i+1) ; j < n ; j++){
            //Statement To Get Max. Index.....
            if(arr[max] < arr[j]){      max=j;      }
        }
        //Swap arr[i] & arr[max].....
        int Temp=arr[i];
        arr[i]=arr[max];
        arr[max]=Temp;
    }
    cout<<"After Selection Sort In Descending Order --> ";
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
    SelectionSort_AscendingOrder(arr,8);
    SelectionSort_DescendingOrder(arr,8);
    return 0;
}