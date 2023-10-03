#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int CurrData){
            this->data=CurrData;
            this->next=NULL;
        }
};

class Queues_LinkedList{
    private:
        Node* head;
        Node* tail;
        int size;
        int Capacity;
    public:
        Queues_LinkedList(int c){
            this->Capacity=c;
            this->size=0;
            this->head=NULL;
            this->tail=NULL;
        }
        void enqueue(int data){
            if (this->size == this->Capacity){
	    		cout<<"QUEUE OVERFLOW ::: QUEUE IS FULL"<<endl;
	    		return;
	    	}
            Node* NewNode=new Node(data);
            if(this->head==NULL){
                this->head=this->tail=NewNode;
                size++;
                return;
            }
            this->tail->next=NewNode;
            this->tail=NewNode;
            size++;
        }
        int dequeue(){
            if (this->head==NULL){
	    		cout<<"QUEUE UNDERFLOW ::: QUEUE IS EMPTY"<<endl;
	    		return (-1);
	    	}
            Node* temp=this->head;
            int Value=temp->data;
            this->head=this->head->next;
            temp->next=NULL;
            this->size--;
            free(temp);
            return Value;            
        }
        int PeekFront(){
            if (this->head==NULL){
	    		cout<<"QUEUE UNDERFLOW ::: QUEUE IS EMPTY"<<endl;
	    		return (-1);
	    	}
            return this->head->data;
        }
        int PeekLast(){
            if (this->head==NULL){
	    		cout<<"QUEUE UNDERFLOW ::: QUEUE IS EMPTY"<<endl;
	    		return (-1);
	    	}
            return this->tail->data;
        }
        void PrintQueue(){
            cout<<"THE QUEUE IS ::: FRONT--> ";
            Node* temp=head;
            while(temp->next!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data<<" <--REAR"<<endl;
        }
        int Size(){  return this->size;  }
        bool isEmpty(){  return this->head==NULL;  }
        bool isFull(){  return this->size==this->Capacity;  }
};

int main(){
    Queues_LinkedList qll(10);
    qll.enqueue(1);
    qll.enqueue(5);
    qll.enqueue(3);
    qll.enqueue(4);
    qll.enqueue(2);
    qll.enqueue(6);
    qll.PrintQueue();
    qll.dequeue();
    qll.PrintQueue();
    cout<<"THE FRONT OF THE QUEUE IS ::: "<<qll.PeekFront()<<endl;
    cout<<"THE LAST OF THE QUEUE IS ::: "<<qll.PeekLast()<<endl;
    cout<<"QUEUE IS EMPTY ::: "<<qll.isEmpty()<<endl;
    cout<<"QUEUE IS FULL ::: "<<qll.isFull()<<endl;
    cout<<"SIZE OF QUEUE IS ::: "<<qll.Size()<<endl;
    cout<<endl;
    return 0;
}
