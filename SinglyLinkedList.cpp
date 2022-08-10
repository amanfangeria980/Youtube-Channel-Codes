#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

//Insert at Head
void InsertAtHead(Node *&head,int d){
    Node *newNode = new Node(d);
    newNode->next=head;
    head=newNode;
}
//Print the linkedList
void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

// Insert at tail
void InsertAtTail(Node *&tail,int d){
    Node *newNode=new Node(d);
    tail->next=newNode;
    tail=newNode;
}

//Insert at any position

void InsertAtPos(Node *&head,Node *&tail,int d,int pos){
    if(pos==1){
        InsertAtHead(head,d);
        return ;
    }
    int count=1;
    Node *temp=head;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        InsertAtTail(tail,d);
        return ;
    }
    Node *newNode=new Node(d);
    newNode->next=head->next;
    head->next=newNode;
    // newnode ka next /* ko point kara rhe hai to hum head ka next me equal kara denge */
}

// To delete a node
void DeleteAtPos(Node *&head,int pos){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return ;
    }
    else{
        Node *current=head;
        Node *previous=NULL;
        int count=1;
        while(count<pos){
            previous=current;
            current=current->next;
            count++;
        }
        previous->next=current->next;
        delete current;
    }
}

void Size(Node *&head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<"Size is "<<count<<endl;
}

void Search(Node *&head,int key){
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            cout<<"FOUND"<<endl;
            return ;
        }
        temp=temp->next;
    }
    cout<<"NOT FOUND"<<endl;
}

int main(){
    Node *t=new Node(5); 
    Node *head=t;
    Node *tail=t;
    InsertAtHead(head,10);
    // 10 5
    // print(head);
    InsertAtTail(tail,15); //10 5 15
    // print(head);
    // cout<<head->data<<" "<<tail->data<<endl;
    InsertAtPos(head,tail,20,2);
    // print(head);
    //10 20 5 15
    DeleteAtPos(head,2);
    print(head);
    //10 5 15
    Size(head);
    Search(head,50);








    return 0;
}