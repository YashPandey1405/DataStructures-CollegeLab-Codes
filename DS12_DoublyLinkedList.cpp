#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int CurrData){
            this->data=CurrData;
            this->prev=this->next=NULL;
        }
};

static int size_DLL;

class DoublyLL{
    private:
        Node* Head;
        Node* Tail;
    public:
        DoublyLL(){
            this->Head=NULL;
            this->Tail=NULL;
        }

        void AddFront(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                size_DLL++;
                return;
            }
            Head->prev=NewNode;
            NewNode->next=Head;
            Head=NewNode;
            size_DLL++;
        }

        void AddLast(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                size_DLL++;
                return;
            }
            Tail->next=NewNode;
            NewNode->prev=Tail;
            Tail=NewNode;
            size_DLL++;
        }

        int RemoveFirst(){
            if(Head==NULL){
                cout<<"DOUBLY LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* Temp=Head;
            int Value=Temp->data;
            Head=Head->next;
            Head->prev=NULL;
            Temp->next=NULL;
            free(Temp);
            size_DLL--;
            return Value;
        }

        int RemoveLast(){
            if(Head==NULL){
                cout<<"DOUBLY LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* Temp=Tail;
            int Value=Temp->data;
            Tail=Tail->prev;
            Tail->next=NULL;
            Temp->prev=NULL;
            free(Temp);
            size_DLL--;
            return Value;
        }

        Node* GetMiddle(){
            Node* Slow=Head;
            Node* Fast=Head->next;
            while(Fast!=NULL && Fast->next!=NULL){
                Slow=Slow->next;
                Fast=Fast->next->next;
            }
            return Slow;
        }

        void AddMiddle(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                size_DLL++;
                return;
            }

            Node* Slow=GetMiddle();
            NewNode->next=Slow->next;
            Slow->next->prev=NewNode;
            Slow->next=NewNode;
            NewNode->prev=Slow;
            size_DLL++;
        }

        int RemoveMiddle(){
            if(Head==NULL){
                cout<<"DOUBLY LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* MidNode=GetMiddle();
            int Value=MidNode->data;
            Node* Prev=MidNode->prev;
            Prev->next=MidNode->next;
            MidNode->prev=NULL;
            MidNode->next->prev=Prev;
            MidNode->next=NULL;
            free(MidNode);
            size_DLL--;
            return Value;
        }

        void PrintDLL(){
            Node* Temp=Head;
            cout<<"THE Doubly-LinkedList IS ::: ";
            while(Temp->next!=NULL){
                cout<<Temp->data<<" <--> ";
                Temp=Temp->next;
            }
            cout<<Temp->data<<endl;
        }

        void PrintReverse_DLL(){
            Node* Temp=Tail;
            cout<<"THE REVERSED Doubly-LinkedList IS ::: ";
            while(Temp->prev!=NULL){
                cout<<Temp->data<<" <--> ";
                Temp=Temp->prev;
            }
            cout<<Temp->data<<endl;
        }
};

int main(){
        DoublyLL dll;

        // dll.AddFront(3);
        // dll.AddFront(2);
        // dll.AddFront(1);
        // dll.AddLast(5);
        // dll.AddLast(6);
        // dll.AddLast(7);
        // dll.PrintDLL();
        // cout<<"THE SIZE OF Doubly-LinkedList IS ::: "<<size_DLL<<endl;

        // dll.AddMiddle(4);
        // dll.PrintDLL();
        // cout<<"THE SIZE OF Doubly-LinkedList IS ::: "<<size_DLL<<endl;
        
        // Node* temp=dll.GetMiddle();
        // cout<<"MIDDLE NODE OF Doubly-LinkedList IS ::: "<<temp->data<<endl;

        // dll.RemoveFirst();
        // dll.PrintDLL();
        // cout<<"THE SIZE OF Doubly-LinkedList IS ::: "<<size_DLL<<endl;

        // dll.RemoveLast();
        // dll.PrintDLL();
        // cout<<"THE SIZE OF Doubly-LinkedList IS ::: "<<size_DLL<<endl;

        // dll.RemoveMiddle();
        // dll.PrintDLL();
        // cout<<"THE SIZE OF Doubly-LinkedList IS ::: "<<size_DLL<<endl;


        // dll.PrintReverse_DLL();
    return 0;
}