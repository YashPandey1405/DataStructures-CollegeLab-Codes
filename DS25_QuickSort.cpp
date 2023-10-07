/*
-> Quick Sort Is Based On The Principle Of Divide & Conquer Where We Divide The Bigger Problem Into Smaller Problem , Solve The Problem For
   Smaller Tasks and Then Cummulate The Solution Of Smaller Task To Obtain Solution Of Bigger Problem.......
-> Average Case Time Complexity Of Quick Sort Is O(nLogn).......
-> Worst Case Time Complexity Of Quick Sort Is O(n^2).......
-> Space Complexity Of Quick Sort Is O(1).......
-> Theory --> https://youtu.be/QN9hnmAgmOc?si=7o_Y4ErOqJdjzN1P
-> Code --> https://youtu.be/sNaHN4tZmRk?si=s9908_XMu7CTALNK
* Note --> To Get Quick Sort In Descending Order , Just Change Signs Shown Below To Get Descending Order Sorting......
        ~> Change Signs Of From "<=" --> ">=" In (1)[Line-39 Of Code] ......
        ~> Change Signs Of From "<" --> ">" In (1)[Line-55 Of Code] ......
        ~> Change Signs Of From ">" --> "<" In (1)[Line-58 Of Code] ......
*/

#include<iostream>
using namespace std;

int Partition(int*,int,int);    //Function Prototype Of Function Partition()......
void PrintArray(int*,int);    //Function Prototype Of Function PrintArray()......

void QuickSort(int arr[],int Start,int End){  //O(nLogn).......

    if(Start>=End){  //Base Case Of Quick Sort....
        return;
    }
    //Call To Partition Function To Get The Index Of Pivot......
    int Pivot=Partition(arr,Start,End);
    
    //Recursive Calls For The Array To Sort Left & Right Part In Array......
    QuickSort(arr,Start,Pivot-1);  //Recursive Call For QuickSort() For Left-Part --> [Start,Pivot-1]........
    QuickSort(arr,Pivot+1,End);  //Recursive Call For QuickSort() For Right-Part -->[Pivot+1,End]........

}

int Partition(int arr[],int Start,int End){
    int Pivot=arr[Start];
    int Count=0;
    for(int i = (Start+1) ; i <= End ; i++){
        if(arr[i] <= Pivot){  //--> (1).....
            Count++;
        }
    } 

    // Get The Correct Pivot Index & Move Pivot To The Right Place.....
    int PivotIndex=Start+Count;
    int Temp=arr[PivotIndex];  //Swap Of arr[PivotIndex] & arr[End] i.e. Pivot.......
    arr[PivotIndex]=arr[Start];
    arr[Start]=Temp;

    //Loop To Make The LeftPart <= Pivot <= RightPart......
    int ptr1=Start , ptr2=End;
    while(ptr1<PivotIndex && ptr2>PivotIndex){
        
        //Loop To Reach The Value > Pivot In The Left Part --> [Start,PivotIndex-1].....
        while(arr[ptr1]<Pivot){    ptr1++;    }  //--> (2).....

        //Loop To Reach The Value > Pivot In The Right Part --> [PivotIndex+1,End].....
        while(arr[ptr2]>Pivot){    ptr2--;    }  //--> (3).....

        // Statement When LeftPart-Value > Pivot && RightPart-Value < Pivot....... 
        if(ptr1<PivotIndex && ptr2>PivotIndex){
            int Temp=arr[ptr1];  //Swap Of arr[PivotIndex] & arr[End] i.e. Pivot.......
            arr[ptr1]=arr[ptr2];
            arr[ptr2]=Temp;
            ptr1++;  ptr2--;
        }
    }

    return PivotIndex;
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
    int arr[8]={3,2,6,1,5,7,8,4};
    PrintArray(arr,8);
    QuickSort(arr,0,7);
    cout<<"After QuickSort() Function , ";
    PrintArray(arr,8);
    return 0;
}
