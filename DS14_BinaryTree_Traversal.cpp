#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* Left;
        Node* Right;
        Node(int CurrData){
            this->data=CurrData;
            this->Left=this->Right=NULL;
        }
};

void PreOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    cout<<Root->data<<" ";
    PreOrder_Traversal(Root->Left);
    PreOrder_Traversal(Root->Right);
}

void InOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    InOrder_Traversal(Root->Left);
    cout<<Root->data<<" ";
    InOrder_Traversal(Root->Right);
}

void PostOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    PostOrder_Traversal(Root->Left);
    PostOrder_Traversal(Root->Right);
    cout<<Root->data<<" ";
}

void LevelOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(Root);
    q.push(NULL);
    while(!q.empty()){
        Node* CurrNode=q.front();
        q.pop();
        if(CurrNode != NULL){
            cout<<CurrNode->data<<" ";
            if(CurrNode->Left != NULL){   q.push(CurrNode->Left);   }
            if(CurrNode->Right != NULL){   q.push(CurrNode->Right);   }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

/*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
*/

int main(){
    Node* NewNode=new Node(1);
    NewNode->Left=new Node(2);
    NewNode->Right=new Node(3);
    NewNode->Left->Left=new Node(4);
    NewNode->Left->Right=new Node(5);
    NewNode->Right->Left=new Node(6);
    NewNode->Right->Right=new Node(7);

    cout<<"THE PRE-ORDER TRAVERSAL IS ::: ";
    PreOrder_Traversal(NewNode);
    cout<<endl;

    cout<<"THE IN-ORDER TRAVERSAL IS ::: ";
    InOrder_Traversal(NewNode);
    cout<<endl;

    cout<<"THE POST-ORDER TRAVERSAL IS ::: ";
    PostOrder_Traversal(NewNode);
    cout<<endl;

    cout<<"THE LEVEL-ORDER TRAVERSAL IS ::: ";
    LevelOrder_Traversal(NewNode);
    cout<<endl;
}