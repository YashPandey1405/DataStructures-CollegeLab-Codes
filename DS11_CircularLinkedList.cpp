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

static int size_CLL;

class CircularLL{
    private:
    public:
        Node* Head;
        Node* Tail;
        CircularLL(){
            this->Head=NULL;
            this->Tail=NULL;
        }
        void AddStart(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                return;
            }
            NewNode->next=Head;
            Head=NewNode;
            Tail->next=Head;
            size_CLL++;
        }

        void AddLast(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                return;
            }
            Tail->next=NewNode;
            Tail=NewNode;
            Tail->next=Head;
            size_CLL++;
        }

        Node* GetMiddle(){
            Node* Slow=Head->next;
            Node* Fast=Head->next->next;
            while(Fast!=Tail && Fast->next!=Tail){
                Slow=Slow->next;
                Fast=Fast->next->next;
            }
            return Slow;
        }

        void AddMiddle(int data){
            Node* NewNode=new Node(data);
            if(Head==NULL){
                Head=Tail=NewNode;
                return;
            }

            Node* Slow=GetMiddle();
            NewNode->next=Slow->next;
            Slow->next=NewNode;
        }

        int RemoveMiddle(){
            if(Head==NULL){
                cout<<"CIRCULAR LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return (-1);
            }
            Node* MidNode=GetMiddle();
            Node* Prev=Head;
            while(Prev->next!=MidNode){
                Prev=Prev->next;
            }
            int Value=MidNode->data;
            Prev->next=MidNode->next;
            MidNode->next=NULL;
            free(MidNode);
            return Value;
        }

        int DeleteStart(){
            if(Head==NULL){
                cout<<"CIRCULAR LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return(-1);
            }
            Node*temp=Head;
            int Value=temp->data;
            Head=Head->next;
            Tail->next=Head;
            temp->next=NULL;
            free(temp);
            return Value;
        }

        int Delete_End(){
            if(Head==NULL){
                cout<<"CIRCULAR LINKED LIST IS EMPTY , DELETION NOT POSSIBLE"<<endl;
                return(-1);
            }
            Node*temp=Head;
            while(temp->next!=Tail){
                temp=temp->next;
            }
            Node* ptr=temp->next;
            int Value=ptr->data;
            temp->next=Head;
            Tail=temp;
            Tail->next=Head;
            ptr->next=NULL;
            free(ptr);
            return Value;
        }

        void Reverse_CLL(){
            if(Head==NULL){
                cout<<"CIRCULAR LINKED LIST IS EMPTY , REVERSAL NOT POSSIBLE"<<endl;
            }
            Node* Prev=Tail;
            Node* Temp=Head;
            Node* Ahead=NULL;
            while(Temp!=Tail){
                Ahead=Temp->next;
                Temp->next=Prev;
                Prev=Temp;
                Temp=Ahead;
            }
            Temp->next=Prev;
            Tail=Head;
            Head=Temp;
        }

        void Print_CLL(){
            cout<<"THE CIRCULAR LINKED LIST IS ::: ";
            Node*temp=Head;
            while(temp!=Tail){
                cout<<temp->data<<" --> ";
                temp=temp->next;
            }
            cout<<temp->data<<endl;
        }
};  

int main(){
    CircularLL cll;
    // cll.AddStart(2);
    // cll.AddStart(1);
    // cll.AddLast(5);
    // cll.AddLast(6);
    // cll.AddMiddle(3);
    // cll.AddMiddle(4);
    // cll.Print_CLL();

    // Node* temp=cll.GetMiddle();
    // cout<<"MIDDLE NODE OF Circular LL IS ::: "<<temp->data<<endl;

    // cll.DeleteStart();
    // cll.Print_CLL();

    // cll.Delete_End();  
    // cll.Print_CLL();

    // cll.RemoveMiddle();
    // cll.Print_CLL();

    // cll.Reverse_CLL();
    // cll.Print_CLL();
    return 0;
}