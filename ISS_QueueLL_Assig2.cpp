#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
}*front=NULL,*rear=NULL;

void addQ(int n){
    node *temp = new node();
    if(temp==NULL) 
        cout<<"Queue is Full"<<endl;
    else{
        cout<<"Added Element "<<n<<" to Queue"<<endl;
        temp->data = n;
        if(!front) 
            front = temp;
        if(rear==NULL) 
            temp->next = NULL;
        else{
            rear->next = temp;
            temp->next = NULL;
        }
        rear = temp;
    }
}

int deleteQ(){
    int n=-1;
    if(front==rear)
        cout<<"Queue is Empty"<<endl;
    else{
        n = front->data;
        front = front->next;
        cout<<"Front Element of Queue = "<<n<<endl;
    }
    return n;
}

bool isFull(){
    node *temp = new node();
    if(temp==NULL)
        return true;
    return false;
}

bool isEmpty(){
    node *temp = new node();
    if(temp!=NULL)
        return true;
    return false;
}


int main(){
    addQ(23);
    addQ(56);
    addQ(40);
    addQ(96);
    deleteQ();
    deleteQ();
    cout<<"Is Empty? = "<<isEmpty()<<endl;
    cout<<"Is Full? = "<<isFull()<<endl;
    return 0;
}