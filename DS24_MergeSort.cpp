/*
-> Merge Sort Is Based On The Principle Of Divide & Conquer Where We Divide The Bigger Problem Into Smaller Problem , Solve The Problem For
   Smaller Tasks and Then Cummulate The Solution Of Smaller Task To Obtain Solution Of Bigger Problem.......
-> Time Complexity Of Merge Sort Is O(nLogn).......
-> Space Complexity Of Merge Sort Is O(n).......
-> Theory --> https://youtu.be/jlHkDBEumP0?si=yV7aOqQJ12-AJZzz 
-> Code --> https://youtu.be/cdHEpbBVjRM?si=KgyUpkmIln2tUajY
* Note --> To Get Merge Sort In Descending Order , Just Change Sign From "<=" --> ">=" In (1)[Line-42 Of Code] To Get Descending Order Sorting......
*/

#include<iostream>
using namespace std;

void Merge(int*,int,int,int); //Function Prototype Of Function Merge()......
void PrintArray(int*,int);    //Function Prototype Of Function PrintArray()......

void MergeSort(int arr[],int Start,int End){  // O(nLogn)......

    //Base Case Of Merge Sort....
    if(Start>=End){    
        return;
    }

    int Mid=Start+(End-Start)/2; //Calculation Of Mid-Index Of The Array.....

    //Recursive Calls For The Array To Create Left & Right Part In Array......
    MergeSort(arr,Start,Mid);  //Recursive Call For MergeSort() For Left-Part --> [Start,Mid]........
    MergeSort(arr,Mid+1,End);  //Recursive Call For MergeSort() For Right-Part -->[Mid+1,End]........

    // Merge Left-Part & Right-Part Of Array.....
    Merge(arr,Start,Mid,End);
}

void Merge(int arr[],int Start,int Mid,int End){
    int Temp[End-Start+1]={0};  //Created A Temp Array For Merging Of The [Start,Mid] & [Mid+1,End]......
    int ptr1=Start;  // Pointer For The Left-Part --> [Start,Mid] , Begins From Value-(Start)....... 
    int ptr2=Mid+1;  // Pointer For The Left-Part --> [Mid+1,End] , Begins From Value-(Mid+1)....... 
    int ptr=0;       // Pointer Insert The Values In 'Temp' Array....... 

    //Loop To Add The Elements Of 2-Parts In Sorted Order In The 'Temp' Array.......
    while(ptr1<=Mid && ptr2<=End){
        if(arr[ptr1] <= arr[ptr2]){  // -->(1).....
            // Temp[ptr++] = arr[ptr1++];
            Temp[ptr]=arr[ptr1];
            ptr1++;
        }
        else {
            // Temp[ptr++] = arr[ptr2++];
            Temp[ptr]=arr[ptr2];
            ptr2++;
        }
        ptr++;
    }

    while(ptr1<=Mid){  //Loop To Remaining Element Of Left-Part --> [Start,Mid].......
        // Temp[ptr++] = arr[ptr1++];
        Temp[ptr]=arr[ptr1];
        ptr1++; ptr++;
    }

    while(ptr2<=End){  //Loop To Remaining Element Of Right-Part --> [Mid+1,End].......
        // Temp[ptr++] = arr[ptr1++];
        Temp[ptr]=arr[ptr2];
        ptr2++; ptr++;
    }

    // Loop To Copy The Value Of 'Temp' Array To Array-'arr'.......
    int idx=Start;
    for(int i =0 ; i < (End-Start+1) ; i++ ){
        arr[idx]=Temp[i];
        idx++;
    }
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
    MergeSort(arr,0,7);
    cout<<"After Merge Sort , ";
    PrintArray(arr,8);
    return 0;
}
