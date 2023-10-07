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

//Function To Evaluate The Height Of The Binary Tree.....
int Height_BinaryTree(Node* Root){
    if(Root==NULL){
        return 0;
    }
    int LeftHeight=Height_BinaryTree(Root->Left);
    int RightHeight=Height_BinaryTree(Root->Right);
    int CurrHeight=(LeftHeight>RightHeight) ? LeftHeight : RightHeight;
    return CurrHeight+1;  //(+1) For Inclusion Of Height Of Root Node.....
}

//Function To Evaluate The Count Of Nodes In The Binary Tree.....
int CountNodes_BinaryTree(Node* Root){
    if(Root==NULL){
        return 0;
    }
    int LeftCount=CountNodes_BinaryTree(Root->Left);
    int RightCount=CountNodes_BinaryTree(Root->Right);
    return (LeftCount+RightCount+1);  //(+1) For Inclusion Of Count Of Root Node.....
}

//Function To Evaluate The Sum Of Nodes In The Binary Tree.....
int SumNodes_BinaryTree(Node* Root){
    if(Root==NULL){
        return 0;
    }
    int LeftCount=SumNodes_BinaryTree(Root->Left);
    int RightCount=SumNodes_BinaryTree(Root->Right);
    int CurrValue=Root->data;
    return (LeftCount+RightCount+CurrValue);  //(+1) For Inclusion Of Count Of Root Node.....
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
    cout<<endl;

    int Height=Height_BinaryTree(NewNode);
    cout<<"THE HEIGHT OF BINARY TREE IS ::: "<<Height<<endl;

    int Count=CountNodes_BinaryTree(NewNode);
    cout<<"THE TOTAL NODES IN THE BINARY TREE IS ::: "<<Count<<endl;

    int Sum=SumNodes_BinaryTree(NewNode);
    cout<<"THE SUM OF NODES IN THE BINARY TREE IS ::: "<<Sum<<endl;
}