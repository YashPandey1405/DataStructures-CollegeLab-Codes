/*
-> Heap Is A 'Complete Binary Tree' That Comes With A Heap Order Property......
-> A complete binary tree is a binary tree in which every level is completely filled except possibly the last, which is filled from the left.
-> In Max Heap , The Value Of Parent Is Always Greater Than The Child.....
-> In Min Heap , The Value Of Parent Is Always Lesser Than The Child.....
-> We Will Take The Heap Start From The 0th Index Of The Array , Thus : -
    ~> For Node=(i) , Then , LeftChild=[(2*i) + 1] & RightChild=[(2*i) + 2]........ 
    ~> For Node=(i) , Then , The Index Of Parent Of Thus Node=( (i-1) /2 )......
*/ 

#include<iostream>
using namespace std;

class MinHeap{
    public:
        int arr[100];
        int Size;
        MinHeap(void){ //Constructor Of Class Heap.....
            this->Size=(-1);    
        }  
        
        void Insert(int Value){  //O(Logn).....
            Size++;
            int Index=Size;
            arr[Index]=Value;  //Add Value At Last Index Of Array....

            while(Index > 0){  // O(Logn)......
                int ParentIdx=(Index-1)/2;  // As , For Node=i , Parent=(i-1)/2.....

                // Case 1 --> When The Value Of Parent > Value Of Child.......
                if(arr[ParentIdx] > arr[Index]){
                    // Swap The Value Of Child & Parent.......
                    int Temp=arr[Index];
                    arr[Index]=arr[ParentIdx];
                    arr[ParentIdx]=Temp;

                    Index=ParentIdx;
                }
                // When The Value Of Parent < Value Of Child --> Simply Continue.......
                else{    return;     }
            }
        }

        void Heapify(int i) { // O(Logn).....
            int Left = (2 * i) + 1;
            int Right = (2 * i) + 2;
            int MinIDX = i;
            
            // When The Left Child Is Valid & Parent Value > Left Child Value......
            if (Left <= Size && arr[MinIDX] > arr[Left]) {
                MinIDX = Left;
            }
            
            // When The Right Child Is Valid & Parent Value > Right Child Value......
            if (Right <= Size && arr[MinIDX] > arr[Right]) {
                MinIDX = Right;
            }

            if (MinIDX != i) {  //When The Value Of Child Is Lesser Than The Parent Value.....
                int temp = arr[i];  // Swap arr[i] & arr[MinIDX]......
                arr[i] = arr[MinIDX];
                arr[MinIDX]=temp;

                Heapify(MinIDX);
            }
        }

        int Remove() { // O(Logn).....
            int data = arr[0];  // First Element Of Our Array 'arr'.....
            int n = arr[Size];  // Last Element Of Our Array 'arr'.....

            // Step-1 ::: Swap The First & Last Element Of The Array.....
            int temp = arr[0];
            arr[0]=arr[Size];
            arr[Size]=temp;

            // Step-2 ::: Delete The Last Element Of The Array.....
            this->Size--;  // Simply Decrease The Size Of The Array......

            // Step-3 ::: Heapify To Mantain/Fix The MinHeap.....
            Heapify(0);

            return data;
        }

        int Peek_MinHeap(){
            return arr[0];
        }

        void PrintArray(){ //Function To Print Array...
            cout<<"THE ARRAY IS ::: { ";
            for(int i=0 ; i <= Size ; i++){
                if(i==(Size)){
                    cout<<arr[i]<<" }"<<endl;
                }
                else{
                    cout<<arr[i]<<", ";
                }
            }
        }

};

int main(){
    MinHeap heap;
    int arr[8]={3,2,6,1,5,7,8,4};
    int n = sizeof(arr) / sizeof(int);
    for(int i=0 ; i < n ; i++){
        heap.Insert(arr[i]);
    }
    heap.PrintArray();
    cout<<"PEEK OF MIN HEAP IS ::: "<<heap.Peek_MinHeap()<<endl;
    heap.Remove();
    cout<<"After Remove Operation , ";
    heap.PrintArray();
    return 0;
}