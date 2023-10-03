#include <iostream>
using namespace std; 

class Queues_Arrays{
    private :
	    int * arr;
        int Capacity;
        int Front,Rear;
	public:
	    Queues_Arrays(int c){
            this->Capacity=c;
	    	this->arr=new int[Capacity];
	    	this->Front=0;
	    	this->Rear=-1;
	    }
	    void enqueue(int x){
	    	if (this->Rear == this->Capacity-1){
	    		cout<<"QUEUE OVERFLOW ::: QUEUE IS FULL"<<endl;
	    		return;
	    	}
	    	this->arr[++(this->Rear)]=x;
	    }
		int dequeue(){
			if (this->Front == (-1) || this->Front>this->Rear){
	    		cout<<"QUEUE UNDERFLOW ::: QUEUE IS EMPTY"<<endl;
				return -1;
			}
            int temp=this->arr[this->Front++];
			// this->Front++;
            return temp;
		}
		int FrontPeek(){
			if (this->Front == (-1) || this->Front>this->Rear){
	    		cout<<"QUEUE UNDERFLOW ::: QUEUE IS EMPTY"<<endl;
				return -1;
			}
			return this->arr[this->Front];
		}
		int LastPeek(){
			if (this->Front == (-1) || this->Front>this->Rear){
	    		cout<<"QUEUE UNDERFLOW ::: QUEUE IS EMPTY"<<endl;
				return -1;
			}
			return this->arr[this->Rear];
		}
		void SortQueue(){
            int n=(this->Rear-this->Front+1);
            for(int i=0;i<(n-1);i++){  //Selection Sort
                for(int j=(i+1);j<n;j++){
                    if(this->arr[j]<this->arr[i]){  
                        int temp=this->arr[i];
                        this->arr[i]=this->arr[j];
                        this->arr[j]=temp;                   
                    }
                }
            }
            cout<<"After SortQueue() Function , ";
        }
        void ReverseQueue(){
            int n=(this->Rear-this->Front+1);
            for(int i=0;i<(n/2);i++){  //Reverse A Queue....
                        int temp=this->arr[i];
                        this->arr[i]=this->arr[n-i-1];
                        this->arr[n-i-1]=temp;                   
            }
            cout<<"After ReverseQueue() Function , ";
        }
        int size(){     return (this->Rear-this->Front+1);  }
		bool isEmpty (){
            return (this->Front == (-1) || this->Front>this->Rear) ? true : false;
		}
        bool isFull(){
            return (this->Front==(-1) && this->Rear==(this->Capacity-1));
        }
        void PrintQueue(){
            cout<<"THE QUEUE IS ::: Front--> ";
            for(int i=this->Front;i<=this->Rear;i++){
                cout<<this->arr[i]<<" ";
            }
            cout<<"<--Rear"<<endl;
        }
};
int main(){
	cout<<endl;
	Queues_Arrays q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
    q.PrintQueue();
    q.dequeue();
    q.PrintQueue();
	cout<<endl;
    cout<<"THE FRONT ELEMENT OF QUEUE IS ::: "<<q.FrontPeek()<<endl;
    cout<<"THE REAR ELEMENT OF QUEUE IS ::: "<<q.LastPeek()<<endl;
    cout<<"THE SIZE OF THE QUEUE IS ::: "<<q.size()<<endl;
    cout<<"THE QUEUE IS EMPTY ::: "<<q.isEmpty()<<endl;
    cout<<"THE QUEUE IS FULL ::: "<<q.isFull()<<endl;
	cout<<endl;
	q.SortQueue();
    q.PrintQueue();
	q.ReverseQueue();
    q.PrintQueue();
	cout<<endl;
	return 0;
}