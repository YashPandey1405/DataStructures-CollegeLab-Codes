#include<iostream>
using namespace std;

class CircularQueues{
    private:
        int* arr;
        int size , Capacity;
        int Rear=-1;
        int Front=-1;
    public:
        CircularQueues(int n){  //Constructor Of Class CircularQueues()....
            size=Capacity=n;
            arr=new int[n]; //Initialized The Array For Circular Queues.....
            Rear=-1;
            Front=-1;
        }

        //Time Complexity Of This enqueue() Function Is O(1)......
        void enqueue(int data){  //Function To Add Element At End Of Queue......
            if(IsFull()){
                cout<<"THE CIRCULAR QUEUE IS FULL , ADDITION OF ELEMENTS IS NOT POSSIBLE"<<endl;
                return;
            }
            if(Front == (-1)){  Front=0;  } //When We Are Adding First Element In The Circular Queue.....
            Rear = (Rear+1) % size;  //FOCUS....
            arr[Rear]=data;
        }

        //Time Complexity Of This dequeue() Function Is O(1)......
         int dequeue(){ //Function To Remove Element From Start Of Queue......
            if(IsEmpty()){
                cout<<"THE QUEUE IS EMPTY , REMOVAL OF ELEMENTS IS NOT POSSIBLE"<<endl;  
                return -1;
            }
            int result=arr[Front];
            if(Rear==Front){  Rear=Front=-1;  }  //Statement When We Are Removing The Last Element Of The Queue....
            else{  Front=(Front+1)%size;  }  
            return result;
        }

        //Time Complexity Of This peek() Function Is O(1)......
        int peek(){ //Function To Get Element From Start Of Queue......
            if(IsEmpty()){
                cout<<"THE QUEUE IS EMPTY , REMOVAL OF ELEMENTS IS NOT POSSIBLE"<<endl;  
                return -1;
            }
            return arr[Front];
        }

        //Time Complexity Of This IsEmpty() Function Is O(1)......
        bool IsEmpty(){ //Function To Check Whether Queue Is Empty Or Not....
            if(Rear==-1 && Front==-1){  return true;  }
            else{  return false;  }
        }

        //Time Complexity Of This IsFull() Function Is O(1)......
        bool IsFull(){ //Function To Check Whether Queue Is Empty Or Not....
            if( (Rear+1) % size == Front ){  return true;  }
            else{  return false;  }
        }

        //Time Complexity Of This PrintCircularQueue() Function Is O(n)......
        void PrintCircularQueue(){ //Function To Print Element Of Queue......
            cout<<"THE QUEUE IS ::: {";
            for(int i=Front;i<=Rear;i++){
                if(i==(Rear)){
                    cout<<arr[i]<<"}"<<endl;
                    break;
                }
                cout<<arr[i]<<",";
            }
        }
};

int main(){
    /*Implementaion Of Circular Queue Using Array......*/
    CircularQueues cq(10);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.PrintCircularQueue();
    cq.dequeue();
    cq.PrintCircularQueue();
    cout<<"THE PEEK OF QUEUE IS ::: "<<cq.peek()<<endl;  
    cout<<"THE CIRCULAR QUEUE IS EMPTY ::: "<<cq.IsEmpty()<<endl;  
    cout<<"THE CIRCULAR QUEUE IS FULL ::: "<<cq.IsFull()<<endl;  
    return 0;
}