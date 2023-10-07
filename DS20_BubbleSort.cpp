// In Bubble Sort , We Move The Largest Element To End Of The Array In Each Iteration 
// We Do This By Swapping Of Largest No With Adjacent Elements......
// Time Complexity Of Bubble Sort Is O(n^2)......

#include<iostream>
using namespace std;

void PrintArray(int*,int); //Function Prototype Of Function PrintArray()......

//Function To Perform Bubble Sort In Ascending Order.......
void BubbleSort_AscendingOrder(int arr[],int n){  //O(n^2)......
    // int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j<(n-1-i) ; j++){
            if(arr[j]>arr[j+1]){  //(1)......
                //Swap arr[j] & arr[j+1].....
                int Temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=Temp;
            }
        }
    }
    cout<<"After Bubble Sort In Ascending Order --> ";
    PrintArray(arr,n);
}

//Change The Sign From '>' --> '<' In (1) To Get Sorting In Descending Order, Rest Code Will Be Same.....
//Function To Perform Bubble Sort In Descending Order.......
void BubbleSort_DescendingOrder(int arr[],int n){  //O(n^2)......
    // int n=sizeof(arr)/sizeof(int);
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j<(n-1-i) ; j++){
            if(arr[j]<arr[j+1]){
                //Swap arr[j] & arr[j+1].....
                int Temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=Temp;
            }
        }
    }
    cout<<"After Bubble Sort In Descending Order --> ";
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
    BubbleSort_AscendingOrder(arr,8);
    BubbleSort_DescendingOrder(arr,8);
    return 0;
}