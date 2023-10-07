/*
 * Inorder Sucsessor Of A Node Is The Just Greater Value Node For That Target Node....
 * Inorder Sucsessor Of A Node Is LeftMost Node In The Right Sub-Tree Of The Target Node....
 * For A Target Node With 2 Child , We Replace That Node With It's Inorder Sucsessor.....
 */

#include<iostream>
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

//Function To Search Key In The BST.....
bool Search_In_BST(Node* Root,int Key){
    if(Root == NULL){
        return false;
    }

    if(Root->data==Key){
        return true;
    } 
    else if(Root->data > Key){
        return Search_In_BST(Root->Left,Key);
    } 
    else{
        return Search_In_BST(Root->Right,Key);
    }
}

//Function To Get InOrder Traversal Of The BST.....
void InOrder_Traversal(Node* Root){
    if(Root==NULL){
        return;
    }
    InOrder_Traversal(Root->Left);
    cout<<Root->data<<" ";
    InOrder_Traversal(Root->Right);
}

// Inorder Sucsessor Of Node Is LeftMost Node In The Right Sub-Tree Of The Target Node....
Node* Find_InOrder_Sucsessor(Node* Root){
    Node* Temp=Root;
    while(Root->Left != NULL){ //Loop To Reach LeftMost Node In The Right Sub-Tree.....
        Temp=Temp->Left;
    }
    return Temp;
}

//Function To Delete A Node From Given BST......
Node* Delete_In_BST(Node* Root, int Value) {
    if (Root->data > Value) {
        Root->Left = Delete_In_BST(Root->Left, Value);
    } 
    else if (Root->data < Value) {
        Root->Right = Delete_In_BST(Root->Right, Value);
    } 
    else {

        //Case 1--> When The Target Node Is A Leaf Node(Has No Child)......
        if (Root->Left == NULL && Root->Right == NULL) {  
            return NULL;
        }

        //Case 2--> When The Target Node Has One Child......
        else if (Root->Left == NULL) {  //Part Of Case-2.....
            return Root->Right;
        } 
        else if (Root->Right == NULL) {  //Part Of Case-2.....
            return Root->Left;
        }

        //Case 3--> When The Target Node Has Two Child......
        Node* InOrdSucs = Find_InOrder_Sucsessor(Root->Right);
        Root->data = InOrdSucs->data;
        Root->Right = Delete_In_BST(Root->Right, InOrdSucs->data);
    }
    return Root;
}


/*
         4
       /   \
      2     6
     / \   / \
    1   3 5   7
*/

int main(){

    Node* NewNode=new Node(4);
    NewNode->Left=new Node(2);
    NewNode->Right=new Node(6);
    NewNode->Left->Left=new Node(1);
    NewNode->Left->Right=new Node(3);
    NewNode->Right->Left=new Node(5);
    NewNode->Right->Right=new Node(7);

    int Value=5;
    bool Search=Search_In_BST(NewNode,Value);
    cout<<"VALUE "<<Value<<" EXISTS IN GIVEN BST ::: "<<Search<<endl;

    int Target=5;
    Node* Temp=Delete_In_BST(NewNode,Target);
    cout<<"VALUE "<<Target<<" IS DELETED FROM THE BST"<<endl;

    cout<<"THE IN-ORDER TRAVERSAL IS ::: ";
    InOrder_Traversal(NewNode);
    return 0;
}