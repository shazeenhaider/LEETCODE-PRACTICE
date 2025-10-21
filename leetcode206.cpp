#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node* newnode= new Node(val);
        if(head==NULL){
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    void printLinkedlist(){
        Node* temp=head;
        if(head==NULL){
            cout<<"linked list is empty";
        }
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    Node* Reverselinkedlist(Node* head){//using recursive approach
    if(head==NULL || head->next==NULL){
        return head;
    }
   //recursive call which return node by backtracking
    Node* newnode = Reverselinkedlist(head->next);
    head->next->next=head;//2->next->next=2 means 2 ka next 3 or 3 ka null but chnge to 2
    head->next=NULL;//2->next=NULL
    return newnode;
    }
};
int main(){
    List ll;
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    cout<<"Original linkedlist"<<endl;
    ll.printLinkedlist();
    ll.head=ll.Reverselinkedlist(ll.head);
    cout<<"Reversed linkedlist"<<endl;
    ll.printLinkedlist();
    return 0;
}
